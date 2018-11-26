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

Fecha DarFecha(Revision rev);

String DarDesc(Revision rev);

int DarCodExp(Revision rev);

Evaluacion DarEv(Revision rev);

#endif // REVISION_H_INCLUDED
