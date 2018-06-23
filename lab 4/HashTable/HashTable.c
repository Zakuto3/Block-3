#define _CRT_SECURE_NO_WARNINGS // Behovs for vissa funktioner i visual studio
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 4\HashTable\HashTable.h"
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 4\HashTable\Bucket.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define UNUSED 0	// Anvands for att markera en ledig plats i Hashtabellen


/* Denna funktion tar en nyckel och returnerar ett hash-index
dvs ett index till arrayen som �r Hashtabellen */
static int hash(Key key, int tablesize)
{
	return key%tablesize; // Key(Personal nr) Modulus the size of the array gives index nr.
}

HashTable createHashTable(unsigned int size)
{
	HashTable htable;
	htable.table = calloc(size, sizeof(struct Bucket)); //allocates dynamic memmory
	if (htable.table==NULL) //If allocation failed
	{
		printf("Memory allocation for Table Failed");
	}
	htable.size = size; //update current size
	int i;

	for (i = 0; i < size; i++) //makes sure all key value is set to zero for "unused" slot
	{
		htable.table[i].key = UNUSED;
	}
	return htable;
}

static int findSlot(const HashTable* htable, const Key key)
{
	int i, z = 1, index = hash(key, (*htable).size);

	for (i = 0; i < htable->size; i++)//goes through the whole "Bucket"
 	{
		if(htable->table[index].key == UNUSED && htable->table[index].key == key) //if slot is used, go to rehash a new index
		{
			index = hash(key+z, (*htable).size);//rehashing, notice "+z"
			z++;
		}
	}
	return index;
}

/* Satter in paret {key,data} i Hashtabellen, om en nyckel redan finns ska vardet uppdateras */
void insertElement(HashTable* htable, const Key key, const Value value)
{
	int index = findSlot(htable, key); //with findSlot function, gives index a valid slot number.
	htable->table[index].key = key;
	htable->table[index].value = value;

	assert(lookup(htable,key)!=NULL);
	// Postcondition: det finns ett element for key i tabellen (anvand lookup() for att verifiera)
}

/* Tar bort datat med nyckel "key" */
void deleteElement(HashTable* htable, const Key key)
{
 	int index = findSlot(htable, key); //gives index a valid slot
	if(htable->table[index].key != key)
	{
		printf("Could not find element\n");
	}
	else
	{
		htable->table[index].key = UNUSED; //renders the current index useless
		int size=htable->size,i=1;

		struct Bucket temp;
		while (htable->table[index+i%size].key != UNUSED)//goes on untill we find an unused slot
	 	{
			temp = htable->table[index+i%size]; //puts next index in temp
			htable->table[index+i%size].key = UNUSED; //next index is set as unused
			insertElement(htable, temp.key, temp.value); //moves the temp into the deleteElement's location
			i++;
		}
	}
	assert(lookup(htable,key)==NULL);
	// Postcondition: inget element med key finns i tabellen (anvand loookup() for att verifiera)
}

/* Returnerar en pekare till vardet som key ar associerat med eller NULL om ingen sadan nyckel finns */
const Value* lookup(const HashTable* htable, const Key key)
{
	int index = findSlot(htable, key); //give the searched index
	if (htable->table[index].key == key)//if the key matches
 	{
		return &(htable->table[index].value);
	}
	else
	{
		return NULL;
	}
}

/* Tommer Hashtabellen */
void freeHashTable(HashTable* htable)
{
	htable->size=0;
	free(htable->table);
	assert(htable->size == 0);
	(*htable).table = NULL;
	// Postcondition: hashtabellen har storlek 0
}

/* Ger storleken av Hashtabellen */
unsigned int getSize(const HashTable* htable)
{
	return htable->size;
}

/* Denna for att ni enkelt ska kunna visualisera en Hashtabell */
void printHashTable(const HashTable* htable)
{
	int i;
	for (i = 0; i < htable->size; i++)
	{
		if(htable->table[i].key != UNUSED)
		{
			printPerson(&(htable->table[i].value));
	 	}
	}
	// Tips: anvand printPerson() i Person.h for att skriva ut en person
}
