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
