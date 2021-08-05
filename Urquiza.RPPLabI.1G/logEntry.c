#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logEntry.h"

LogEntry* logEntry_new()
{
    LogEntry* log=NULL;

    log = (LogEntry*)malloc(sizeof(LogEntry));

    return log;

}

LogEntry* logEntry_newParametros(char* date,char* time,char* serviceName,int gravedad,char* msg)
{
    LogEntry* logRetorno=NULL;
    LogEntry* aux;

    aux = logEntry_new();
    if(aux!=NULL)
    {
        if(logEntry_setDate(aux,date)&&
           logEntry_setTime(aux,time)&&
           logEntry_setServiceName(aux,serviceName)&&
           logEntry_setGravedad(aux,gravedad)&&
           logEntry_setMsg(aux,msg))
        {
            logRetorno=aux;
        }
    }

    return logRetorno;
}

int logEntry_setDate(LogEntry* log,char* date)
{
    int returnValue=-1;
    if(log!= NULL && date!=NULL)
    {
        strcpy(log->date,date);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_getDate(LogEntry* log,char* date)
{
    int returnValue=-1;
    if(log!= NULL && date!=NULL)
    {
        strcpy(date,log->date);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_setTime(LogEntry* log,char* time)
{
    int returnValue=-1;
    if(log!= NULL && time!=NULL)
    {
        strcpy(log->time,time);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_getTime(LogEntry* log,char* time)
{
    int returnValue=-1;
    if(log!= NULL && time!=NULL)
    {
        strcpy(time,log->time);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_setServiceName(LogEntry* log,char* serviceName)
{
    int returnValue=-1;
    if(log!= NULL && serviceName!=NULL)
    {
        strcpy(log->serviceName,serviceName);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_getServiceName(LogEntry* log,char* serviceName)
{
    int returnValue=-1;
    if(log!= NULL && serviceName!=NULL)
    {
        strcpy(serviceName,log->serviceName);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_setMsg(LogEntry* log,char* msg)
{
    int returnValue=-1;
    if(log!= NULL && msg!=NULL)
    {
        strcpy(log->msg,msg);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_getMsg(LogEntry* log,char* msg)
{
    int returnValue=-1;
    if(log!= NULL && msg!=NULL)
    {
        strcpy(msg,log->msg);
        returnValue=1;
    }
    return returnValue;
}

int logEntry_setGravedad(LogEntry* log,int gravedad)
{
    int returnValue=-1;
    if(log!= NULL)
    {
        log->gravedad=gravedad;
        returnValue=1;
    }
    return returnValue;
}

int logEntry_getGravedad(LogEntry* log,int* gravedad)
{
    int returnValue=-1;
    if(log!= NULL && gravedad!=NULL)
    {
        *gravedad=log->gravedad;
        returnValue=1;
    }
    return returnValue;
}

int LogEntry_ListLog(LogEntry* log)
{
    int retorno=0;
    char date[11];
    char time[6];
    char serviceName[65];
    int gravedad;
    char msg[65];

    if(log!=NULL)
    {
        if(logEntry_getDate(log,date)&&
           logEntry_getTime(log,time)&&
           logEntry_getServiceName(log,serviceName)&&
           logEntry_getGravedad(log,&gravedad)&&
           logEntry_getMsg(log,msg))
           {
                printf("%20s%20s%30s%10d%30s\n",date,time,serviceName,gravedad,msg);
                retorno=1;
           }
    }
    return retorno;
}

int LogEntry_filtrarGravedad3(void* log)
{
    int retorno=0;
    LogEntry* logAux;
    if(log!=NULL)
    {
        logAux=(LogEntry*)log;
        if(logAux->gravedad==3)
        {
            retorno=1;
        }
    }
    return retorno;
}

int LogEntry_filtrarGravedadEntre4y7(void* log)
{
    int retorno=0;
    LogEntry* logAux;
    if(log!=NULL)
    {
        logAux=(LogEntry*)log;
        if(logAux->gravedad>4 && logAux->gravedad<7)
        {
            retorno=1;
        }
    }
    return retorno;
}

int LogEntry_filtrarGravedadMayorA7(void* log)
{
    int retorno=0;
    LogEntry* logAux;
    if(log!=NULL)
    {
        logAux=(LogEntry*)log;
        if(logAux->gravedad>7)
        {
            retorno=1;
        }
    }
    return retorno;
}

int LogEntry_filtrarGravedadMenorA3(void* log)
{
    int retorno=0;
    LogEntry* logAux;
    if(log!=NULL)
    {
        logAux=(LogEntry*)log;
        if(logAux->gravedad<3)
        {
            retorno=1;
        }
    }
    return retorno;
}













