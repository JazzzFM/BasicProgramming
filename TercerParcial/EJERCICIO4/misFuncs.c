/*
 * Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "misFuncs.h"

double seno(double x)
{
  return sin(x*x+x+1);
}

double coseno(double x)
{
  double aux = cos(x);
  return aux*aux;
}

double parabola(double x)
{
  return x*x-1;
}

void grafica(f_RenR f, double a, double b)
{
    double x1, y1, x2, y2, dx=(b-a)/100.0;
    
    for(y1=f(x1=a); x1<b; x1=x2, y1=y2){
        y2=f(x2=x1+dx);
        dibujaSegmento(x1, y1, x2, y2);
    }
}


