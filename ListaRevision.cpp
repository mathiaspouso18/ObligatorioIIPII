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

void InicializarLista(ListRev &lis)
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

void ListarRev(ListRev lis, Boolean Cabezal)
{
    int largo=0,i=0;
	String desc;

	if(lis == NULL)
	{
		printf("No hay revisiones registradas\n");
	}
	else
	{
        if (Cabezal)
            printf("FECHA       COD_EXPED  DESCRIPCION              EVALUACION\n");

		while(lis!=NULL)
		{
		    printf("%02d/%02d/%d  ",DarFecha(lis->info));
            printf("%-11d",DarCodExpEnRev(lis->info));

		    DarDesc(lis->info,desc);
			print(desc);
            largo=strlar(desc);
            for (i=largo; i<25; i++)
                printf(" ");

            MostrarEvaluacion(DarEv(lis->info));
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
	int largo=0,i=0;

    printf("\nFECHA       COD_EXPED  DESCRIPCION              EVALUACION\n");

	while(lis!=NULL)
	{
		if(DarCodExpEnRev(lis->info) == cod)
		{
		   printf("%02d/%02d/%d  ",DarFecha(lis->info));
            printf("%-11d",DarCodExpEnRev(lis->info));

		    DarDesc(lis->info,desc);
			print(desc);
            largo=strlar(desc);
            for (i=largo; i<25; i++)
                printf(" ");

            MostrarEvaluacion(DarEv(lis->info));
            printf("\n");


		}
		lis = lis->sig;
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
	Revision rev;
	Levantar_Revision (rev, f);
    while (!feof(f))
	{
		InsBack(lis, rev);
		Levantar_Revision (rev, f);
	}
	fclose (f);
}

int CantRevEntreFec(ListRev l, Fecha f1, Fecha f2)
{
    if (l == NULL)
        return 0;
    else
        if (MayorIgualFecha(DarFecha(l->info),f1) && MenorIgualFecha(DarFecha(l->info),f2) )
            return 1 + CantRevEntreFec(l->sig,f1,f2);
        else
            return CantRevEntreFec(l->sig,f1,f2);


}

int CantRevExp(ListRev lis, int cod)
{
    int cant=0;
	while(lis!=NULL){
		if(DarCodExpEnRev(lis->info) == cod)
            cant++;
        lis = lis->sig;
	}
return cant;
}
