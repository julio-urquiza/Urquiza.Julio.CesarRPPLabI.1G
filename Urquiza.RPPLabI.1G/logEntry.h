#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED

struct S_LogEntry
{
char date[11];
char time[6];
char serviceName[65];
int gravedad;
char msg[65];
};
typedef struct S_LogEntry LogEntry;

#endif // LOGENTRY_H_INCLUDED
LogEntry* logEntry_new();
LogEntry* logEntry_newParametros(char* date,char* time,char* serviceName,int gravedad,char* msg);
int logEntry_setDate(LogEntry* log,char* date);
int logEntry_getDate(LogEntry* log,char* date);
int logEntry_setTime(LogEntry* log,char* time);
int logEntry_getTime(LogEntry* log,char* time);
int logEntry_setServiceName(LogEntry* log,char* serviceName);
int logEntry_getServiceName(LogEntry* log,char* serviceName);
int logEntry_setMsg(LogEntry* log,char* msg);
int logEntry_getMsg(LogEntry* log,char* msg);
int logEntry_setGravedad(LogEntry* log,int gravedad);
int logEntry_getGravedad(LogEntry* log,int* gravedad);
int LogEntry_ListLog(LogEntry* log);
int LogEntry_filtrarGravedad3(void* log);
int LogEntry_filtrarGravedadEntre4y7(void* log);
int LogEntry_filtrarGravedadMayorA7(void* log);
int LogEntry_filtrarGravedadMenorA3(void* log);
