/* Laboration 2 - Datastrukturer och Algoritmer */
/* Queue */

#ifndef QUEUE_H
#define QUEUE_H
#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\list.h"    // Din lista inkluderas
/*******************************************************************/
/* Kon ska implementeras som en lankad lista.                      */
/* Du ska anv�nda dina listfunktioner aven i kon                   */
/* Du ska alltsa varken skriva om funktionerna eller kopiera koden */
/* OBS! Du ska inte andra nagonting i interfacet                   */
/* Alla funktioner ska implementeras                               */
/*******************************************************************/

typedef List Queue;  // Ordet 'Queue' kommer att vara din listtyp


/* Skapar en ny tom ko */
Queue initializeQueue(void);

/* Returnerar 1 om kon �r tom, annars 0 */
int queueIsEmpty(const Queue queue);

/* Lagger ett nytt element sist i kon */
void enqueue(Queue* queue, const Data data);

/* Tar bort elementet som ar forst i kon */
void dequeue(Queue* queue);

/* Returnerar elementet som ar forst i kon */
Data peekQueue(const Queue queue);

/*Skriver ut hela kon
  Endast till f�r testning och felsokning */
void printQueue(const Queue queue, FILE *textfile);


#endif
