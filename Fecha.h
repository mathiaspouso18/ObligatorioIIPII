#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct Fecha {int dia;
                      int mes;
                      int anio;};

int DarDia(Fecha f);
int DarMes(Fecha f);
int DarAnio(Fecha f);

#endif // FECHA_H_INCLUDED
