#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType a_eNewData)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	pNewNode->eData = a_eNewData;
	pNewNode->pPrevNode = NULL;
	pNewNode->pNextNode = NULL;

	return pNewNode;
}

void CDLL_DestroyNode(Node* a_pNode)
{
	free(a_pNode);
}

void CDLL_AppendNode(Node** a_ppHead, Node* a_pNewNode)
{
	if(*a_ppHead == NULL)
	{
		*a_ppHead = a_pNewNode;
		(*a_ppHead)->pNextNode = *a_ppHead;
		(*a_ppHead)->pPrevNode = *a_ppHead;
	}
	else
	{
		Node* pTail = (*a_ppHead)->pPrevNode;
		
		pTail->pNextNode->pPrevNode = a_pNewNode;
		pTail->pNextNode = a_pNewNode;

		a_pNewNode->pNextNode = *a_ppHead;
		a_pNewNode->pPrevNode = pTail;
	}
}

void CDLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode)
{
	a_pNewNode->pNextNode = a_pCurrent->pNextNode;
	a_pNewNode->pPrevNode = a_pCurrent;

	a_pCurrent->pNextNode->pPrevNode = a_pNewNode;
	a_pCurrent->pNextNode = a_pNewNode;
}

void CDLL_RemoveNode(Node** a_ppHead, Node* a_pRemove)
{
	if(*a_ppHead == a_pRemove)
	{
		(*a_ppHead)->pPrevNode->pNextNode = a_pRemove->pNextNode;
		(*a_ppHead)->pNextNode->pPrevNode = a_pRemove->pPrevNode;

		*a_ppHead = a_pRemove->pNextNode;
	}
	else
	{
		Node* pTemp = a_pRemove;

		a_pRemove->pPrevNode->pNextNode = pTemp->pNextNode;
		a_pRemove->pNextNode->pPrevNode = pTemp->pPrevNode;
	}

	a_pRemove->pPrevNode = NULL;
	a_pRemove->pNextNode = NULL;
}

Node* CDLL_GetNodeAt(Node* a_pHead, int a_nLocation)
{
	Node* pCurrent = a_pHead;

	while(pCurrent != NULL && (--a_nLocation) >= 0)
		pCurrent = pCurrent->pNextNode;

	return pCurrent;
}

int CDLL_GetNodeCount(Node* a_pHead)
{
	unsigned int count = 0;
	Node* pCurrent = a_pHead;

	while(pCurrent != NULL)
	{
		pCurrent = pCurrent->pNextNode;
		count++;

		if(pCurrent == a_pHead)
			break;
	}

	return count;
}
