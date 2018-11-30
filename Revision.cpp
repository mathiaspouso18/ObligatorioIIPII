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

void Bajar_Revision(Revision rev, FILE *f)
{
	int Dia, Mes, Anio;
	Dia = DarDia(rev.fecRea);
	Mes = DarMes(rev.fecRea);
	Anio = DarAnio(rev.fecRea);
	fwrite (&Dia, sizeof(int), 1, f);
	fwrite (&Mes, sizeof(int), 1, f);
	fwrite (&Anio, sizeof(int), 1, f);
	fwrite (&rev.codigoExp, sizeof(int), 1, f);
	fwrite (&rev.eval, sizeof(Evaluacion), 1, f);
	Bajar_String (rev.descripcion, f);
}

void Levantar_Revision (Revision &rev, FILE * f)
{
	Fecha fec;
	fread (&fec.dia,sizeof(int), 1, f);
	fread (&fec.mes,sizeof(int), 1, f);
	fread (&fec.anio,sizeof(int), 1, f);
	rev.fecRea = fec;
	fread (&rev.codigoExp, sizeof(int), 1, f);
	fread (&rev.eval, sizeof(Evaluacion), 1, f);
	strcrear (rev.descripcion);
	Levantar_String (rev.descripcion, f);
}
