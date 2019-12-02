#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a, b, c, d, r, q, s, t, s_0, s_1, t_0, t_1;


    printf("Este programa se ingresan dos enteros positivos a y b con a > b, y ");
    printf("se desea obtener s y t tales que: \n   (a(*)s)⊕(b(*)t) = f(a, b) \n");

    printf("\n");
    printf("Ingresa el primer número entero, a = +");
    scanf("%d",&a);
    printf("Ingresa el segundo número entero, b = +");
    scanf("%d",&b);
 
    d = a; 
    r = b;
    
    if(a<0) a=-a;
    if(b<0) b=-b;

    s_1=t_0=1;
    s_0=t_1=0;

    while((c = a%b)!=0)
    {
	q = a/b;
        a = b;
        b = c;
        
	s = s_0;
        t = t_0;
        
	s_0 = s_1-q*s_0;
        t_0 = t_1-q*t_0;
        
	s_1 = s;
        t_1 = t;
    }

    printf("\n f( %+d, %+d) = %d", d, r, (b<0?-b:b) );
    printf("\n");
    printf("De donde: ");
    printf("\n (%d(*)s)⊕(%d(*)t) = %d", d, r, (b<0?-b:b)); 
    printf("\n");
    printf("Por lo tanto s = %d, y t = %d", (d<0 ? -s_0:s_0 ), (r < 0 ? -t_0:t_0 ));
    printf("\n");
    printf("Es decir se tiene que (%d(*)%d)⊕(%d(*)%d) = %d", d,(d<0 ? -s_0:s_0 ), r,(r < 0 ? -t_0:t_0 ), b);
    printf("\n");
    

}

