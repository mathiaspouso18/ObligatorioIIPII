#include "Revision.h"

typedef struct nodo_rev{Revision info;
						nodo_rev * sig;} Nodo;
typedef Nodo * ListRev;

void Crear(ListRev &lis);

Boolean EsVaciaLis (ListRev lis);

/* Precondici�n: lista NO vac�a */
Revision Primero(ListRev lis);

/* Precondici�n: lista NO vac�a */
void Resto (ListRev &lis);

void InsFront (ListRev &lis, Revision rev);

//Precondicion: debe ser una fecha valida
Boolean EsValidaSis(ListRev lis, Fecha f);

void BorrarRev (ListRev &lis, int cod);

int DarAnioRev(Revision r);
int DarMesRev(Revision r);
int DarDiaRev(Revision r);
