#ifndef ABBEXPEDIENTE_H_INCLUDED
#define ABBEXPEDIENTE_H_INCLUDED

#include "Expediente.h"
#include "ListaRevision.h"

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
Expediente Maximo (Arbol ABB);

/* PRECONDICION: ABB no vacio */
Expediente Minimo (Arbol ABB);

/* Precondición : el árbol NO está vacío */
void Borrar_Minimo (Arbol &ABB);

/* Precondición : el valor cod existe en el árbol a */
void Borrar (Arbol &ABB, int cod);

/*Precodicion: ABB no vacio */
void ListarExp(Arbol ABB, Boolean Cabezal);

/*Precodicion: ABB no vacio */
void ListarMinMax(Arbol ABB);

/*Precodicion: ABB no vacio */
int ExpxEscribano(Arbol ABB, String ape);

void Bajar_ABB_Aux (Arbol ABB, FILE * f);

void Bajar_ABB (Arbol ABB , String nomArch);

/*Precondicion: Debe existir el archivo.*/
void Levantar_ABB (Arbol &ABB, String nomArch);

/*Precodicion: ABB no vacio */
/* Si hay mas de un expediente con la misma cantidadad de revisiones
muestra el expediente mas cercano a la raiz del abb*/
int ExpConMasRev(Arbol ABB, ListRev lis, int MayorCant, int Codigo);


#endif // ABBEXPEDIENTE_H_INCLUDED
