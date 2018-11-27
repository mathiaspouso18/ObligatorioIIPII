#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "Escribano.h"

typedef struct {int codigo;
               String Caratula;
               Escribano esc;
               int cantPags;
               }Expediente;

void CrearExpediente(Expediente &ex, int cod);

int DarCodigo(Expediente ex);

void DarNombreEscrib(Expediente ex, String &nombre);

void DarApellidoEscrib(Expediente ex, String &apellido);

int DarCantP(Expediente ex);

#endif // EXPEDIENTE_H_INCLUDED
