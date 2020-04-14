#include "DoublyLinkedList.h"

Node* DLL_CreateNode(ElementType a_eNewData)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	pNewNode->eData = a_eNewData;
	pNewNode->pPrevNode = NULL;
	pNewNode->pNextNode = NULL;

	return pNewNode;
}

void DLL_DestroyNode(Node* a_pNode)
{
	free(a_pNode);
}

void DLL_AppendNode(Node** a_ppHead, Node* a_pNewNode)
{
	if(*a_ppHead == NULL)
		*a_ppHead = a_pNewNode;
	else
	{
		Node* pTail = *a_ppHead;
		while(pTail->pNextNode != NULL)
			pTail = pTail->pNextNode;

		pTail->pNextNode = a_pNewNode;
		a_pNewNode->pPrevNode = pTail;
	}
}

void DLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode)
{
	a_pNewNode->pNextNode = a_pCurrent->pNextNode;
	a_pNewNode->pPrevNode = a_pCurrent;

	if(a_pCurrent->pNextNode != NULL)
		a_pCurrent->pNextNode->pPrevNode = a_pNewNode;

	a_pCurrent->pNextNode = a_pNewNode;
}

void DLL_RemoveNode(Node** a_ppHead, Node* a_pRemove)
{
	if(*a_ppHead == a_pRemove)
	{
		*a_ppHead = a_pRemove->pNextNode;
		if(*a_ppHead != NULL)
			(*a_ppHead)->pPrevNode = NULL;
	}
	else
	{
		Node* pTemp = a_pRemove;

		if(a_pRemove->pPrevNode != NULL)
			a_pRemove->pPrevNode->pNextNode = pTemp->pNextNode;

		if(a_pRemove->pNextNode != NULL)
			a_pRemove->pNextNode->pPrevNode = pTemp->pPrevNode;
	}

	a_pRemove->pPrevNode = NULL;
	a_pRemove->pNextNode = NULL;
}

Node* DLL_GetNodeAt(Node* a_pHead, int a_nLocation)
{
	Node* pCurrent = a_pHead;

	while(pCurrent != NULL && (--a_nLocation) >= 0)
		pCurrent = pCurrent->pNextNode;

	return pCurrent;
}

int DLL_GetNodeCount(Node* a_pHead)
{
	unsigned int count = 0;
	Node* pCurrent = a_pHead;
	
	while(pCurrent != NULL)
	{
		pCurrent = pCurrent->pNextNode;
		count++;
	}

	return count;
}
