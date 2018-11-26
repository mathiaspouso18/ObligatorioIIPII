#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "Escribano.h"

typedef struct {int codigo;
               /*Caratula??*/
               Escribano esc;
               int cantPags;
               }Expediente;

int Darcodigo(Expediente ex);

Escribano DarEscrib(Expediente ex);

int DarCantP(Expendiente ex);

#endif // EXPEDIENTE_H_INCLUDED
