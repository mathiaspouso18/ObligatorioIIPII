#include "Expediente.h"
#include "Boolean.h"

void CrearExpediente(Expediente &ex, int cod)
{
}

int DarCodigo(Expediente ex){
	return ex.codigo;
}

void DarNombreEscrib(Expediente ex, String &nombre)
{
    DarNombre(ex.esc, nombre);
}

void DarApellidoEscrib(Expediente ex, String &apellido)
{
    DarApellido(ex.esc, apellido);
}

int DarCantP(Expediente ex){
	return ex.cantPags;
}
