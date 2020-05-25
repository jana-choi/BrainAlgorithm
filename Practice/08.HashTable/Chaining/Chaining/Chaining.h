#ifndef _CHAINING_H_
#define _CHAINING_H_

#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode
{
	KeyType		Key;
	ValueType	Value;

	struct tagNode*	Next;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int		TableSize;
	List*	Table;
} HashTable;



HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);

Node* CHT_CreateNode(const char* Key, const char* Value);
void CHT_DestroyNode(Node* TheNode);

void CHT_Set(HashTable* HT, const char* Key, const char* Value);
ValueType CHT_Get(HashTable* HT, const char* Key);
int CHT_Hash(const char* Key, int KeyLength, int TableSize);

#endif	// _CHAINING_H_
