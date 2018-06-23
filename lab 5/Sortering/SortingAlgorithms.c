#define _CRT_SECURE_NO_WARNINGS
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 5\Sortering\SortingAlgorithms.h"
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 5\Sortering\Statistics.h"
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 5\Sortering\Array.h"
#include <assert.h>
#include <string.h>
#include <math.h>

int isImplemented(SortingAlgorithm algorithm)
{
	switch (algorithm)
	{
     		case BUBBLE_SORT:
    		case INSERTION_SORT:
//      case SELECTION_SORT:
      	case QUICK_SORT:
//      case MERGE_SORT:
            return 1;
        default:
            return 0;
	}
}

/*void quicksorting( int *number,int first,int last, Statistics* statistics){
   int i, j, pivot, temp;

   if(lessThan(first,last,statistics)){
      pivot=first;
      i=first;
      j=last;

      while(lessThan(i,j,statistics)){
         while(lessThanOrEqualTo(number[i],number[pivot],statistics) && lessThan(i,last,statistics))
            i++;
         while(greaterThan(number[j],number[pivot],statistics))
            j--;
         if(lessThan(i,j,statistics)){
           swapElements(&number[i],&number[j],statistics);
            //temp=number[i];
            //number[i]=number[j];
            //number[j]=temp;
         }
      }

      //swapElements(number[pivot],number[j],statistics);
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksorting(number,first,j-1,statistics);
      quicksorting(number,j+1,last,statistics);

   }
}*/
/******************************************************************************************/
/* Era algoritmer har: */

static void bubbleSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
	int i,step,temp;

	for(step=0;lessThan(step,size-1,statistics);++step)//step controlls how far into the array to stort
	{
		for(i=0;lessThan(i,size-step-1,statistics);++i) //first run step is 0, runts trough whole array. then one less etc
		{
			if(greaterThan(arrayToSort[i],arrayToSort[i+1],statistics))   /* To sort in descending order, change > to < in this line. */
			{
			swapElements(&arrayToSort[i],&arrayToSort[i+1],statistics);
			//temp=arrayToSort[i];
			//arrayToSort[i]=arrayToSort[i+1];
			//arrayToSort[i+1]=temp;
			}
		}
	}
}
/*static void insertionSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
	int i, key, j;
	//ElementType temp[1] = {0};
	//begin at second element then goes through the whole array
	for (i = 0; lessThan(i,size,statistics); i++)
	{
		//key = arrayToSort[i]; //key is the next element to find its sorted place
		j = i;
		//first compare the two elements. then goes trough
		greaterThanOrEqualTo(j,0,statistics); //crashes when this is inside while
		while (j >= 0 && greaterThan(arrayToSort[j-1], arrayToSort[j],statistics))
		{
			swapElements(&arrayToSort[j],&arrayToSort[j-1],statistics);
			//arrayToSort[j+1] = arrayToSort[j];//shots forward the whole sorted array until index with lessthan key position is found
			--j;
		}
		//swapElements(&temp[0],&temp[0],statistics);
		//arrayToSort[j+1] = key; //inserts key to correct position
	}
}*/
static void insertionSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
	int i, key, j;
	ElementType temp[1] = {0};
	//begin at second element then goes through the whole array
	for (i = 0; lessThan(i,size,statistics); i++)
	{
		key = arrayToSort[i]; //key is the next element to find its sorted place
		j = i-1;
		//first compare the two elements. then goes trough
		greaterThanOrEqualTo(j,0,statistics); //crashes when this is inside while
		while (j >= 0 && greaterThan(arrayToSort[j], key,statistics))
		{
			swapElements(&temp[0],&temp[0],statistics);
			arrayToSort[j+1] = arrayToSort[j];//shots forward the whole sorted array until index with lessthan key position is found
			--j;
		}
		//swapElements(&temp[0],&temp[0],statistics);
		arrayToSort[j+1] = key; //inserts key to correct position
	}
}

static void selectionSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
}

static void mergeSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
}

static void quickSort(ElementType* arrayToSort, size_t size, Statistics* statistics)
{
  quicksort(arrayToSort, 0, size-1, statistics);
}
void quicksort(ElementType* number,int first,int last, Statistics* statistics){
   int i, j, pivot, temp;
	 int pivotx = ceil(first + (last-first)/2);

	 lessThan(first,last,statistics);//crash when this is in if
   if(first<last){
      pivot=pivotx;
      i=first;
      j=last;

      while(lessThan(i,j,statistics)){
				//gemför från väntersida med pivot tills ett större tal hittas.
         while(lessThanOrEqualTo(number[i],number[pivot],statistics) && lessThan(i,last,statistics))
            i++;
						//gemför från höger sida med pivot tills mindre tal hittas, flyttar fram "wall"
         while(greaterThan(number[j],number[pivot],statistics))
            j--;
         if(lessThan(i,j,statistics)){
					 //swichar de talen som hittades eller ett steg framför "wall"
					 swapElements(&number[i],&number[j],statistics);
         }
      }
			//sätter pivot på sin "plats" där allt på vänter sida är mindre
			swapElements(&number[pivot],&number[j],statistics); //not needed if pivot is last

      quicksort(number,first,j-1, statistics); //sorterar vänter sida först med pivot
      quicksort(number,j+1,last, statistics); //sedan höger sida med pivot
   }
}

/******************************************************************************************/


char* getAlgorithmName(SortingAlgorithm algorithm)
{
	/* Ar inte strangen vi allokerar lokal for funktionen?
	   Nej, inte i detta fall. Strangkonstanter ar ett speciallfall i C */
	switch (algorithm)
	{
        case BUBBLE_SORT:	 return "  Bubble sort ";
        case SELECTION_SORT: return "Selection sort";
        case INSERTION_SORT: return "Insertion sort";
        case MERGE_SORT:	 return "  Merge sort  ";
        case QUICK_SORT:	 return "  Quick sort  ";
        default: assert(0 && "Ogiltig algoritm!"); return "";
	}
}

// Sorterar 'arrayToSort' med 'algorithmToUse'. Statistik for antal byten och jamforelser hamnar i *statistics
static void sortArray(ElementType* arrayToSort, size_t size, SortingAlgorithm algorithmToUse, Statistics* statistics)
{
	if(statistics != NULL)
		resetStatistics(statistics);

	switch (algorithmToUse)
	{
	case BUBBLE_SORT:	 bubbleSort(arrayToSort, size, statistics); break;
	case SELECTION_SORT: selectionSort(arrayToSort, size, statistics); break;
	case INSERTION_SORT: insertionSort(arrayToSort, size, statistics); break;
	case MERGE_SORT:	 mergeSort(arrayToSort, size, statistics); break;
	case QUICK_SORT:	 quickSort(arrayToSort, size, statistics); break;
	default:
		assert(0 && "Ogiltig algoritm!");
	}
}

// Forbereder arrayer for sortering genom att allokera minne for dem, samt intialisera dem
static void prepareArrays(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], const unsigned int sizes[])
{
	assert(isImplemented(algorithm));

	int i;
	int totalArraySize;

	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		totalArraySize = sizeof(ElementType)*sizes[i];
		sortingArray[i].arrayToSort = malloc(totalArraySize);
		memcpy(sortingArray[i].arrayToSort, arrays[i], totalArraySize);

		sortingArray[i].algorithm = algorithm;
		sortingArray[i].arraySize = sizes[i];
		resetStatistics(&sortingArray[i].statistics);
	}
}

// Sorterar arrayerna
static void sortArrays(SortingArray toBeSorted[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		SortingArray* current = &toBeSorted[i];
		sortArray(current->arrayToSort, current->arraySize, current->algorithm, &current->statistics);

		if (!isSorted(current->arrayToSort, current->arraySize))
		{
			printf("Fel! Algoritmen %s har inte sorterat korrekt!\n", getAlgorithmName(current->algorithm));
			printf("Resultatet är: \n");
			printArray(current->arrayToSort, current->arraySize, stdout);
			assert(0); // Aktiveras alltid
		}
	}
}

void printResult(SortingArray sortedArrays[], FILE* file)
{
	assert(file != NULL);

	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		fprintf(file, "%4d element: ", sortedArrays[i].arraySize);
		printStatistics(&sortedArrays[i].statistics, file);
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void sortAndPrint(SortingArray sortingArray[], SortingAlgorithm algorithm, const ElementType* arrays[], unsigned int sizes[], FILE* file)
{
	assert(file != NULL);

	prepareArrays(sortingArray, algorithm, arrays, sizes);
	sortArrays(sortingArray);
	printResult(sortingArray, file);
}

void freeArray(SortingArray sortingArray[])
{
	int i;
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		if (sortingArray[i].arrayToSort != NULL)
			free(sortingArray[i].arrayToSort);
		sortingArray[i].arrayToSort = NULL;
		sortingArray[i].arraySize = 0;
		resetStatistics(&sortingArray[i].statistics);
	}
}
