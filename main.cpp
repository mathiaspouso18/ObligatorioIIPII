#include "ABBExpediente.h"

using namespace std;

int main()
{
    Arbol ABB;
    Expediente ex;
    int cod;
    InicializarArbol(ABB);

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

    //Agregar la creacion de la revision. Validar fecha y codigo.
}
