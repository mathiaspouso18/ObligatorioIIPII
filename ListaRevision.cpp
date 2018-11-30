#include "ListaRevision.h"

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

void InsBack (ListRev &L, Revision rev)
{
    if (L == NULL)
     {
         L = new Nodo;
         L -> info = rev;
         L -> sig = NULL;
     }
     else
        InsBack (L -> sig, rev);
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

void ListarRev (ListRev lis)
{
	String desc;
	if(lis == NULL)
	{
		printf("\tNo hay revisiones registradas\n");
	}
	else
	{
		while(lis!=NULL)
		{
			printf("\t");
			printf("Fecha: %d/%d/%d",DarFecha(lis->info));
			printf(" | ");
			printf("Descripcion: ");
			DarDesc(lis->info,desc);
			print(desc);
			printf(" | ");
			printf("Codigo expediente: %d",DarCodExpEnRev(lis->info));
			printf(" | ");
			printf("Evaluacion: ");
			if(DarEv(lis->info) == Satisfactoria)
			{
				printf("Satisfactoria");
			}
			else
			{
				if(DarEv(lis->info) == Incompleta)
				{
					printf("Incompleta");
				}
				else
				{
					printf("Pendiente");
				}

			}
			printf("\n");

			lis = lis->sig;
		}

	}

}

Boolean TieneRev (ListRev lis, int cod)
{
	Boolean existe = FALSE;
	while(lis != NULL && !existe)
	{
		if(DarCodExpEnRev(lis->info) == cod)
			existe = TRUE;
		lis = lis->sig;
	}

	return existe;
}

void ListarRevxExp(ListRev lis, int cod)
{
	String desc;
	while(lis!=NULL)
	{
		if(DarCodExpEnRev(lis->info) == cod)
		{
			printf("\t");
			printf("Fecha: %d/%d/%d",DarFecha(lis->info));
			printf(" | ");
			printf("Descripcion: ");
			DarDesc(lis->info,desc);
			print(desc);
			printf(" | ");
			printf("Codigo expediente: %d",cod);
			printf(" | ");
			printf("Evaluacion: ");
			if(DarEv(lis->info) == Satisfactoria)
			{
				printf("Satisfactoria");
			}
			else
			{
				if(DarEv(lis->info) == Incompleta)
				{
					printf("Incompleta");
				}
				else
				{
					printf("Pendiente");
				}
			}
			printf("\n");

			lis = lis->sig;
		}
	}
}

void RevxEvaluacion(ListRev lis, int &Satis, int &inComp, int &Pend)
{
	Satis = 0, inComp = 0, Pend = 0;
	while(lis != NULL)
	{
		if(DarEv(lis->info) == Satisfactoria)
			{
				Satis++;;
			}
			else
			{
				if(DarEv(lis->info) == Incompleta)
				{
					inComp++;
				}
				else
				{
					Pend++;
				}
			}
		lis = lis->sig;
	}
}

void Bajar_Lista (ListRev lis , String nomArch)
{
	FILE * f = fopen (nomArch, "wb");
	while (lis != NULL)
	{
		Bajar_Revision (lis -> info, f);
		lis = lis -> sig;
	}
	fclose (f);
}

void Levantar_Lista (ListRev &lis, String nomArch)
{
	FILE * f = fopen (nomArch, "rb");
	Revision buffer;
	Levantar_Revision (buffer, f);
	 while (!feof(f))
	{
		InsBack(lis, buffer);
		Levantar_Revision (buffer, f);
	}
	fclose (f);
}

int ContarRevEntreFec(ListRev l, Fecha f1, Fecha f2)
{
    if (l == NULL)
        return 0;
    else
        if ( MayorIgualFecha(DarFecha(l->info),f1) && MenorIgualFecha(DarFecha(l->info),f2) )
            return 1 + ContarRevEntreFec(l->sig,f1,f2);
        else
            return ContarRevEntreFec(l->sig,f1,f2);


}
