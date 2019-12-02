/*
 * Carlos Coronado
 * Materia: Programaci'on II
 *
 */

#ifndef _MI_KOCH_H_
#define _MI_KOCH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "logo.h"

int iniciaKoch(double l, double x, double y, LOGO *tortuga);
int dibujaKoch(int nivelRecursion);
int dibujaKochI(int nivelRecursion);
int dibujaKochII(int nivelRecursion);


#ifdef __cplusplus
}
#endif

#endif
