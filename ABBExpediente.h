#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "Expediente.h"

typedef struct nodoN{Expediente info;
                    nodoN *hizq;
                    nodoN *hder;} nodo;

typedef nodo *Arbol;

void InicializarArbol(Arbol &ABB);
Boolean ExisteExp(int cod, Arbol abb);
Boolean EsVacio(Arbol ABB);
Expediente DarRaiz(Arbol ABB);
Arbol HijoIzquierdo(Arbol ABB);
Arbol HijoDerecho(Arbol ABB);
void Cons(Arbol i, Arbol d, int valor, Arbol &ABB);
void InsertarNodo(Arbol &ABB, Expediente ex);
#endif // ABBEXPEDIENTE_H_INCLUDED
