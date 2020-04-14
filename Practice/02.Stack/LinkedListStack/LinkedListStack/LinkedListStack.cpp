#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** a_ppStack)
{
	(*a_ppStack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*a_ppStack)->pList = NULL;
	(*a_ppStack)->pTop = NULL;
}

void LLS_DestroyStack(LinkedListStack* a_pStack)
{
	while(!LLS_IsEmpty(a_pStack))
	{
		Node* pPopped = LLS_Pop(a_pStack);
		LLS_DestroyNode(pPopped);
	}
	free(a_pStack);
}

Node* LLS_CreasteNode(const char* a_pData)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	
	pNewNode->pData = (char*)malloc(sizeof(a_pData) + 1);
	strcpy_s(pNewNode->pData, sizeof(a_pData), a_pData);

	pNewNode->pNextNode = NULL;

	return pNewNode;
}

void LLS_DestroyNode(Node* a_pNode)
{
	free(a_pNode->pData);
	free(a_pNode);
}

void LLS_Push(LinkedListStack* a_pStack, Node* a_pNode)
{
	if(a_pStack->pList == NULL)
	{
		a_pStack->pList = a_pNode;
	}
	else
	{
		Node* pOldTop = a_pStack->pList;
		while(pOldTop->pNextNode != NULL)
			pOldTop = pOldTop->pNextNode;

		pOldTop->pNextNode = a_pNode;
	}

	a_pStack->pTop = a_pNode;
}

Node* LLS_Pop(LinkedListStack* a_pStack)
{
	Node* pTopNode = a_pStack->pTop;

	if(a_pStack->pList == a_pStack->pTop)
	{
		a_pStack->pList = NULL;
		a_pStack->pTop = NULL;
	}
	else
	{
		Node* pCurrentTop = a_pStack->pList;
		while(pCurrentTop != NULL && pCurrentTop->pNextNode != a_pStack->pTop)
			pCurrentTop = pCurrentTop->pNextNode;

		a_pStack->pTop = pCurrentTop;
		pCurrentTop->pNextNode = NULL;
	}

	return pTopNode;
}

Node* LLS_Top(LinkedListStack* a_pStack)
{
	return a_pStack->pTop;
}

int LLS_GetSize(LinkedListStack* a_pStack)
{
	int nCount = 0;
	Node* pCurrent = a_pStack->pList;

	while(pCurrent)
	{
		pCurrent = pCurrent->pNextNode;
		nCount++;
	}

	return nCount;
}

int LLS_IsEmpty(LinkedListStack* a_pStack)
{
	return (a_pStack->pList == NULL);
}
