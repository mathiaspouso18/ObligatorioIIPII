#include "stdafx.h"
#include "ListaRevision.h"

void Crear(ListRev &lis)
{
	lis = NULL;
}
Boolean Vacia(ListRev lis)
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
	if(f.anio >= DarFecha(lis->info).anio && f.mes >=DarFecha(lis->info).mes && f.dia >= DarFecha(lis->info).dia)
		es = TRUE;
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