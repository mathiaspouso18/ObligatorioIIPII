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

/* PRECONDICION: ABB no vacio */
Expediente Minimo (Arbol ABB);

/* Precondición : el árbol a NO está vacío */
void Borrar_Minimo (Arbol &ABB);

/* Precondición : el valor cod existe en el árbol a */
void Borrar (Arbol &ABB, int cod);

#endif // ABBEXPEDIENTE_H_INCLUDED
