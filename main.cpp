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
                    printf("El expediente ya existe!");//Deberia volver al case 2?
                }
            break;
			case 2:
				printf("Ingrese codigo del expediente: ");
                scanf("%d", &cod);
				if(ExisteExp(cod, ABB))
                {
					CargarFecha(f);
					if(EsValidaSis(Lis, f)){
						CrearRevision(rev, cod, f);
						InsFront (Lis, rev);
					}
					else
					{
						printf("La fecha es menor a la de la ultima revisión ingresada");//Deberia volver al case 2?
					}
                }
                else
                {
                    printf("El expediente no existe!");//Deberia volver al case 2?
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
        }

    }while(opcion != 0);

    opcion = -1;//limpio la variable dejandola en -1;
}
