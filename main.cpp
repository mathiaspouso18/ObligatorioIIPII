#include "ABBExpediente.h"
#include "ListaRevision.h"
#include "Menu.h"


int main()
{
    Arbol ABB;
	ListRev Lis;
    Expediente ex;
	Revision rev;
    int cod, opcion;
	Fecha f;
    InicializarArbol(ABB);
	Crear(Lis);

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
        }

    }while(opcion != 0);

    opcion = -1;//limpio la variable dejandola en -1;
}
