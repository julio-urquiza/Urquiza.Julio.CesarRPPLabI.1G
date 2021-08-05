/*******************************************************************
*Division:1g
*Alumno:Julio Cesar Urquiza
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/** \brief pide un int al usuario y comprueba que sea un numero entero que este entre los datos ingresados
 *
 * \param pResultado int* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \param maximo int valor màximo que puede ingresar el usuario
 * \param minimo int valor mìnimo que puede ingresar el usuario
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumero(int* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo);

/** \brief pide un int al usuario y comprueba que sea un numero entero
 *
 * \param pResultado int* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumeroSinLimite(int* pResultado,char* mensaje,char* mensajeError);

/** \brief pide un float al usuario y comprueba que sea un numero flotante que este entre los datos ingresados
 *
 * \param pResultado float* variable por referencia donde se almacenarà el numero
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \param maximo int valor màximo que puede ingresar el usuario
 * \param minimo int valor mìnimo que puede ingresar el usuario
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirNumeroComa(float* pResultado,char* mensaje,char* mensajeError,int maximo,int minimo);

/** \brief pide un string al usuario y comprueba que sea una cadena de caracteres
 *
 * \param pResultado int* variable por referencia donde se almacenarà la cadena
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirTexto(char* pTexto,char* mensaje,char* mensajeError);

/** \brief pide un string al usuario y comprueba que sea una cadena ya sea de caracteres con numeros o solo una con letras
 *
 * \param pResultado int* variable por referencia donde se almacenarà la cadena
 * \param mensaje char* mensaje que verà el usuario, que le indicarà que hacer
 * \param mensajeError char* mensaje que verà el usuario en caso de equivocarse
 * \return int retorna -1 si no pudo completar la tarea en caso de que la complete regresa 1
 */
int pedirTextoConNumeros(char* pTexto,char* mensaje,char* mensajeError);

int opcionSwitch(char* mensaje,char* mensajeError,int minimo,int maximo);

int opcion(char* mensaje,char* mensajeError);

int pedirUnaLetra(char* pCaracter,char* mensaje,char* mensajeError);
