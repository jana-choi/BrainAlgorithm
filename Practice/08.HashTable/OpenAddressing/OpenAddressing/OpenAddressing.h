#ifndef _OPEN_ADDRESSING_H_
#define _OPEN_ADDRESSING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)


typedef char*	KeyType;
typedef char*	ValueType;

enum ElementStatus
{
	EMPTY		= 0,
	OCCUPIED	= 1,
};

typedef struct tagElementType
{
	KeyType		Key;
	ValueType	Value;

	enum ElementStatus	Status;
} ElementType;

typedef struct tagHashTable
{
	int		OccupiedCount;
	int		TableSize;

	ElementType* Table;
} HashTable;


HashTable* OAHT_CreateHashTable(int TableSize);
void OAHT_DestroyHashTable(HashTable* HT);
void OAHT_ClearElement(ElementType* Element);

void OAHT_Set(HashTable** HT, const char* Key, const char* Value);
ValueType OAHT_Get(HashTable* HT, const char* Key);
int OAHT_Hash(const char* Key, int KeyLength, int TableSize);
int OAHT_Hash2(const char* Key, int KeyLength, int TableSize);

void OAHT_Rehash(HashTable** HT);

#endif	// _OPEN_ADDRESSING_H_
