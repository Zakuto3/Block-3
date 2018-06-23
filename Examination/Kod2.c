KOD2
Lab 2 så valde jag att jobba med cirkulär dubbel länkade listor. Jag tror att det underlätta uppgiften för mig.
för uppgiften så kommer jag använda en uppgift som jag redan hade skrivit vid lab2, nämligen addLast, om det inte var
ok att använda tidigare funktioner så skulle jag nog endå skriva en hjälpfunktion som är identisk till addLast.

olika fall:
om listan är tom så händer inget och "VARIABEL could not be found in list, list is empty." då print funktionen printar om listan är tomd
Om noden ska länkas först så länkas den först o blir nya head.
om sist så länkas den sist då addLast var redan designad för detta.
om mitt i så kommer addBefore skicka insertBeforeData noden till addLast, addlast tolkar det som head och kommer sätta nya noden innan HEAD
då den tror där tail ligger, detta tog använde jag till att sätta före insertBeforeData noden.

Addbefore funktionen kommer söka igenom listan om det finns en lista. om rätt data hittas så anropas addlast. addBefore Kommer
att fortsätta söka tills vi är tillbaka till HEAD.


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


void addLast(List *list, const Data data) //done
{
   if(isEmpty(*list)==1){ //om listan är tom, kallar på addfirst, detta sker inte i detta fall då den anropas inte om listan är tom
       addFirst(list, data);
   }
   else{
       List newnode;
       newnode = createListNode(data); //skapar ny node
       (*list)->prev->next = newnode;//föregånde node's next pekar på nya noden.
       newnode->prev = (*list)->prev; //insertBeforeData prev är nyaNode prev, för att inte tappa länking
       newnode->next = *list; //Noden framför nya noden är nu vår insertBeforeData noden.
       (*list)->prev = newnode;//Noden bakom insertBeforeData noden är nu vår nya Node,
   }
}

//denna funktion kommer inte anvädas i detta fall, men includerar det för övrigt(anropas i addlast)
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


ANROP:
case 13:
      //CALL EXAMINATION HERE
      printf("Data to add: ");
      scanf("%d%*c", &data);
      printf("Data of add Before: ");
      scanf("%d%*c", &data2);
      addBefore(&head,data,data2);
      printf("List: ");
      printList(head, stdout);
      break;
