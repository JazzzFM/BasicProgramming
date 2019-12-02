#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i,j,n,t;
    int *p ;

printf("Algoritmo 2. Una permutación particular, se require una lista de n ≥ 2 enteros en un arreglo A[ ] indexado de 0 a n − 1. Se obtiene un resultado desconocido, decirlo.\n");
	printf("\n");
	printf("Ingrese el número de elementos de su arreglo, n = ");
        scanf("%d",&n);

        p = (int *)malloc(n*sizeof(int)); 

        if(p == NULL)
        {
                printf("Insuficiente Espacio de Memoria");
                return; 
        }

	printf("Ingrese los elementos a guardar: \n");
        for(i=0; i<n ;i++)
        {
                printf("Elemento A[%d] = ", i);
                scanf("%d",(p+i));
        }

	printf("\n");

        printf("Los elementos del arreglo son: \n");

        for(i=0; i<n; i++)
        {
                printf("%s%d%s%d%s","A[",i,"]= ",*(p+i),", ");
        } free(p); 
	



	printf("\n");

    for(i=0; i<n; i++)
    {
        for(j=n-1; j>i; j--)
	{
            if(*(p+j)<*(p+j-1))
		{	
                t = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = t;
           	 }
        }
    }

    printf("\n");

    printf("Ahora, después de aplicar el algoritmo, los elementos del arreglo son: \n");

        for(i=0; i<n; i++)
        {
                 printf("%s%d%s%d%s","A[",i,"]= ",*(p+i),", ");

        }

        printf("\n \n");
	printf("El resutado es que se ordenaron los elementos del arreglo de menor a mayor, desde el índice 0 hasta %d", n-1);
	printf("\n");


}
