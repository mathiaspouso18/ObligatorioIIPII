#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>
#include "Boolean.h"

typedef struct  {int dia;
                      int mes;
                      int anio;}Fecha;

int DarDia(Fecha f);
int DarMes(Fecha f);
int DarAnio(Fecha f);
void CargarFecha(Fecha &f);
void DesplegarFecha(Fecha f);
Boolean EsValida(Fecha f);

//Si f1 es menor a f2
Boolean MenorIgualFecha (Fecha f1, Fecha f2);

Boolean MayorIgualFecha(Fecha f1, Fecha f2);


#endif // FECHA_H_INCLUDED
