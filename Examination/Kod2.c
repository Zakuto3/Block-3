KOD2
Lab 2 s� valde jag att jobba med cirkul�r dubbel l�nkade listor. Jag tror att det underl�tta uppgiften f�r mig.
f�r uppgiften s� kommer jag anv�nda en uppgift som jag redan hade skrivit vid lab2, n�mligen addLast, om det inte var
ok att anv�nda tidigare funktioner s� skulle jag nog end� skriva en hj�lpfunktion som �r identisk till addLast.

olika fall:
om listan �r tom s� h�nder inget och "VARIABEL could not be found in list, list is empty." d� print funktionen printar om listan �r tomd
Om noden ska l�nkas f�rst s� l�nkas den f�rst o blir nya head.
om sist s� l�nkas den sist d� addLast var redan designad f�r detta.
om mitt i s� kommer addBefore skicka insertBeforeData noden till addLast, addlast tolkar det som head och kommer s�tta nya noden innan HEAD
d� den tror d�r tail ligger, detta tog anv�nde jag till att s�tta f�re insertBeforeData noden.

Addbefore funktionen kommer s�ka igenom listan om det finns en lista. om r�tt data hittas s� anropas addlast. addBefore Kommer
att forts�tta s�ka tills vi �r tillbaka till HEAD.


//EXAMINATION
void addBefore(List *list, const Data newData, const Data insertBeforeData)
{
  if (*list != NULL) //medans list inte �r NULL
 {
    List current = *list; //current �r en pekare till list som vi kan jobba med och end� beh�lla HEAD med *list
   do
   {
     if (current->data==insertBeforeData)//om data �r funnen
     {
        addLast(&current,newData); //add last funktionen anropas, detta funkar pga cirkul�r l�nkning
        break; //break ur while, ta bort denna break och newData kommer s�ttas bakom alla insertBeforeData,
     }
     current=current->next; //hoppa till n�sta node
   }
   while (*list != current);//slutar s�ka igenom n�r vi har g�tt hela varvet runt listan
 }
 printf("%d not found in list ", insertBeforeData);//om inte funnen, orsak kan ocks� vara att listan �r tom, b�da fall printas ut
}


void addLast(List *list, const Data data) //done
{
   if(isEmpty(*list)==1){ //om listan �r tom, kallar p� addfirst, detta sker inte i detta fall d� den anropas inte om listan �r tom
       addFirst(list, data);
   }
   else{
       List newnode;
       newnode = createListNode(data); //skapar ny node
       (*list)->prev->next = newnode;//f�reg�nde node's next pekar p� nya noden.
       newnode->prev = (*list)->prev; //insertBeforeData prev �r nyaNode prev, f�r att inte tappa l�nking
       newnode->next = *list; //Noden framf�r nya noden �r nu v�r insertBeforeData noden.
       (*list)->prev = newnode;//Noden bakom insertBeforeData noden �r nu v�r nya Node,
   }
}

//denna funktion kommer inte anv�das i detta fall, men includerar det f�r �vrigt(anropas i addlast)
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
