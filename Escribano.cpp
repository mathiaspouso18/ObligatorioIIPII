#include "Escribano.h"

void DarNombre(Escribano esc, String &nom)
{
    strcop(nom, esc.nombre);
}

void DarApellido(Escribano esc, String &ape)
{
    strcop(ape, esc.apellido);
}

