#include "ABBExpediente.h"
#include "ListaRevision.h"
#include "Menu.h"

int main()
{
    Arbol ABB;
	ListRev Lis;
    Expediente ex;
	Revision rev;
    int cod, opcion, Satis, inComp, Pend, cantExp;
	String ape;
	Fecha f;
    InicializarArbol(ABB);
	Levantar_ABB (ABB, "Expedientes.dat");
	Crear(Lis);
	Levantar_Lista (Lis, "Revisiones.dat");

    do
    {
        MenuPrincipal(opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
                if(!ExisteExp(cod, ABB))
                {
                    CrearExpediente(ex, cod);
                    InsertarNodo(ABB, ex);
                }
                else
                {
                    printf("\n\nEl expediente ya existe!");//Deberia volver al case 2?
                }
            break;
			case 2:
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
				printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
				if(ExisteExp(cod, ABB))
                {
					Borrar (ABB, cod);
					BorrarRev(Lis, cod);
                }
                else
                {
                    printf("El expediente no existe!");//Deberia volver al case 3?
                }
			break;
			case 4:
				ListarExp(ABB);
			break;
			case 5:
				ListarRev(Lis);
			break;
			case 6:
				ListarMinMax(ABB);
			break;
			case 7:
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
						printf("No se encontraron revisiones para dicho expediente");
					}
				}
                else
                {
                    printf("El expediente no existe!");
                }
			break;
			case 8:
				printf("Ingrese el apellido del escribano: ");
                scan(ape);
				cantExp = ExpxEscribano(ABB, ape);
				if(cantExp > 0)
				{
					printf("La cantidad de expedientes realizados por dicho escribano es de: %d", cantExp);
				}
				else
				{
					printf("No se encontraron expedientes para dicho escribano");
				}
			break;
			case 11:
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

    opcion = -1;//limpio la variable dejandola en -1;

	Bajar_ABB (ABB, "Expedientes.dat");
	Bajar_Lista (Lis , "Revisiones.dat");
}
