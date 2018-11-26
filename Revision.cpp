#include "Revision.h"

Fecha DarFecha(Revision rev){
	return rev.fecRea;
}

String DarDesc(Revision rev){
	return rev.descripcion;
}

int DarCodExp(Revision rev){
	return rev.codigoExp;
}

Evaluacion DarEv(Revision rev){
	return rev.eval;
}
