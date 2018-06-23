#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\Queue.h"
#include<assert.h>

/*Har ar det viktigt att ateranvanda koden som du redan skrivit for den lankade listan.
  Ateranvandning betyder inte att man kopierar koden eller skriver av den, ateranvander
  gor man genom att anropa redan implementerade funktioner.*/

/*Funktionen ar fardig*/
Queue initializeQueue(void)
{
    return NULL;
}

int queueIsEmpty(const Queue queue)
{
  if(queue == NULL)
    return 1;
  return 0;
}

/*Postcondition: data ar tillagt sist i kon*/
void enqueue(Queue* queue, const Data data)
{
  addLast(queue, data);
  assert((*queue)->prev->data == data);
   //Tips: Att lagga till i en ko implementerad som en lankad lista ar precis som att lagga till forst eller sist i en lankad lista
}

/* Precondition: kon är ej tom */
void dequeue(Queue* queue)
{
  assert(queue!=NULL);
  removeFirst(queue);
    //Tips: Att ta bort fran en ko implementerad som en lankad lista ar precis som att ta bort sist eller forst i en lankad lista.
}

/* Precondition: kon är ej tom */
Data peekQueue(const Queue queue)
{
    assert(queue!=NULL);
    return queue->data;
}

/* Anvands for testning och felsokning
   Tips: det kan vara bra att ocksa notera i utskriften vart borjan respektive slutet på kon är */
void printQueue(const Queue queue, FILE *textfile)
{
  printList(queue,textfile);
}
