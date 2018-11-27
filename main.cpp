#include "ABBExpediente.h"
#include "Menu.h"

using namespace std;

int main()
{
    Arbol ABB;
    Expediente ex;
    int cod, opcion;
    InicializarArbol(ABB);
    
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
                    printf("El expediente ya existe!");
                }
            break;
        }

    }while(opcion != 0);

    opcion = -1;//limpio la variable dejandola en -1;
}
