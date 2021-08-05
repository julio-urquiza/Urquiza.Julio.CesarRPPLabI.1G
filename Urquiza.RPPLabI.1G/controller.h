#include "LinkedList.h"
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED
int controller_listLogs(LinkedList* pArrayList);
int controller_loadFromText(LinkedList* pArrayList);
int controller_processInformation(  LinkedList* pArrayList,
                                    LinkedList* pArrayListFilterGravedad3,
                                    LinkedList* pArrayListFilterGravedadMayorA7,
                                    LinkedList* pArrayListFilterGravedadEntre4y7,
                                    LinkedList* pArrayListFilterGravedadMenorA3);
