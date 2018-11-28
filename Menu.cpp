#include "Menu.h"

void MenuPrincipal(int &opcion)
{
    printf("\t\n\t");
    printf("Menu Principal");
    printf("\n\n\t");
    printf("1 - Ingresar nuevo expediente");
    printf("\n\t");
    printf("2 - Registrar nueva revision");
    printf("\n\t");
    printf("3 - Borrar expediente del sistema");
    printf("\n\t");
    printf("4 - Listar todos los expedientes registrados en el sistema");
    printf("\n\t");
    printf("5 - Listar todas las revisiones realizadas");
    printf("\n\t");
    printf("6 - Listar los datos del expediente con mayor codigo y del expediente con menor codigo");
    printf("\n\t");
    printf("7 - Listar todas las revisiones correspondientes a un expediente");
    printf("\n\t");
    printf("8 - Dado un apellido, contar cuantos expedientes coordinados hizo");
    printf("\n\t");
    printf("9 - Obtener el codigo del expediente con la mayor cantidad de revisiones");
    printf("\n\t");
    printf("10 - Dadas dos fechas, contar cuantas revisiones fueron realizadas dentro de dicho rango de fechas");
    printf("\n\t");
    printf("11 - Calcular cuantas revisiones de cada tipo hay registradas en el sistema");
    printf("\n\t");
    printf("0 - Salir ");
    printf("\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
}
