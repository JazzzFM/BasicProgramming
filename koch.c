/*
 * Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#include "logo.h"
#include "koch.h"

double longitudKoch;
double miX0Koch;
double miY0Koch;
LOGO *tortugaAuxKoch;

int KochRecursivo(int n, double l, LOGO *tortuga);

int iniciaKoch(double l, double x, double y, LOGO *tortuga)
{
  longitudKoch = l;
  miX0Koch=x;
  miY0Koch=y;
  tortugaAuxKoch = tortuga;
  
  return 0;
}

int dibujaKoch(int nivelRecursion){
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  return KochRecursivo(nivelRecursion, longitudKoch, tortugaAuxKoch);
}

int dibujaKochI(int nivelRecursion){
  int i;
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  for (i=0; i<3; i++){
    KochRecursivo(nivelRecursion, longitudKoch, tortugaAuxKoch);
    der(120, tortugaAuxKoch);
  }
  return 0;
}

int dibujaKochII(int nivelRecursion){
  int i;
  inicia(miX0Koch, miY0Koch, 0, ABAJO, tortugaAuxKoch);

  for (i=0; i<3; i++){
    KochRecursivo(nivelRecursion, longitudKoch, tortugaAuxKoch);
    izq(120, tortugaAuxKoch);
  }
  return 0;
}

int KochRecursivo(int n, double l, LOGO *tortuga)
{
  double l3;
  if (n<=0){
    avanza(l, tortuga);
    return 0;
  }
  l3=l/3.0;
  KochRecursivo(n-1, l3, tortuga);
  izq(60, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  der(120, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  izq(60, tortuga);
  KochRecursivo(n-1, l3, tortuga);
  
  return 0;
}
