#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType eData;
} Node;

typedef struct tagArrayStack
{
	int nCapacity;
	int nTop;
	Node* pNodes;
} ArrayStack;


void AS_CreateStack(ArrayStack** a_ppStack, int a_nCapacity);
void AS_DestroyStack(ArrayStack* a_pStack);
void AS_Push(ArrayStack* a_pStack, ElementType a_eData);
ElementType AS_Pop(ArrayStack* a_pStack);
ElementType AS_Top(ArrayStack* a_pStack);
int AS_GetSize(ArrayStack* a_pStack);
int AS_IsEmpty(ArrayStack* a_pStack);

#endif	// !_ARRAYSTACK_H_