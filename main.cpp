#include "ABBExpediente.h"
#include "Menu.h"
#include <stdlib.h>

int main()
{
    Arbol ABB;
	ListRev Lis;
    Expediente ex;
	Revision rev;
    int cod, opcion, Satis, inComp, Pend, cantExp;
	String ape;
	Fecha f,f1,f2;
    InicializarArbol(ABB);
	InicializarLista(Lis);

    if(fopen("Expedientes.dat", "rb")== NULL)
        fopen("Expedientes.dat", "wb");
    else
        Levantar_ABB (ABB, "Expedientes.dat");

	if(fopen("Revisiones.dat", "rb")== NULL)
        fopen("Revisiones.dat", "wb");
    else
        Levantar_Lista (Lis, "Revisiones.dat");

    do
    {
        MenuPrincipal(opcion);

        system("cls");

        switch(opcion)
        {
            case 1:
                printf("Pantalla Ingreso de expedientes\n\n");
                printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
                if(!ExisteExp(cod, ABB))
                {
                    CrearExpediente(ex, cod);
                    InsertarNodo(ABB, ex);
                }
                else
                {
                    printf("\nEl expediente ya existe!\n");
                }
            break;
			case 2:
			    printf("Pantalla Ingreso de revisiones\n\n");
				printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
				if(ExisteExp(cod, ABB))
                {
					CargarFecha(f);
					if(!EsVaciaLis(Lis))
                    {
                        if(EsValidaSis(Lis, f))
                        {
                            CrearRevision(rev, cod, f);
                            InsFront (Lis, rev);
                        }
                        else
                        {
                            printf("La fecha es menor a la de la ultima revision ingresada");
                        }
					}
					else
                    {
                        CrearRevision(rev, cod, f);
                        InsFront (Lis, rev);
                    }
                }
                else
                {
                    printf("El expediente no existe!");
                }
			break;
			case 3:
			    printf("Pantalla Eliminacion de expedientes\n");
				printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
				if(ExisteExp(cod, ABB))
                {
					Borrar (ABB, cod);
					BorrarRev(Lis, cod);
                }
                else
                {
                    printf("El expediente no existe!");
                }
			break;
			case 4:
			    printf("Pantalla Listado de expedientes\n\n");
				ListarExp(ABB,TRUE);
			break;
			case 5:
			    printf("Pantalla Listado de revisiones\n\n");
				ListarRev(Lis,TRUE);
			break;
			case 6:
			    printf("Pantalla expediente con mayor codigo y expediente con menor codigo\n\n");
				ListarMinMax(ABB);
			break;
			case 7:
			    printf("Pantalla Listado de revisiones por expediente\n\n");
				printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
				if(ExisteExp(cod, ABB))
                {
					if(TieneRev (Lis, cod))
					{
						ListarRevxExp(Lis, cod);
					}
					else
					{
						printf("\nNo se encontraron revisiones para dicho expediente\n");
					}
				}
                else
                {
                    printf("\nEl expediente no existe!\n");
                }
			break;
			case 8:
			    printf("Pantalla Conteo de expedientes por escribano\n\n");
				printf("Ingrese el apellido del escribano: ");
                scan(ape);
				cantExp = ExpxEscribano(ABB, ape);
				if(cantExp > 0)
				{
					printf("\nLa cantidad de expedientes realizados por dicho escribano es de: %d\n", cantExp);
				}
				else
				{
					printf("\nNo se encontraron expedientes para dicho escribano!\n");
				}
			break;
			case 9:
			    printf("Pantalla Codigo expediente con mas Revisiones\n\n");
			    printf("Codigo expediente con mas Revisiones: %d\n",ExpConMasRev(ABB,Lis,0,0));
            break;
			case 10:
			    printf("Pantalla Conteo de revisiones entre fechas\n\n");
			    printf("Ingrese primer fecha\n\n");
                CargarFecha(f1);
                printf("\nIngrese segunda fecha\n\n");
                CargarFecha(f2);
                if (MenorIgualFecha(f1,f2))
                    printf("\nCantidad de revisiones: %d\n", CantRevEntreFec(Lis,f1,f2));
                else
                    printf("\nRango de fechas incorrecto!\n");
            break;
			case 11:
			    printf("Pantalla Conteo de revisiones por tipo de evaluacion\n\n");
				if(!EsVaciaLis(Lis))
				{
					RevxEvaluacion(Lis, Satis, inComp, Pend);
					printf("\nSatisfactorias: %d | Incompletas: %d | Pendientes: %d",Satis,inComp,Pend);
				}
				else
				{
					printf("No existen revisiones ingresadas en el sistema");
				}
			break;
        }

    }while(opcion != 0);

    printf("ADIOS!\n");

    opcion = -1;//limpio la variable dejandola en -1;

	Bajar_ABB (ABB, "Expedientes.dat");
	Bajar_Lista (Lis , "Revisiones.dat");
}
