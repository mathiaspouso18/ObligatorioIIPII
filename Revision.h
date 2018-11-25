#ifndef REVISION_H_INCLUDED
#define REVISION_H_INCLUDED
#include "Fecha.h"
#include "String.h"
#include "Evaluacion.h"

typedef struct {Fecha fecRea;
                        String descripcion;
                        int codigoExp;
                        Evaluacion eval;}Revision ;

#endif // REVISION_H_INCLUDED
