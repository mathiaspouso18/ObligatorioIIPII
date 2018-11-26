#include "Expediente.h"

int Darcodigo(Expediente ex){
	return ex.codigo;
}

Escribano DarEscrib(Expediente ex){
	return ex.esc;
}

int DarCantP(Expediente ex){
	return ex.cantPags;
}
