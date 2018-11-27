#include "Fecha.h"
#include "Boolean.h"

int DarDia(Fecha f)
{
    return f.dia;
}

int DarMes(Fecha f)
{
    return f.mes;
}

int DarAnio(Fecha f)
{
    return f.anio;
}

void CargaFecha(Fecha &f)
{
    Fecha f2;

    printf("\tIngrese dia: ");
    scanf("%d", &f2.dia);
    printf("\tIngrese mes: ");
    scanf("%d", &f2.mes);
    printf("\tIngrese anio: ");
    scanf("%d", &f2.anio);

    while(!EsValida(f2))
    {
        printf("\tLa fecha ingresada no es valida! Ingrese nuevamente\n\n");
        printf("\tIngrese dia: ");
        scanf("%d", &f2.dia);
        printf("\tIngrese mes: ");
        scanf("%d", &f2.mes);
        printf("\tIngrese anio: ");
        scanf("%d", &f2.anio);
    }
    f = f2;
}

void DesplegarFecha(Fecha f)
{
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

Boolean EsValida(Fecha f)
{
    Boolean esValida = FALSE, esBisiesto = FALSE;

    switch(DarMes(f))
    {
        case 1:case 3:
        case 5:case 7:
        case 8:case 10:case 12:
            {
                if(DarDia(f) <= 31)
                    esValida = TRUE;
            }
            break;
        case 4: case 6: case 9: case 11:
            {
                if(DarDia(f) <= 30)
                    esValida = TRUE;
            }
            break;
        case 2:
            {

                if(DarAnio(f) % 4 == 0)
                    esBisiesto = TRUE;

                if(esBisiesto)
                {
                    if(DarDia(f) <= 29)
                        esValida = TRUE;
                }
                else
                {
                    if(DarDia(f) <= 28)
                        esValida = TRUE;
                }
            }
            break;
        default:
            esValida = FALSE;
            break;
    }
    return esValida;
}
