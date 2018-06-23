#include <stdlib.h>
#include <stdio.h>
void menu();
/* Tar två char pekare, skickar sista bokstaven i första strängen till
första plats i andra strängen. detta skär i reverse när den "returnar" tillbaka */
void reverse(char *input,char *Rev,int *i)
{
  if (*input) //basfall, där vilkoren blir falsk då det är slutet på strängen (\0)
  {
      reverse(input+1,Rev,i);//ändringsfaktorn är att vi skickar in input strängen med ett steg fram i index
      Rev[*i]=input[0]; //vid "return" så sätter vi från slutet av input strängen i ordning till reverse strängen.
      *i=*i+1; //int pekare för att hålla koll vart vi ska sätta bostäverna i reverse strängen
  }
    Rev[*i] ='\0'; //manuelt sätta dit vart slutet ska vara på reverse strängen. det följer inte med pga vår IF
}


int main()
{
  menu();
  return 0;
}


void menu()
{
  int run = 1;
  char* a = NULL; //allokeras minne när det behövs
  char* b = NULL;
  int i=0; //koll på index
  int* index = &i;

  while (run)
  {
    char userchoice;
    printf("Meny: \n\tTryck 1-3\n\t[1]Give a string\n\t[2]Reverse the string\n\t[3]print string\n");
    scanf("%c",&userchoice);
    fflush(stdin);

    switch (userchoice)
    {
      case '1': //tar emot en sträng från användaren
        a = malloc(50); //dynamisk allokerad minne för strängen
        printf("\nWrite string: ");
        gets(a);
        printf("%s", a);
        break;

      case '2': //kallar på funktionen för reverse
        b = malloc(50);//dynamisk allokerad minne för strängen
        reverse(a,b,index);
        break;

      case '3': //visar resultat
        if (a != NULL) //visar inget om ingen minne har blivit allokerad
        {
          printf("unreversed: %s\n",a);
          *index = 0;
        }
        if (b != NULL)
        {
          printf("reversed: %s\n",b);
        }
        break;
      case '4':
        free(a); free(b);//släpper minnet
        a = NULL; b = NULL;
        run=0;
        break;
      default:
        printf("Error, Try again...\n");
        break;
    }
  }
}
