#include "Revision.h"

typedef struct nodo_rev{Revision info;
						nodo_rev * sig;} Nodo;
typedef Nodo * ListRev;

void Crear(ListRev &lis);

int DarAnioRev(Revision r);
int DarMesRev(Revision r);
int DarDiaRev(Revision r);

Boolean EsVaciaLis (ListRev lis);

/* Precondición: lista NO vacía */
Revision Primero(ListRev lis);

/* Precondición: lista NO vacía */
void Resto (ListRev &lis);

void InsFront (ListRev &lis, Revision rev);
void InsBack (ListRev &L, Revision rev);

//Precondicion: debe ser una fecha valida
Boolean EsValidaSis(ListRev lis, Fecha f);

void BorrarRev (ListRev &lis, int cod);

void ListarRev (ListRev lis);

/* Precondición: lista NO vacía */
Boolean TieneRev (ListRev lis, int cod);

/*Precondicion: el expediente debe existir en el sistema y debe tener al menos una revision*/
void ListarRevxExp(ListRev lis, int cod);

/* Precondición: lista NO vacía */
void RevxEvaluacion(ListRev lis, int &Satis, int &inComp, int &Pend);

void Bajar_Lista (ListRev lis , String nomArch);

/*Precondicion: Debe existir el archivo*/
void Levantar_Lista (ListRev &lis, String nomArch);
