#include "Revision.h"

Fecha DarFecha(Revision rev){
	return rev.fecRea;
}

void DarDesc(Revision rev, String &desc){
	strcop(desc, rev.descripcion);
}

int DarCodExpEnRev(Revision rev){
	return rev.codigoExp;
}

Evaluacion DarEv(Revision rev){
	return rev.eval;
}

void CrearRevision(Revision &r, int cod, Fecha f)
{
    int a;
    String s;
    Evaluacion eva;
    printf("Ingrese la descripcion: ");
    scan(s);
    printf("Ingrese evaluacion 1-Satisfactoria; 2-Incompleta; 3-Pendiente: ");
    scanf("%d", &a);
    switch(a)
    {
        case 1: eva = Satisfactoria;
        break;
        case 2: eva = Incompleta;
        break;
        case 3: eva = Pendiente;
        break;
    }

    r.fecRea = f;
    r.codigoExp = cod;
    r.eval = eva;
    strcop(r.descripcion, s);
}
