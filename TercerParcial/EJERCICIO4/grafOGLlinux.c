/*
 * Profesor: Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

/********************
 * Mis Declaraciones
 */
#include <unistd.h> 
#include <stdio.h>
#include <stdlib.h>

#include "logo.h"
#include "koch.h"
#include "rama.h"
#include "rama2.h"
#include "misFuncs.h"

#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

//   #define DATA_SIZE 1000

char fractales=0, funciones=0;
f_RenR miFuncion;
misFractales miFractal;
int nRecursion = 5;
LOGO miTortuga;

void segmento(double, double, double, double);
DibujaSegmentos dibujaSegmento=segmento;

/*
 * Mis Declaraciones
 ********************/
void display(void);
void menu_select(int mode);
void nivel_rec(int nivelRec);

GLfloat g(GLfloat x, GLfloat y){
        
	return (x*x) + (y*y); 
}

void campoEscalar(int n, int m, GLfloat f){

        int sizeX = 15;
        int sizeY = 15;

        GLfloat cuad[sizeX+1][sizeY+1][3];
        GLfloat Df = 0.07;
        GLfloat frecuencia = 0.02;
    	GLfloat signo1[2] = {1.0, -1.0};
    

 	int x1 = 0;
   	 int y1 = 0;
    		int q = 0;

   for(q = 0; q <2; q++){
   for(x1 = 0; x1 < sizeX; x1++)
   for(y1 = 0; y1 < sizeY; y1++)
   {
   cuad[x1][y1][0] = signo1[q]*x1 * Df;
   cuad[x1][y1][1] = signo1[q]*y1 * Df;
   cuad[x1][y1][2] = frecuencia*g(x1, y1);

   cuad[x1+1][y1][0] = signo1[q]*(x1 + 1) * Df;
   cuad[x1+1][y1][1] = signo1[q]*y1 * Df;
   cuad[x1+1][y1][2] = frecuencia*g((x1 + 1), y1);

   cuad[x1+1][y1+1][0] = signo1[q]*(x1 + 1) * Df;
   cuad[x1+1][y1+1][1] = signo1[q]*(y1 + 1) * Df;
   cuad[x1+1][y1+1][2] = frecuencia*g((x1 + 1), (y1 + 1));

   cuad[x1][y1+1][0] = signo1[q]*x1 * Df;
   cuad[x1][y1+1][1] = signo1[q]*(y1 + 1) * Df;
   cuad[x1][y1+1][2] = frecuencia*g(x1, (y1 + 1));
        }

  // Cambiar colores  glColor3f( etc, etc, etc) 

   for(x1 = 0; x1 < sizeX; x1++)
   for(y1 = 0; y1 < sizeY; y1++){
glBegin(GL_QUADS);
glColor3f( 0.4, 0.4, 0.4); glVertex3f(  cuad[x1][y1][0],        cuad[x1][y1][1],       cuad[x1][y1][2]);
glColor3f( 0.0, 0.0, 0.5); glVertex3f(  cuad[x1+1][y1][0],    cuad[x1+1][y1][1],     cuad[x1+1][y1][2]);
glColor3f( 0.4, 0.4, 0.4); glVertex3f(  cuad[x1+1][y1+1][0],cuad[x1+1][y1+1][1],   cuad[x1+1][y1+1][2]);
glColor3f( 0.0, 0.0, 0.5); glVertex3f(  cuad[x1][y1+1][0],    cuad[x1][y1+1][1],     cuad[x1][y1+1][2]);
 glEnd();
   }
   }
////////////
   for(q = 0; q <2; q++){
   for(x1 = 0; x1 < sizeX; x1++)
   for(y1 = 0; y1 < sizeY; y1++)
   {
   cuad[x1][y1][0] = -signo1[q]*x1 * Df;
   cuad[x1][y1][1] = signo1[q]*y1 * Df;
   cuad[x1][y1][2] = frecuencia*g(x1, y1);

   cuad[x1+1][y1][0] = -signo1[q]*(x1 + 1) * Df;
   cuad[x1+1][y1][1] = signo1[q]*y1 * Df;
   cuad[x1+1][y1][2] = frecuencia*g((x1 + 1), y1);

   cuad[x1+1][y1+1][0] = -signo1[q]*(x1 + 1) * Df;
   cuad[x1+1][y1+1][1] = signo1[q]*(y1 + 1) * Df;
   cuad[x1+1][y1+1][2] = frecuencia*g((x1 + 1), (y1 + 1));

   cuad[x1][y1+1][0] = -signo1[q]*x1 * Df;
   cuad[x1][y1+1][1] = signo1[q]*(y1 + 1) * Df;
   cuad[x1][y1+1][2] = frecuencia*g(x1, (y1 + 1));



}
// Cambiar colores  glColor3f( etc, etc, etc) 


   for(x1 = 0; x1 < sizeX; x1++)
   for(y1 = 0; y1 < sizeY; y1++){
        glBegin(GL_QUADS);
            glColor3f( 0.4, 0.4, 0.4);      glVertex3f(  cuad[x1][y1][0],        cuad[x1][y1][1],       cuad[x1][y1][2]);
            glColor3f( 0.0, 0.0, 0.5);      glVertex3f(  cuad[x1+1][y1][0],    cuad[x1+1][y1][1],     cuad[x1+1][y1][2]);
            glColor3f( 0.4, 0.4, 0.4);      glVertex3f(  cuad[x1+1][y1+1][0],cuad[x1+1][y1+1][1],   cuad[x1+1][y1+1][2]);
            glColor3f( 0.0, 0.0, 0.5);      glVertex3f(  cuad[x1][y1+1][0],    cuad[x1][y1+1][1],     cuad[x1][y1+1][2]);
            glEnd();
   }
   }
}


int main(int argc, char **argv)
{	
	
	int width = 600, height = 600;
  	int nivelRec;
  	int indice=1;

	 float theta = 0.0f;

       printf("La expresión a evaluar es f(x,y) = x²+y²."); //Aquí lo pueden cambiar, pero cambien la función campo escalar. 
	printf("\n");

	 glutInitWindowSize(width, height);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
  glutCreateWindow("Grafica de |R^2 a |R^3 en Linux c: ");


  while (1)
    	{	


            /* OpenGL animation code goes here */

 	 glClearColor (0.0, 0.0, 0.09, 0.3);
            glClear (GL_COLOR_BUFFER_BIT);
		
	    gluPerspective(45.5f, (GLfloat)(width/height), 10.0f, 10.0f);
          
	glBegin(GL_LINES);
		// draw line for x axis
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
		// draw line for y axis
		glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 1.0, 0.0);
		// draw line for Z axis
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 1.0);

	glEnd();
	 glPushMatrix ();
            glRotatef (theta*0.1, 0.1, 0.0, 0.0);

            glColor3d(0.0, 0.0, 0.0);


            campoEscalar( 1, 1, 1.0);



            //campoEscalar(int n, int m, GLfloat f)-> HERE: CAN DO CANGES COMPAS :D
            glPopMatrix ();

                    glutSwapBuffers ();

            theta += 1.0f;
            sleep (0.025);

}




  nivelRec = glutCreateMenu(nivel_rec);
  glutAddMenuEntry("0 (cero)", 0);
  glutAddMenuEntry("2 (dos)", 2);
  glutAddMenuEntry("4 (cuatro)", 4);
  glutAddMenuEntry("6 (seis)", 6);
  glutAddMenuEntry("8 (ocho)", 8);


  glutCreateMenu(menu_select);
  glutAddMenuEntry("Copo de Koch I", indice++);
  glutAddMenuEntry("Copo de Koch II", indice++);
  glutAddMenuEntry("Copo de Koch III", indice++);
  glutAddMenuEntry("rama", indice++);
  glutAddMenuEntry("rama 2", indice++);
  glutAddMenuEntry("seno", indice++);
  glutAddMenuEntry("coseno", indice++);
  glutAddMenuEntry("parabola", indice++);
  glutAddSubMenu("Nivel de Recurcion", nivelRec); indice++;
  glutAddMenuEntry("Quit", indice++);
  glutAttachMenu(GLUT_RIGHT_BUTTON);



  glutMainLoop();
  return 0;
}

void nivel_rec(int nivelRec)
{
  nRecursion=nivelRec;
  glutPostRedisplay();
}


void menu_select(int mode)
{
	
	glClearColor(0.0,0.0,0.0,0.0);// Color de fondo: negro
	
	glClear(GL_COLOR_BUFFER_BIT);
  switch (mode) {
  case 1:
    fractales=1;
    funciones=0;
    asignaModoDibujarSegmento(segmento, &miTortuga);
    iniciaKoch(10.0, -5.0, 0.0, &miTortuga);
    miFractal = dibujaKoch;
    glutPostRedisplay();
    break;
  case 2:
    fractales=1;
    funciones=0;
    asignaModoDibujarSegmento(segmento, &miTortuga);
    iniciaKoch(10.0, -5.0, 2.5, &miTortuga);
    miFractal = dibujaKochI;
    glutPostRedisplay();
    break;
  case 3:
    fractales=1;
    funciones=0;
    asignaModoDibujarSegmento(segmento, &miTortuga);
    iniciaKoch(10.0, -5.0, -2.5, &miTortuga);
    miFractal = dibujaKochII;
    glutPostRedisplay();
    break;

  case 4:
    fractales=1;
    funciones=0;
    asignaModoDibujarSegmento(segmento, &miTortuga);
    iniciaRama(10.0, 0, -5, &miTortuga);
    miFractal = dibujaRama;
    glutPostRedisplay();
    break;

  case 5:
    fractales=1;
    funciones=0;
    asignaModoDibujarSegmento(segmento, &miTortuga);
    iniciaRama2(10.0, 0, -5, &miTortuga);
    miFractal = dibujaRama2;
    glutPostRedisplay();
    break;



  case 6:
    fractales=0;
    funciones=1;
    miFuncion = seno;
    glutPostRedisplay();
    break;
  case 7:
    fractales=0;
    funciones=1;
    miFuncion = coseno;
    glutPostRedisplay();
    break;
  case 8:
    fractales=0;
    funciones=1;
    miFuncion = parabola;
    glutPostRedisplay();
    break;

  case 10:
    exit(0);
    break;
  }
}



void display(void)
{



glClearColor(0.0,0.0,0.0,0.0);// Color de fondo: negro

glClear(GL_COLOR_BUFFER_BIT);


  glPushMatrix();
            if(fractales==1){
              miFractal(nRecursion);
            } else if (funciones == 1){
              segmento(5.0, 0.0, 0.0, 0.0);
              segmento(0.0, 5.0, 0.0, 0.0);
              grafica(miFuncion, -3.0, 3.0);

            }   
	   
	   
	   
	    glPopMatrix();


  glutSwapBuffers();
}


void segmento(double x1, double y1, double x2, double y2)
{
  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
  glEnd ();
}

