#include <stdlib.h>
#include <stdio.h>
void menu();
/* Tar tv� char pekare, skickar sista bokstaven i f�rsta str�ngen till
f�rsta plats i andra str�ngen. detta sk�r i reverse n�r den "returnar" tillbaka */
void reverse(char *input,char *Rev,int *i)
{
  if (*input) //basfall, d�r vilkoren blir falsk d� det �r slutet p� str�ngen (\0)
  {
      reverse(input+1,Rev,i);//�ndringsfaktorn �r att vi skickar in input str�ngen med ett steg fram i index
      Rev[*i]=input[0]; //vid "return" s� s�tter vi fr�n slutet av input str�ngen i ordning till reverse str�ngen.
      *i=*i+1; //int pekare f�r att h�lla koll vart vi ska s�tta bost�verna i reverse str�ngen
  }
    Rev[*i] ='\0'; //manuelt s�tta dit vart slutet ska vara p� reverse str�ngen. det f�ljer inte med pga v�r IF
}


int main()
{
  menu();
  return 0;
}


void menu()
{
  int run = 1;
  char* a = NULL; //allokeras minne n�r det beh�vs
  char* b = NULL;
  int i=0; //koll p� index
  int* index = &i;

  while (run)
  {
    char userchoice;
    printf("Meny: \n\tTryck 1-3\n\t[1]Give a string\n\t[2]Reverse the string\n\t[3]print string\n");
    scanf("%c",&userchoice);
    fflush(stdin);

    switch (userchoice)
    {
      case '1': //tar emot en str�ng fr�n anv�ndaren
        a = malloc(50); //dynamisk allokerad minne f�r str�ngen
        printf("\nWrite string: ");
        gets(a);
        printf("%s", a);
        break;

      case '2': //kallar p� funktionen f�r reverse
        b = malloc(50);//dynamisk allokerad minne f�r str�ngen
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
        free(a); free(b);//sl�pper minnet
        a = NULL; b = NULL;
        run=0;
        break;
      default:
        printf("Error, Try again...\n");
        break;
    }
  }
}
