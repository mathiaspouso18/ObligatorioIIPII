#include "Expediente.h"

void CrearExpediente(Expediente &ex, int cod)
{
    Escribano esc;
    ex.codigo = cod;
    printf("Ingrese caratula: ");
    scan(ex.Caratula);
    printf("Ingrese cantidad de paginas: ");
    scanf("%d", &ex.cantPags);
    CrearEscribano(esc);
    ex.esc = esc;
}

int DarCodigo(Expediente ex)
{
	return ex.codigo;
}

void DarCaratula(Expediente ex, String &caratula)
{
	strcop(caratula, ex.Caratula);
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
