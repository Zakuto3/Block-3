#include "C:\Users\Zak\Documents\Atom Projects\dstring\dstring\dstring.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>


DString dstring_initialize(const char* str)
{
	char* tempstr;
	assert(str != NULL); //precondition

	tempstr = malloc(strlen(str)+1);
	if(tempstr==NULL)
 		return 0;
	strcpy(tempstr,str); //copy from arg to dynamic string
	assert(strcmp(str,tempstr)==0);//Postcondition
	return tempstr; //returns dynamic string
}

int dstring_concatenate(DString* destination, DString source)
{
	char tempdest[100];
	assert(destination != NULL);
	assert(*destination != NULL);
	assert(source != NULL);

	strcpy(tempdest, *destination);
	strcat(tempdest,source); //for assert later

	*destination = realloc(*destination,strlen(source)+strlen(*destination)+1);
	if (*destination == NULL)
	{return 0;}
	strcat(*destination,source);
	assert(strcmp(tempdest,*destination)==0);
	return 1;
}

void dstring_truncate(DString* destination, unsigned int truncatedLength)
{
	assert(destination != NULL);
	assert(*destination != NULL);

	if (strlen(*destination)>truncatedLength)
	{
		*destination = realloc(*destination,truncatedLength+1);
		if (*destination == NULL)
		{printf("Failed to allocate memory");}
		(*destination)[truncatedLength] = '\0';//Puts "\0" at the end of string
		assert(strlen(*destination)>=truncatedLength);
	}
}

void dstring_print(DString str, FILE* textfile)
{
	assert(textfile != NULL);
	fprintf(textfile, "%s\n", str);
}

void dstring_delete(DString* stringToDelete)
{
	assert(stringToDelete != NULL);
	free(*stringToDelete);
	*stringToDelete = NULL;
	assert(*stringToDelete == NULL);
}
