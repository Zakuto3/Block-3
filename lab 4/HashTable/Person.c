#define _CRT_SECURE_NO_WARNINGS // Behovs i Visual studio for att tillata vissa funktioner
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 4\HashTable\Person.h"
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static void getRandomName(char* name)
{
	assert(name != NULL);

	char* names[] = { "Stefan", "Anna" , "Bengt", "Sture", "Johan", "Therese", "Alva", "Lisa", "Emma", "Linnea", "Lena", "Johanna",
		"Moa", "Per", "Alex", "Fredrik", "Kent", "Tobias", "Malin", "Sara", "Ida", "Hanna", "Sixten", "Birger" };

	const int numberOfNames = sizeof(names) / sizeof(char*);
	int index = rand() % numberOfNames;
	strcpy(name, names[index]);
}

static int getRandomPersonalNumber(void)
{
	int day = rand() % 30 + 1; // For enkelhetens skull antar vi att vaje manad har 30 dagar (blir vissa omojliga datum i februari, men det ar inte viktigt har)
	int month = rand() % 12 + 1;
	int year = rand() % 60 + 40;
	return day + 100 * month + 10000 * year;
}

Person getRandomPerson(void)
{
	Person randomPerson;
	getRandomName(randomPerson.name);
	randomPerson.personalNumber = getRandomPersonalNumber();
	randomPerson.weight = (float)(rand() % 70 + 50);
	return randomPerson;
}

void printPerson(Person* personToPrint)
{
	printf("%d: %s, weight: %f \n", personToPrint->personalNumber, personToPrint->name, personToPrint->weight);
}
