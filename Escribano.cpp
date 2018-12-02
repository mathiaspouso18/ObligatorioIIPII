#include "Escribano.h"


void DarNombre(Escribano esc, String &nom)
{
    strcop(nom, esc.nombre);
}

void DarApellido(Escribano esc, String &ape)
{
    strcop(ape, esc.apellido);
}

void CrearEscribano(Escribano &esc)
{
    String s1, s2;
    printf("Ingrese nombre del escribano: ");
    scan(s1);
    printf("Ingrese apellido del escribano: ");
    scan(s2);

    strcop(esc.nombre, s1);
    strcop(esc.apellido, s2);
}

void LlenarEscribano(Escribano &esc, String Nombre, String Apellido)
{
    strcop(esc.nombre, Nombre);
    strcop(esc.apellido, Apellido);
}

