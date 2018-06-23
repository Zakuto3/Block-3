#ifndef BUCKET_H
#define BUCKET_H
#include "C:\Users\Zak\Documents\Atom Projects\block3\lab 4\HashTable\Person.h"

typedef Person Value;
typedef int Key;

struct Bucket
{
	Key key;
	Value value;
};

#endif
