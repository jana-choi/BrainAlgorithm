#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** a_ppStack, int a_nCapacity)
{
	(*a_ppStack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*a_ppStack)->pNodes = (Node*)malloc(sizeof(Node) * a_nCapacity);

	(*a_ppStack)->nCapacity = a_nCapacity;
	(*a_ppStack)->nTop = 0;
}

void AS_DestroyStack(ArrayStack* a_pStack)
{
	free(a_pStack->pNodes);
	free(a_pStack);
}

void AS_Push(ArrayStack* a_pStack, ElementType a_eData)
{
	int nPosition = a_pStack->nTop;
	a_pStack->pNodes[nPosition].eData = a_eData;
	a_pStack->nTop++;
}

ElementType AS_Pop(ArrayStack* a_pStack)
{
	int nPosition = --(a_pStack->nTop);
	return a_pStack->pNodes[nPosition].eData;
}

ElementType AS_Top(ArrayStack* a_pStack)
{
	int nPosition = a_pStack->nTop - 1;
	return a_pStack->pNodes[nPosition].eData;
}

int AS_GetSize(ArrayStack* a_pStack)
{
	return a_pStack->nTop;
}

int AS_IsEmpty(ArrayStack* a_pStack)
{
	return (a_pStack->nTop == 0);
}
