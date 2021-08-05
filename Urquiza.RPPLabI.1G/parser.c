#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "logEntry.h"

int parser_logFromText(FILE* pFile, LinkedList* pArrayList)
{
    int r;
    char date[11];
    char time[6];
    char serviceName[65];
    int gravedad;
    char msg[65];
    LogEntry* aux;
    if(pArrayList!=NULL && pFile!=NULL)
    {
        do{
            r = fscanf(pFile,"%[^;];%[^;];%[^;];%d;%[^\n]\n",date,time,serviceName,&gravedad,msg);
            if(r==5)
            {
                aux=logEntry_newParametros(date,time,serviceName,gravedad,msg);
                ll_add(pArrayList,aux);
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }

    return 1;
}

int parser_saveAsText(FILE* pFile,LinkedList* pArrayList)
{
    int retorno=0;
    int len;
    char date[11];
    char time[6];
    char serviceName[65];
    int gravedad;
    char msg[65];
    LogEntry* aux;

    if(pArrayList!=NULL && pFile!=NULL)
    {
        len=ll_len(pArrayList);
        printf("Cantidad de elementos guardados: %d\n",len);
        for(int i=0;i<len;i++)
        {
            aux=ll_get(pArrayList,i);
            if(logEntry_getDate(aux,date)&&
              logEntry_getTime(aux,time)&&
              logEntry_getServiceName(aux,serviceName)&&
              logEntry_getGravedad(aux,&gravedad)&&
              logEntry_getMsg(aux,msg))
            {
                fprintf(pFile,"%s;%s;%s;%d;%s\n",date,time,serviceName,gravedad,msg);
            }
        }
        retorno=1;
    }
    return retorno;
}
