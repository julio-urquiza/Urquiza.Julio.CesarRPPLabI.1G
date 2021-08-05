/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include "Validaciòn.h"


static int pedirInt(int* pResultado);
static int pedirFloat(float* pResultado);
static int pedirString(char* pResultado);
static int pedirStringInt(char* pResultado);
static int pedirChar(char* pResultado);
static int myGets(char* cadena,int longitud);
static int esNumerica(char* cadena);
static int esAlfavetico(char* cadena);
static int esAlfaNumerico(char* cadena);
static int esNumeroConComa(char* cadena);
static int esUnaLetra(char* cadena);


static int pedirInt(int* pResultado)
{
   int retorno=-1;
   char buffer[100];
   if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
   {
       retorno=0;
       *pResultado=atoi(buffer);
   }
   return retorno;
}

static int pedirFloat(float* pResultado)
{
   int retorno=-1;
   char buffer[100];
   if(myGets(buffer,sizeof(buffer))==0 && esNumeroConComa(buffer))
   {
       retorno=0;
       *pResultado=atof(buffer);
   }
   return retorno;
}

static int pedirString(char* pResultado)
{
   int retorno=-1;
   char buffer[1000];
   if(myGets(buffer,sizeof(buffer))==0 && esAlfavetico(buffer))
   {
       retorno=0;
       strncpy(pResultado,buffer,1000);
   }
   return retorno;
}

static int pedirStringInt(char* pResultado)
{
   int retorno=-1;
   char buffer[1000];
   if(myGets(buffer,sizeof(buffer))==0 && esAlfaNumerico(buffer))
   {
       retorno=0;
       strncpy(pResultado,buffer,1000);
   }
   return retorno;
}

static int pedirChar(char* pResultado)
{
   int retorno=-1;
   char buffer[1000];
   if(myGets(buffer,sizeof(buffer))==0 && esUnaLetra(buffer) && esAlfavetico(buffer))
   {
       retorno=0;
       *pResultado=buffer[0];
   }
   return retorno;
}

static int myGets(char* cadena,int longitud)
{
    int retorno=-1;
    char bufferString[1000];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
            }
            if(strnlen(bufferString,sizeof(bufferString))<=longitud && strnlen(bufferString,sizeof(bufferString))>0 )
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }
    return retorno;
}

static int esNumerica(char* cadena)
{
    int retorno=1;
    int i=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]>'9'|| cadena[i]<'0')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esAlfavetico(char* cadena)
{
    int retorno=1;
    int i=0;

    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]!=' '&& (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esAlfaNumerico(char* cadena)
{
    int retorno=1;
    int i=0;

    for(;cadena[i]!='\0';i++)
    {

        if(cadena[i]!=' '&& (cadena[i]<'a' || cadena[i]>'z') &&(cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]>'9'|| cadena[i]<'0'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int esNumeroConComa(char* cadena)
{
    int retorno=1;
    int i=0;
    int contadorPuntos=0;

    if(cadena[0]=='-')
    {
        i=1;
    }
    for(;cadena[i]!='\0';i++)
    {
        if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
        {
            continue;
        }
        if((cadena[i]>'9'|| cadena[i]<'0') && cadena[i]!='.')
        {
            if (cadena[i]=='.' && contadorPuntos==0)
            {
                contadorPuntos++;
            }
            else
            {
                retorno=0;
                break;
            }
        }

    }
    return retorno;
}

static int esUnaLetra(char* cadena)
{
    int retorno=1;
    for(int i=0;cadena[i]!='\0';i++)
    {
        if(i==1)
        {
            retorno=0;
            break;
        }

    }
    return retorno;
}
int pedirNumero(int* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo)
{
    int retorno=-1;
    int buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        do{
            printf("%s",mensaje);
            if(pedirInt(&buffer)==0 && buffer >=minimo && buffer <=maximo)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirNumeroSinLimite(int* pResultado,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    int buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirInt(&buffer)==0)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirNumeroComa(float* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo)
{
    int retorno=-1;
    float buffer;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        do{
            printf("%s",mensaje);
            if(pedirFloat(&buffer)==0 && buffer >=minimo && buffer <=maximo)
            {
                *pResultado=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirTexto(char* pTexto,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    char buffer[1000];
    if(pTexto!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirString(buffer)==0)
            {
                strcpy(pTexto,buffer);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int pedirTextoConNumeros(char* pTexto,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    char buffer[1000];
    if(pTexto!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirStringInt(buffer)==0)
            {
                strcpy(pTexto,buffer);
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int opcionSwitch(char* mensaje,char* mensajeError,int minimo,int maximo)
{
    int retorno=-1;
    int buffer;
    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo)
    {
        do{
            printf("%s",mensaje);
            if(pedirInt(&buffer)==0 && buffer >=minimo && buffer <=maximo)
            {
                retorno=buffer;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}

int opcion(char* mensaje,char* mensajeError)
{
    int retorno;
    if(mensaje!=NULL && mensajeError!=NULL)
    {
        pedirNumero(&retorno,mensaje,mensajeError,1,0);
    }
    return retorno;
}

int pedirUnaLetra(char* pCaracter,char* mensaje,char* mensajeError)
{
    int retorno=-1;
    char buffer;
    if(pCaracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            printf("%s",mensaje);
            if(pedirChar(&buffer)==0)
            {
                *pCaracter=buffer;
                retorno=0;
                break;
            }
            printf("%s",mensajeError);
        }while(1);
    }
    return retorno;
}
