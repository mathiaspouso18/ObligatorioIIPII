#include "Revision.h"

typedef struct nodo_rev{Revision info;
						nodo_rev * sig;} Nodo;
typedef Nodo * ListRev;

void Crear(ListRev &lis);

Boolean Vacia (ListRev lis);

/* Precondición: lista NO vacía */
Revision Primero(ListRev lis);

/* Precondición: lista NO vacía */
void Resto (ListRev &lis);

void InsFront (ListRev &lis, Revision rev);

//Precondicion: debe ser una fecha valida
Boolean EsValidaSis(ListRev lis, Fecha f);

void BorrarRev (ListRev &lis, int cod);