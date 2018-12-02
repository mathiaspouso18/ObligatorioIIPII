#include "Fecha.h"

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

void CargarFecha(Fecha &f)
{
    Fecha f2;

    printf("Ingrese dia: ");
    scanf("%d", &f2.dia);
    printf("Ingrese mes: ");
    scanf("%d", &f2.mes);
    printf("Ingrese anio: ");
    scanf("%d", &f2.anio);

    while(!EsValida(f2))
    {
        printf("La fecha ingresada no es valida! Ingrese nuevamente\n\n");
        printf("Ingrese dia: ");
        scanf("%d", &f2.dia);
        printf("Ingrese mes: ");
        scanf("%d", &f2.mes);
        printf("Ingrese anio: ");
        scanf("%d", &f2.anio);
    }
    f = f2;
}

void DesplegarFecha(Fecha f)
{
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

void LlenarFecha(Fecha &f, int dia, int mes, int anio)
{
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
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

Boolean MenorIgualFecha(Fecha f1, Fecha f2)
{
Boolean menorigual = FALSE;

    if (f1.anio < f2.anio)
        menorigual = TRUE;
    else
    {
        if (f1.anio == f2.anio)
        {
            if (f1.mes < f2.mes)
                menorigual = TRUE;
            else
            {
                if (f1.mes == f2.mes)
                {
                    if (f1.dia <= f2.dia)
                        menorigual = TRUE;
                }
            }
        }
    }
    return menorigual;
}

Boolean MayorIgualFecha(Fecha f1, Fecha f2)
{
Boolean mayorigual = FALSE;
    if (f1.anio > f2.anio)
        mayorigual = TRUE;
    else
    {
        if (f1.anio == f2.anio)
        {
            if (f1.mes > f2.mes)
                mayorigual = TRUE;
            else
            {
                if (f1.mes == f2.mes)
                {
                    if (f1.dia >= f2.dia)
                        mayorigual = TRUE;
                }
            }
        }
    }
return mayorigual;
}
