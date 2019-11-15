//                      Institto Politénico Nacional.                          //
//                 Escuela Superior de Física y Matemáticas.                    //
//                                                                              //
//                              Progrmación II                                  //
//                Profesor: Luis Carlos Coronado García.                        //
//  EQUIPO: 4  EJERCICIO 4 XD  Alumnos: Flores Rodríguez Jaziel David y los otros compas xD                //
//


#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

#include <stdio.h>
#include <stdlib.h>
//#include "Vector3D.h" -> coming soon
//#include "Matriz3D.h" -> coming soon
#include "logo.h"
#include "koch.h"
#include "rama.h"
#include "rama2.h"
#include "misFuncs.h"

#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

void segmento(double, double, double, double);
DibujaSegmentos dibujaSegmento=segmento;

GLfloat g(GLfloat x, GLfloat y){
//#include <stdio.h>
/*#include <stdlib.h>
 
int main()
{
	return (x*x) + (y*y) ; // -> HERE: Cambiar la función parametrizada compas :D
} 

void campoEscalar(int n, int m, GLfloat f){
	
	GLfloat a = 1.0;
	int sizeX = 10;
	int sizeY = 10;
	
	GLfloat cuad[sizeX+1][sizeY+1][3];
	GLfloat Df = 0.1;
	GLfloat frecuencia = 0.03;
	
	int x1 = 0;
    int y1 = 0;
    int q = 0;
    
    GLfloat signo1[2] = {1.0, -1.0};
    GLfloat signo2[2] = {-1.0, 1.0};
    
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
glColor3f( 0.0, 0.0, 1.0); glVertex3f(  cuad[x1][y1][0],        cuad[x1][y1][1],       cuad[x1][y1][2]);
glColor3f( 0.0, 1.0, 0.0); glVertex3f(  cuad[x1+1][y1][0],    cuad[x1+1][y1][1],     cuad[x1+1][y1][2]);
glColor3f( 1.0, 0.0, 0.0); glVertex3f(  cuad[x1+1][y1+1][0],cuad[x1+1][y1+1][1],   cuad[x1+1][y1+1][2]);
glColor3f( 1.0, 1.0, 1.0); glVertex3f(  cuad[x1][y1+1][0],    cuad[x1][y1+1][1],     cuad[x1][y1+1][2]);
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
            glColor3f( 0.0, 0.0, 1.0);      glVertex3f(  cuad[x1][y1][0],        cuad[x1][y1][1],       cuad[x1][y1][2]);
            glColor3f( 0.0, 1.0, 0.0);      glVertex3f(  cuad[x1+1][y1][0],    cuad[x1+1][y1][1],     cuad[x1+1][y1][2]);
            glColor3f( 1.0, 0.0, 0.0);      glVertex3f(  cuad[x1+1][y1+1][0],cuad[x1+1][y1+1][1],   cuad[x1+1][y1+1][2]);
            glColor3f( 1.0, 1.0, 1.0);      glVertex3f(  cuad[x1][y1+1][0],    cuad[x1][y1+1][1],     cuad[x1][y1+1][2]);
            glEnd();
   }
   }
      
   }


 
 

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "graficos";
    RegisterClass (&wc);

    char fractales=0, funciones=0;
    f_RenR miFuncion;
    misFractales miFractal;
    int nRecursion = 5;
    LOGO miTortuga;
    char *miParametro="koch";

    if (strcmp(lpCmdLine, "")) miParametro = lpCmdLine;
    
    if(strncmp(miParametro, "koch", 4)==0 || strncmp(miParametro, "rama", 4)==0){
      fractales=1;
      asignaModoDibujarSegmento(segmento, &miTortuga);
      if (strncmp(miParametro, "kochII", 6)==0){
        iniciaKoch(10.0, -5.0, -2.5, &miTortuga);
        miFractal = dibujaKochII;
      } else if (strncmp(miParametro, "kochI", 5)==0){
        iniciaKoch(10.0, -5.0, 2.5, &miTortuga);
        miFractal = dibujaKochI;
      } else if (strncmp(miParametro, "rama2", 5)==0){
        iniciaRama2(10.0, 0, -5, &miTortuga);
        miFractal = dibujaRama2;
      } else if (strncmp(miParametro, "rama", 4)==0){
        iniciaRama(10.0, 0, -5, &miTortuga);
        miFractal = dibujaRama;
      } else {
        iniciaKoch(10.0, -5.0, 0.0, &miTortuga);
        miFractal = dibujaKoch;
      }
    } else if(strncmp(miParametro, "seno", 4)==0){
      funciones=1;
      miFuncion = seno;
    } else if(strncmp(miParametro, "coseno", 6)==0){
      funciones=1;
      miFuncion = coseno;
    } else if(strncmp(miParametro, "parabola", 8)==0){
      funciones=1;
      miFuncion = parabola;
    }

    /* create main window */
    hWnd = CreateWindow (
      "graficos", 
      "En este SO tan feo :c", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 2*256, 2*256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
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


            glClearColor (1.0f, 1.0f, 1.0f, 0.5f);
            glClear (GL_COLOR_BUFFER_BIT);

		
            campoEscalar( 1, 1, 1.0);
            
            glPopMatrix ();

            SwapBuffers (hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}


void segmento(double x1, double y1, double x2, double y2)
{
	  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
}
