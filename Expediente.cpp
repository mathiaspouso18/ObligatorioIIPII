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

void Bajar_Expediente (Expediente ex, FILE * f) 
{
	String nom, ape;
	fwrite (&ex.codigo, sizeof(int), 1, f);
	Bajar_String (ex.Caratula, f);
	DarNombreEscrib(ex,nom);
	DarApellidoEscrib(ex,ape);
	Bajar_String (nom, f);
	Bajar_String (ape, f);
	fwrite (&ex.cantPags, sizeof(int), 1, f);
} 

void Levantar_Expediente (Expediente &ex, FILE * f)
{
	Escribano esc;
	fread(&ex.codigo,sizeof(int), 1, f);
	strcrear (ex.Caratula);
	Levantar_String (ex.Caratula, f);
	Levantar_String (esc.nombre, f);
	Levantar_String (esc.apellido, f);
	ex.esc = esc;
	fread (&ex.cantPags, sizeof(int), 1, f);
} 
