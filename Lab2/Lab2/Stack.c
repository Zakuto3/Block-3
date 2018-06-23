#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\Stack.h"
#include<assert.h>

/*Funktionen ar fardig*/
Stack initializeStack(void)
{
    return createEmptyList();
}

int stackIsEmpty(const Stack stack)
{
  if (stack==NULL)
    return 1;
  return 0;
}

/* Postcondition 'data' ligger overst pŒ stacken */
void push(Stack* stack, const Data data)//adds data "ontop"
{
  addFirst(stack,data);
  assert((*stack)->data==data);
}

/* Precondition: stacken far inte vara tom */
void pop(Stack* stack)
{
  assert(stack !=NULL);
  removeFirst(stack);
}

/* Precondition: stacken far inte vara tom */
Data peekStack(const Stack stack)
{
  assert(stack !=NULL);
  return stack->data;
}

/* Anvands for testning och felsokning
 Tips: det kan vara bra att ocksa notera i urskriften vart toppen pa stacken ar */
void printStack(const Stack stack, FILE *textFile)
{
  printList(stack,textFile);
}
