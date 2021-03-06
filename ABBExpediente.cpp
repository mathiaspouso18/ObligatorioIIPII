#include "ABBExpediente.h"

void InicializarArbol(Arbol &ABB)
{
    ABB = NULL;
}

Boolean ExisteExp(int cod, Arbol abb)
{
    Boolean existe = FALSE;

    while(!existe && abb != NULL){
        if(cod == DarCodigo(abb->info))
        {
            existe = TRUE;
        }
        else
        {
            if(cod < DarCodigo(abb->info))
                abb = abb->hizq;
            else
                abb = abb->hder;
        }
    }
    return existe;
}

Boolean EsVacio(Arbol ABB)
{
    Boolean es = TRUE;
    if(ABB != NULL)
        es = FALSE;

    return es;
}

Expediente DarRaiz(Arbol ABB)
{
    return ABB->info;
}

Arbol HijoIzquierdo(Arbol ABB)
{
    return ABB->hizq;
}

Arbol HijoDerecho(Arbol ABB)
{
    return ABB->hder;
}

void Cons(Arbol i, Arbol d, Expediente valor, Arbol &ABB)
{
    ABB = new nodo;
    ABB->info = valor;
    ABB->hizq = i;
    ABB->hder = d;
}

void InsertarNodo(Arbol &ABB, Expediente ex)
{
    if (ABB == NULL)
    {
        ABB = new nodo;
        ABB -> info = ex;
        ABB -> hizq = NULL;
        ABB -> hder = NULL;
    }
    else
    {
        if (DarCodigo(ex) < DarCodigo(ABB->info))
            InsertarNodo (ABB -> hizq, ex);
        else
            InsertarNodo (ABB -> hder, ex);
    }
}

Expediente Maximo (Arbol ABB)
{
	if (ABB -> hder == NULL)
		return (ABB->info);
	else
		return Maximo(ABB -> hder);
}

Expediente Minimo (Arbol ABB)
{
	if (ABB -> hizq == NULL)
		return (ABB->info);
	else
		return Minimo (ABB -> hizq);
}

void Borrar_Minimo (Arbol &ABB)
{
	Arbol aux;
	if (ABB -> hizq == NULL)
	{
		aux = ABB -> hder;
		delete ABB;
		ABB = aux;
	}
	else
		Borrar_Minimo (ABB -> hizq);
}

void Borrar (Arbol &ABB, int cod)
{
	Arbol aux;
	if (cod == DarCodigo(ABB -> info))
	{
		if (ABB -> hder == NULL)
		{
			aux = ABB -> hizq;
			delete ABB;
			ABB = aux;
		}
		else
		{
			if (ABB -> hizq == NULL)
			{
				aux = ABB -> hder;
				delete ABB;
				ABB = aux;
			}
			else
			{
				ABB -> info = Minimo (ABB -> hder);
				Borrar_Minimo (ABB -> hder);
			}
		}
	}
	else
	{
		if (cod < DarCodigo(ABB -> info))
			Borrar (ABB -> hizq, cod);
		else
			Borrar (ABB -> hder, cod);
	}
 }

void ListarExp(Arbol ABB, Boolean Cabezal)
{
    String caratula, nom, ape;
	int largo=0,i=0;

    if (Cabezal)
        printf("\nCODIGO     CARATULA              ESCRIBANO                 PAGINAS\n");


	if (ABB != NULL)
	{
		ListarExp(ABB -> hizq,FALSE);
		//Codigo
        printf ("%-11d", DarCodigo(ABB->info));

        //Caratula
        DarCaratula(ABB->info,caratula);
        print(caratula);
        largo=strlar(caratula);
        for (i=largo; i<22; i++)
            printf(" ");

        //Escribano
        DarNombreEscrib(ABB ->info, nom);
		DarApellidoEscrib(ABB ->info, ape);
        print(nom);
		printf(" ");
		print(ape);
        largo=strlar(nom)+strlar(ape)+1;
        for (i=largo; i<26; i++)
            printf(" ");

        //Cant Paginas
        printf("%d\n",DarCantP(ABB->info));

		ListarExp(ABB -> hder,FALSE);
	}
}

void ListarMinMax(Arbol ABB)
{
	String caratula, nom, ape;
	Expediente exmin, exmax;
	int largo=0, i=0;

	exmin = Minimo(ABB);

    printf("CODIGO     CARATULA              ESCRIBANO                 PAGINAS\n");

	printf("%-11d",exmin);

	DarCaratula(exmin, caratula);
	print(caratula);
    largo=strlar(caratula);
    for (i=largo; i<22; i++)
        printf(" ");


	DarNombreEscrib(exmin, nom);
	DarApellidoEscrib(exmin, ape);
	print(nom);
	printf(" ");
	print(ape);
	largo=strlar(nom)+strlar(ape)+1;
    for (i=largo; i<26; i++)
        printf(" ");

	printf("%d", DarCantP(exmin));
	printf("\n");

	exmax = Maximo(ABB);


    printf("%-11d",exmax);

	DarCaratula(exmax, caratula);
	print(caratula);
    largo=strlar(caratula);
    for (i=largo; i<22; i++)
        printf(" ");


	DarNombreEscrib(exmax, nom);
	DarApellidoEscrib(exmax, ape);
	print(nom);
	printf(" ");
	print(ape);
	largo=strlar(nom)+strlar(ape)+1;
    for (i=largo; i<26; i++)
        printf(" ");

	printf("%d", DarCantP(exmax));
	printf("\n");

}

int ExpxEscribano(Arbol ABB, String ape)
{
	if (ABB == NULL)
		return 0;
	else
	{
		String apeexp;
		DarApellidoEscrib(ABB->info, apeexp);
		if(streq(apeexp, ape))
			return 1 + ExpxEscribano(ABB->hizq, ape) + ExpxEscribano(ABB->hder, ape);
        else
            return ExpxEscribano(ABB->hizq, ape) + ExpxEscribano(ABB->hder, ape);;
	}
}

void Bajar_ABB_Aux (Arbol ABB, FILE * f)
{
	if (ABB != NULL)
	{
		Bajar_Expediente (ABB->info, f);
		Bajar_ABB_Aux (ABB -> hizq, f);
		Bajar_ABB_Aux (ABB -> hder, f);
	}
}

void Bajar_ABB (Arbol ABB, String nomArch)
{
	FILE * f = fopen (nomArch, "wb");
	Bajar_ABB_Aux (ABB, f);
	fclose (f);
}

void Levantar_ABB (Arbol &ABB, String nomArch)
{
	FILE * f = fopen (nomArch, "rb");
	Expediente ex;
    Levantar_Expediente(ex, f);
	while (!feof(f))
	{
		InsertarNodo(ABB, ex);
		Levantar_Expediente(ex, f);
	}
	fclose (f);
}

int ExpConMasRev(Arbol ABB, ListRev lis, int MayorCant,int Codigo)
{
    int CurrCant=0;
	if (ABB != NULL){


        Codigo = ExpConMasRev(ABB -> hder,lis,MayorCant,Codigo);

        CurrCant = CantRevExp(lis,DarCodigo(ABB->info));
        if (MayorCant < CurrCant){
            MayorCant = CurrCant;
            Codigo = DarCodigo(ABB->info);
        }

        Codigo = ExpConMasRev(ABB -> hizq,lis,MayorCant,Codigo);


	}
    return Codigo;
}
