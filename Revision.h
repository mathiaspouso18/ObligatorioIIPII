#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED
#include "Fecha.h"
#include "String.h"
#include "Evaluacion.h"

typedef struct {Fecha fecRea;
                String descripcion;
                int codigoExp;
                Evaluacion eval;
               }Revision ;

void CrearRevision(Revision &r, int cod, Fecha f);

Fecha DarFecha(Revision rev);

void DarDesc(Revision rev, String &desc);

int DarCodExpEnRev(Revision rev);

Evaluacion DarEv(Revision rev);

void Bajar_Revision(Revision rev, FILE * f);

void Levantar_Revision(Revision &rev, FILE * f);

#endif // REVISION_H_INCLUDED
