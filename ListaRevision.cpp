#include "ListaRevision.h"

void Crear(ListRev &lis)
{
	lis = NULL;
}
Boolean EsVaciaLis(ListRev lis)
{
	Boolean es = FALSE;
	if (lis == NULL)
        es = TRUE;
	return es;
}

Revision Primero(ListRev lis)
{
	return lis -> info;
}

void Resto (ListRev &lis)
{
	ListRev aux = lis;
	lis = lis -> sig;
	delete aux;
}

void InsFront (ListRev &lis, Revision rev)
{
	ListRev aux = new Nodo;
	aux -> info = rev;
	aux -> sig = lis;
	lis = aux;
}

Boolean EsValidaSis(ListRev lis, Fecha f)
{
	Boolean es = FALSE;
	if (DarAnio(f) > DarAnioRev(lis->info))
        es = TRUE;
    else
    {
        if (DarAnio(f) == DarAnioRev(lis->info))
        {
            if (DarMes(f) > DarMesRev(lis->info))
                es = TRUE;
            else
            {
                if (DarMes(f) == DarMesRev(lis->info))
                {
                    if (DarDia(f) >= DarDiaRev(lis->info))
                        es = TRUE;
                }
            }
        }
    }
	return es;
}

void BorrarRev (ListRev &lis, int cod)
{
	if (lis != NULL)
	{
		if (cod == DarCodExpEnRev(lis -> info))
		{
			ListRev aux = lis;
			lis = lis -> sig;
			delete aux;
			BorrarRev (lis, cod);
		}
	else
		BorrarRev (lis -> sig, cod);
	}
}

int DarAnioRev(Revision r)
{
    return DarAnio(r.fecRea);
}

int DarMesRev(Revision r)
{
    return DarMes(r.fecRea);
}

int DarDiaRev(Revision r)
{
    return DarDia(r.fecRea);
}
