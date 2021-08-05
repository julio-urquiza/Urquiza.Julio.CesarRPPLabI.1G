#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "logEntry.h"
#include "parser.h"

int controller_listLogs(LinkedList* pArrayList)
{
    int retorno=-1;
    int tam;
    if(pArrayList!=NULL && ll_len(pArrayList)>0)
    {
        tam=ll_len(pArrayList);
        printf("Hay %d elementos\n",tam);
        printf("%20s%20s%30s%10s%30s\n","date","time","serviceName","gravedad","msg");
        for(int i=0;i<tam;i++)
        {
            LogEntry_ListLog(ll_get(pArrayList,i));
        }
        retorno=1;
    }
    return retorno;
}

int controller_loadFromText(LinkedList* pArrayList)
{
    int retorno=-1;
    FILE* pFile;
    if(pArrayList!=NULL && ll_len(pArrayList)==0)
    {
        pFile=fopen("log.txt","r");
        if(pFile == NULL)
        {
            printf("El archivo no existe\n");
            exit(EXIT_FAILURE);
        }
        parser_logFromText(pFile,pArrayList);
        printf("\nDatos Cargados con exito\n");
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

int controller_processInformation(  LinkedList* pArrayList,
                                    LinkedList* pArrayListFilterGravedad3,
                                    LinkedList* pArrayListFilterGravedadMayorA7,
                                    LinkedList* pArrayListFilterGravedadEntre4y7,
                                    LinkedList* pArrayListFilterGravedadMenorA3)
{
    FILE* pFile1;
    FILE* pFile2;
    int retorno=0;
    if(pArrayList!=NULL && ll_len(pArrayList)>0 &&
       pArrayListFilterGravedad3!=NULL && pArrayListFilterGravedadMayorA7!=NULL &&
       pArrayListFilterGravedadEntre4y7!=NULL && pArrayListFilterGravedadMenorA3!=NULL)
    {
    printf("hola\n");
        pArrayListFilterGravedad3=ll_filter(pArrayList,LogEntry_filtrarGravedad3);
        if(pArrayListFilterGravedad3!=NULL)
        {
            pFile1=fopen("Warnings.txt","w");
            if(pFile1 == NULL)
            {
                printf("El archivo no existe\n");
                exit(EXIT_FAILURE);
            }
            if(parser_saveAsText(pFile1,pArrayListFilterGravedad3))
            {
                printf("Datos guardados en ""Warnings.txt""\n");
            }
            fclose(pFile1);
        }
        pArrayListFilterGravedadMayorA7=ll_filter(pArrayList,LogEntry_filtrarGravedadMayorA7);
        if(pArrayListFilterGravedadMayorA7!=NULL)
        {
            pFile2=fopen("Archivo Errors.txt","w");
            if(pFile2 == NULL)
            {
                printf("El archivo no existe\n");
                exit(EXIT_FAILURE);
            }
            if(parser_saveAsText(pFile2,pArrayListFilterGravedadMayorA7))
            {
                printf("Datos guardados en ""Archivo Errors.txt""\n");
            }
            fclose(pFile2);
        }
        pArrayListFilterGravedadEntre4y7=ll_filter(pArrayList,LogEntry_filtrarGravedadEntre4y7);
        if(pArrayListFilterGravedadEntre4y7!=NULL)
        {
            controller_listLogs(pArrayListFilterGravedadEntre4y7);
        }
        pArrayListFilterGravedadMenorA3=ll_filter(pArrayList,LogEntry_filtrarGravedadMenorA3);
    }
    return retorno;
}












