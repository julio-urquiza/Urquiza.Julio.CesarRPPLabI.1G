#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Validaciòn.h"
#include "LinkedList.h"
#include "controller.h"

int opciones(void);

int main()
{
    LinkedList* lista=ll_newLinkedList();
    LinkedList* pArrayListFilterGravedad3=NULL;
    LinkedList* pArrayListFilterGravedadMayorA7=NULL;
    LinkedList* pArrayListFilterGravedadEntre4y7=NULL;
    LinkedList* pArrayListFilterGravedadMenorA3=NULL;

    int seguir=1;
    do{
        switch(opciones())
        {
            case 1://Leer Log:
                system("cls");
                controller_loadFromText(lista);
                break;
            case 2://Procesar información:
                system("cls");
                controller_processInformation(lista,
                                              pArrayListFilterGravedad3,
                                              pArrayListFilterGravedadMayorA7,
                                              pArrayListFilterGravedadEntre4y7,
                                              pArrayListFilterGravedadMenorA3);
                break;
            case 3://Mostrar estadísticas:
                system("cls");
                //controller_listLogs(pArrayListFilterGravedad3);
                //controller_listLogs(pArrayListFilterGravedadMayorA7);
                controller_listLogs(pArrayListFilterGravedadEntre4y7);
                //controller_listLogs(pArrayListFilterGravedadMenorA3);
                break;
            case 4://Imprimir lista logs:
                system("cls");
                controller_listLogs(lista);
                break;
            case 5://Salir
                system("cls");
                ll_deleteLinkedList(lista);
                ll_deleteLinkedList(pArrayListFilterGravedad3);
                ll_deleteLinkedList(pArrayListFilterGravedadMayorA7);
                ll_deleteLinkedList(pArrayListFilterGravedadEntre4y7);
                ll_deleteLinkedList(pArrayListFilterGravedadMenorA3);
                seguir=0;
                break;
            default:
                system("cls");
                printf("opcion invalida\n");
                break;
        }
        system("pause");
    }while(seguir);
    return 0;
}
int opciones(void)
{
    int numero;
    system("cls");
    printf("1.Leer Log\n");
    printf("2.Procesar informacion\n");
    printf("3.Mostrar estadisticas\n");
    printf("4.Imprimir lista logs\n");
    printf("5.Salir\n");

    pedirNumeroSinLimite(&numero,"Ingrese un numero: ","ERROR,");
    return numero;
}

