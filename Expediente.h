#ifndef EXPEDIENTE_H_INCLUDED
#define EXPEDIENTE_H_INCLUDED
#include "Escribano.h"

typedef struct {int codigo;
               String Caratula;
               Escribano esc;
               int cantPags;
               }Expediente;

//PRECONDICION: El expediente no puede existir previamente.
void CrearExpediente(Expediente &ex, int cod);

int DarCodigo(Expediente ex);

void DarCaratula(Expediente ex, String &caratula);

void DarNombreEscrib(Expediente ex, String &nombre);

void DarApellidoEscrib(Expediente ex, String &apellido);

int DarCantP(Expediente ex);

void Bajar_Expediente (Expediente ex, FILE * f) ;

void Levantar_Expediente (Expediente &ex, FILE * f);

#endif // EXPEDIENTE_H_INCLUDED
