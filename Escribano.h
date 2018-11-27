#ifndef ESCRIBANO_H_INCLUDED
#define ESCRIBANO_H_INCLUDED
#include "String.h"

typedef struct {
                String nombre;
                String apellido;
                }Escribano;


void DarNombre(Escribano esc, String &nom);
void DarApellido(Escribano esc, String &ape);

#endif // ESCRIBANO_H_INCLUDED
