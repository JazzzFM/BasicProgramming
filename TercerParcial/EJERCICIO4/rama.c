/*
 * Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#include "logo.h"
#include "rama.h"

double longitudRama;
double miX0Rama;
double miY0Rama;
LOGO *tortugaAuxRama;

int RamaRecursiva(int n, double l, LOGO *tortuga);

int iniciaRama(double l, double x, double y, LOGO *tortuga)
{
  longitudRama = l;
  miX0Rama=x;
  miY0Rama=y;
  tortugaAuxRama = tortuga;
  
  return 0;
}

int dibujaRama(int nivelRecursion){
  inicia(miX0Rama, miY0Rama, 90, ABAJO, tortugaAuxRama);

  return RamaRecursiva(nivelRecursion, longitudRama, tortugaAuxRama);
}

int RamaRecursiva(int n, double l, LOGO *tortuga)
{
  double lTercios;
  if (n<=1){
    avanza(l, tortuga);
    return 0;
  }
  lTercios = l/3.0;
  avanza(lTercios, tortuga);
  der(45, tortuga);
  RamaRecursiva(n-1, lTercios, tortuga);
  laPluma(ARRIBA, tortuga);
  retrocede(lTercios, tortuga);
  laPluma(ABAJO, tortuga);
  izq(45, tortuga);
  avanza(lTercios, tortuga);
  izq(45, tortuga);
  RamaRecursiva(n-1, lTercios, tortuga);
  laPluma(ARRIBA, tortuga);
  retrocede(lTercios, tortuga);
  laPluma(ABAJO, tortuga);
  der(45, tortuga);
  avanza(lTercios, tortuga);

  return 0;
}


