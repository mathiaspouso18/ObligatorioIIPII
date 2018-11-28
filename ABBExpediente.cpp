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

void ListarExp(Arbol ABB)
{
	String caratula, nom, ape;
	if (ABB != NULL)
	{
		ListarExp(ABB -> hizq);

		printf("\t");
		printf("Codigo expediente: %d",DarCodigo(ABB ->info));
		printf(" | ");
		printf("Caratula: ");
		DarCaratula(ABB ->info, caratula);
		print(caratula);
		printf(" | ");
		printf("Escribano: ");
		DarNombreEscrib(ABB ->info, nom);
		DarApellidoEscrib(ABB ->info, ape);
		print(nom);
		printf(" ");
		print(ape);
		printf(" | ");
		printf("Cant. Pag: %d", DarCantP(ABB ->info));			
		printf("\n");

		ListarExp(ABB -> hder);
	} 
}

void ListarMinMax(Arbol ABB)
{
	String caratula, nom, ape;
	Expediente exmin, exmax;

	exmin = Minimo(ABB);

	printf("\t");
	printf("Codigo expediente: %d",exmin);
	printf(" | ");
	printf("Caratula: ");
	DarCaratula(exmin, caratula);
	print(caratula);
	printf(" | ");
	printf("Escribano: ");
	DarNombreEscrib(exmin, nom);
	DarApellidoEscrib(exmin, ape);
	print(nom);
	printf(" ");
	print(ape);
	printf(" | ");
	printf("Cant. Pag: %d", DarCantP(exmin));			
	printf("\n");

	exmax = Maximo(ABB);

	printf("\t");
	printf("Codigo expediente: %d",exmax);
	printf(" | ");
	printf("Caratula: ");
	DarCaratula(exmax, caratula);
	print(caratula);
	printf(" | ");
	printf("Escribano: ");
	DarNombreEscrib(exmax, nom);
	DarApellidoEscrib(exmax, ape);
	print(nom);
	printf(" ");
	print(ape);
	printf(" | ");
	printf("Cant. Pag: %d", DarCantP(exmax));			
	printf("\n");
}
