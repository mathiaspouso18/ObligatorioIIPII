#include "Evaluacion.h"

void MostrarEvaluacion(Evaluacion ev)
{
    switch(ev){
        case Satisfactoria: printf("Satisfactoria"); break;
        case Incompleta: printf("Incompleta");break;
        case Pendiente: printf("Pendiente");
    }
}
