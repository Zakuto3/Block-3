

#include <stdio.h>
#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\list.h"
#include "C:\Users\Zak\Documents\Atom Projects\block3\Lab2\Lab2\list.c"
#include <assert.h>

/*Denna kan du anvanda for att testa specifika funktioner
 (du far givetvis skriva en egen menyfunktion om du vill det)*/
void menu(List head);

/*Kors programmet felfritt genom denna funktion sa fungerar det som specificerat (observera att utskriften maste testas manuellt.
  OBS! Innan alla funktioner är implementerade sa kommer exekveringen fastna i olika asserts*/
void testFunction(List head);


int main(void)
{
    List head = createEmptyList(); /*head ska hela tiden peka på borjan av din lista, om listan ar tom ska head peka pa NULL */

    /*Kommentera eller avkommentera beroende pa om det ar menyn eller testfunktionen som ska koras*/
    testFunction(head);
    menu(head);


    return 0;
}

void menu(List head)
{
    int choice;
    Data data,data2;
    char c; //Anvands endast for att rensa lasbufferten

    do
    {
        printf("\n\n--------------MENU--------------\n"
               "1 - Print list\n"
               "2 - Add data first in list\n"
               "3 - Add data last in list\n"
               "4 - Remove first node in list\n"
               "5 - Remove last node in list\n"
               "6 - Remove data in list\n"
               "7 - Number of nodes in list\n"
               "8 - Is the list empty?\n"
               "9 - Get first element in list\n"
               "10 - Get last element in list\n"
               "11 - Search in list\n"
               "12 - Clear list (removes all nodes)\n"
               "13 - EXAMINATION: AddBefore Data\n"
               "14 - End program\n"
               "-----------------------------------\n"
               "Choice: ");

        scanf("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF); //Rensar lasbufferten

        switch(choice)
        {
            case 1: printf("List: ");
                    printList(head, stdout); break;

            case 2: printf("Data to add first: ");
                    scanf("%d%*c", &data);
                    addFirst(&head, data);
                    printf("List: ");
                    printList(head, stdout);
                    printf("\nCURRENT HEAD: %d\n",(*head).data );
                    break;

            case 3: printf("Data to add last: ");
                    scanf("%d%*c", &data);
                    addLast(&head, data);
                    printf("List: ");
                    printList(head, stdout);
                    break;

            case 4: removeFirst(&head);
                    printf("First node removed\n");
                    printf("List: ");
                    printList(head, stdout);
                    break;

            case 5: removeLast(&head);
                    printf("Last node removed\n");
                    printf("List: ");
                    printList(head, stdout);
                    break;

            case 6: printf("Data to remove: ");
                    scanf("%d%*c", &data);
                    if(removeElement(&head, data) == 1)
                        printf("First occurance of node with data %d is removed\n", data);
                    else
                        printf("No node with data %d\n", data);
                    printf("List: ");
                    printList(head, stdout);
                    break;

            case 7: printf("Number of nodes in list: %d\n", numberOfNodesInList(head)); break;

            case 8: if(isEmpty(head) == 1)
                        printf("The list is empty\n");
                    else
                        printf("The list is not empty\n");
                    break;

            case 9: printf("First element: %d\n", getFirstElement(head)); break;

            case 10: printf("Last element: %d\n", getLastElement(head)); break;

            case 11: printf("Data to search for: ");
                scanf("%d", &data);
                if(search(head, data) == 1)
                {
                    printf("%d found in list ", data);
                    printList(head, stdout);
                }
                else
                {
                    printf("%d not found in list ", data);
                    printList(head, stdout);
                }
                break;

            case 12: clearList(&head); break;
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
            case 14: printf("\nEnding program");

            default: printf("\nWrong input");
        }
    }while(choice != 14);
}

void testFunction(List head)
{
    assert(isEmpty(head)); //Listan ska vara tom fran borjan
    //Testar addFirst
    addFirst(&head, 6);
    addFirst(&head, 5);
    addFirst(&head, 4);
    addFirst(&head, 3);
    addFirst(&head, 2);
    assert(numberOfNodesInList(head) == 5);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 6);

    //Testar addLast
    addLast(&head, 7);
    addLast(&head, 8);
    assert(numberOfNodesInList(head) == 7);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 8);

    //Testar removeFirst
    removeFirst(&head);
    assert(numberOfNodesInList(head) == 6);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 8);

    //Testar removeLast
    removeLast(&head);
    assert(numberOfNodesInList(head) == 5);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 7);

    //Testar att ta bort en nod i mitten av listan
    removeElement(&head, 5);
    assert(numberOfNodesInList(head) == 4);
    assert(getFirstElement(head) == 3);
    assert(getLastElement(head) == 7);

    //Testar att ta bort forsta noden med removeElement
    removeElement(&head, 3);
    assert(numberOfNodesInList(head) == 3);
    assert(getFirstElement(head) == 4);
    assert(getLastElement(head) == 7);

    //Testar att ta bort sista noden med removeElement
    removeElement(&head, 7);
    assert(numberOfNodesInList(head) == 2);
    assert(getFirstElement(head) == 4);
    assert(getLastElement(head) == 6);

    assert(!isEmpty(head)); //Listan ska inte vara tom (4 och 6 ar kvar i listan)

    //Testar att ta bort ett ensamt element med removeElement
    removeElement(&head, 6);
    assert(numberOfNodesInList(head) == 1);
    assert(getFirstElement(head) == 4);
    removeElement(&head, 4);
    assert(isEmpty(head)); //Listan ska nu vara tom

    //Testar att lagga till data till en tomd lista
    addFirst(&head, 5);
    addFirst(&head, 4);
    addFirst(&head, 3);
    addFirst(&head, 2);
    assert(numberOfNodesInList(head) == 4);
    assert(getFirstElement(head) == 2);
    assert(getLastElement(head) == 5);

    //Testar search (mitt i, forst, sist, data som inte finns)
    assert(search(head, 4) == 1);
    assert(search(head, 2) == 1);
    assert(search(head, 5) == 1);
    assert(search(head, 7) == 0);

    //Testar att tomma hela listan
    clearList(&head);
    assert(isEmpty(head));

    //Testar att soka i en tom lista
    assert(search(head, 5) == 0);

    printf("Congratulations!\nYour program passed the test\n");
}
