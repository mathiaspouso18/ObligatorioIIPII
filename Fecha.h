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
#endif // FECHA_H_INCLUDED
