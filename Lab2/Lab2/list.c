#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\list.h"
#include <stdlib.h>
#include <assert.h>

/*Hjalpfunktion till add
  Allokerar minne for en ny nod
  om allokeringen lyckades initieras data samt pekare (pekare initieras till NULL).
  Den nya noden (eller NULL) returneras.*/
static struct node* createListNode(const Data data) //Done
{
    List list = malloc(sizeof(struct node)); //creates struct node for alloc mem
    if (list==NULL) {
        printf("ERROR in allocation of memory");
    }
    (*list).data=data; //puts arg into union data
    return list;
}

/*Returnera en tom lista - funktionen ar fardig*/
List createEmptyList(void) //done
{
    return NULL;
}


/*Ar listan tom?
  Returnerar 1 om den Šr tom, annars 0*/
int isEmpty(const List list)//done
{
    if(list==NULL)
    return 1;
  return 0;
}

/*Lagg till nod forst i listan*/
/*Postcondition: Det nya datat ligger forst i listan (testa med assert)*/
void addFirst(List *list, const Data data) //done
{
    List newnode;
    newnode = createListNode(data);

    if (isEmpty(*list)==1)//creates a node that points on itself, inital node.
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        *list = newnode;
    }
    else
    {
        newnode->prev = (*list)->prev;//adds current head's prev to newnode's prev
        (*list)->prev->next = newnode;//last node points to head
        (*list)->prev = newnode;//adds current head's prev to newnode
        newnode->next = *list;//connects newnode's next to old head

        *list = newnode; //new head
    }
}

/*Lagg till nod sist i listan
  Tips, nar du hittat ratt plats kan du anvanda funktionen addFirst for att lagga till*/
void addLast(List *list, const Data data) //done
{
   if(isEmpty(*list)==1){
       addFirst(list, data);
   }
   else{
       List newnode;
       newnode = createListNode(data);
       (*list)->prev->next = newnode;//assign last node's next pointer to new node
       newnode->prev = (*list)->prev;
       newnode->next = *list;
       (*list)->prev = newnode;//adds new node to last in list
   }
}

/*Ta bort forsta noden i listan
  Precondition: listan ar inte tom (testa med assert)
  Noden ska lankas ur och minnet frigoras, resten av listan ska finnas kvar*/
void removeFirst(List *list)
{
   assert(*list != NULL);
   List toRemove = *list;
   if ((*list)->prev == toRemove->prev->prev)//checks if its the last node
   {
      free(*list); //free's head
      *list=createEmptyList();
   }
   else
   {
      (*list)->prev->next = toRemove->next;//assign adjacent pointers to eachother
      (*list)->next->prev = toRemove->prev;
      *list = toRemove->next; //assign new head
      free(toRemove);
      toRemove=NULL;
   }
}

/*Ta bort sista noden i listan
  Precondition: listan ar inte tom (testa med assert)t*/
void removeLast(List *list)
{
   //removeFirst(&(*list)->prev);
   assert(*list != NULL);
   List toRemove = (*list)->prev; //point to last spot
   if (toRemove->prev == toRemove->prev->prev)//checks if its the last node
   {
      free(*list); //free's head
      *list=createEmptyList();
   }
   else
   {
      toRemove->prev->next = toRemove->next;//assign adjacent pointers to eachother
      toRemove->next->prev = toRemove->prev;
      free(toRemove);
      toRemove=NULL;
   }
}

/*Ta bort data ur listan (forsta forekomsten)
  Returnera 1 om datat finns, annars 0
  Tips, nar du hittar ratt nod kan du anvanda en av de ovanstaende funktionerna for att ta bort noden*/
int removeElement(List *list, const Data data)
{
   if (isEmpty(*list))
   {
      printf("List is Empty");
      return 0; //Ersatt med ratt returvarde
   }

   List current = *list;
   do
   {
      if (!(current->data==data))//if data not found, go to next node
      {
         current=current->next;
      }
      else if(current == *list)//if first node is choosen
      {
         removeFirst(list);
         return 1;
      }
      else
      {
         removeLast(&current->next);
         return 1;
      }
   }
   while (*list != current);//ends at the last node
   return 0;
}

/*Finns data i listan?
  Om datat finns returneras 1, annars 0
  Tank pa att listan kan vara tom*/
int search(const List list, const Data data)
{
   if (!isEmpty(list)==1) //kollar om listan är tom, im ja notera användare
  {
     List current = list; //current är en pekare till list som vi kan jobba med
    do
    {
      if (current->data==data)//if data found
      {
         return 1;
      }
      current=current->next;
    }
    while (list != current);//ends at the last node
   }
 return 0;
}

//EXAMINATION
void addBefore(List *list, const Data newData, const Data insertBeforeData)
{
  if (*list != NULL) //medans list inte är NULL
 {
    List current = *list; //current är en pekare till list som vi kan jobba med och endå behålla HEAD med *list
   do
   {
     if (current->data==insertBeforeData)//om data är funnen
     {
        addLast(&current,newData); //add last funktionen anropas, detta funkar pga cirkulär länkning
        break; //break ur while, ta bort denna break och newData kommer sättas bakom alla insertBeforeData,
     }
     current=current->next; //hoppa till nästa node
   }
   while (*list != current);//slutar söka igenom när vi har gått hela varvet runt listan
 }
 printf("%d not found in list ", insertBeforeData);//om inte funnen, orsak kan också vara att listan är tom, båda fall printas ut
}

/*Returnera antalet noder i listan*/
int numberOfNodesInList(const List list) //done
{
   if (isEmpty(list))
      return 0;
      int amount = 0;
      List current = list;
      do
      {
         amount++;
         current=current->next;
      }
      while (list != current);
      return amount;
}

/*Ta bort alla noder ur listan
  Glom inte att frigora minnet
  Postcondition: Listan ar tom, *list Šr NULL (testa med assert)*/
void clearList(List *list)
{
   if (!isEmpty(*list)==1)
   {
      int i,num;
      num = numberOfNodesInList(*list);
      for (i = 0; i < num; i++)
      {
         removeFirst(list);
      }
      assert(list != NULL);
   }
}

/*Skriv ut listan
  Vid anropet kan man ange stdout som argument 2 for att skriva ut pŒ skarmen.
  Anvanda fprintf for att skriva ut.
  Den har typen av utskriftfunktion blir mer generell da man kan valja att skriva ut till skarmen eller till fil.*/
void printList(const List list, FILE *textfile)
{
    if (isEmpty(list))
    {
        printf("List is Empty");
    }
    else
    {
      List current = list;
     do
     {
         fprintf(textfile, "[%d]", (*current).data);
         current=current->next;
     }
     while (list != current->next->prev);//ends at the last node
    }
}

/*Returnera forsta datat i listan
  Precondition: listan ar inte tom (testa med assert)*/
Data getFirstElement(const List list)
{
   assert(list != NULL);
    return list->data;
}

/*Returnera sista datat i listan
  Precondition: listan ar inte tom (testa med assert)*/
Data getLastElement(const List list)
{
   assert(list != NULL);
    return list->prev->data;
}
