/*
 * Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#include "logo.h"
#include "rama2.h"

double longitudRama2;
double miX0Rama2;
double miY0Rama2;
LOGO *tortugaAuxRama2;

int Rama2Recursiva(int n, double l, LOGO *tortuga);

int iniciaRama2(double l, double x, double y, LOGO *tortuga)
{
  longitudRama2 = l;
  miX0Rama2=x;
  miY0Rama2=y;
  tortugaAuxRama2 = tortuga;
  
  return 0;
}

int dibujaRama2(int nivelRecursion){
  inicia(miX0Rama2, miY0Rama2, 90, ABAJO, tortugaAuxRama2);

  return Rama2Recursiva(nivelRecursion, longitudRama2, tortugaAuxRama2);
}

int Rama2Recursiva(int n, double l, LOGO *tortuga)
{
  double lTercios, lMedios;
  if (n<=1){
    avanza(l, tortuga);
    return 0;
  }
  lTercios = l/3.0;
  lMedios = l/2.0;
  avanza(lTercios, tortuga);
  der(40, tortuga);
  Rama2Recursiva(n-1, lMedios, tortuga);
  laPluma(ARRIBA, tortuga);
  retrocede(lMedios, tortuga);
  laPluma(ABAJO, tortuga);
  izq(40, tortuga);
  avanza(lTercios, tortuga);
  izq(50, tortuga);
  Rama2Recursiva(n-1, lMedios, tortuga);
  laPluma(ARRIBA, tortuga);
  retrocede(lMedios, tortuga);
  laPluma(ABAJO, tortuga);
  der(50, tortuga);
  avanza(lTercios, tortuga);

  return 0;
}


