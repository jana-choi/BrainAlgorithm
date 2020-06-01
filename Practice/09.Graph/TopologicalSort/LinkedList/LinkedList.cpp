#include "LinkedList.h"

Node* SLL_CreateNode(Vertex* a_eData)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));

	pNewNode->eData = a_eData;
	pNewNode->pNextNode = NULL;

	return pNewNode;
}

void SLL_DestroyNode(Node* a_pNode)
{
	free(a_pNode);
}

void SLL_AppendNode(Node** a_ppHead, Node* a_pNewNode)
{
	if(*a_ppHead == NULL)
		*a_ppHead = a_pNewNode;
	else
	{
		Node* pTail = *a_ppHead;
		while(pTail->pNextNode != NULL)
			pTail = pTail->pNextNode;
		
		pTail->pNextNode = a_pNewNode;
	}
}

void SLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode)
{
	a_pNewNode->pNextNode = a_pCurrent->pNextNode;
	a_pCurrent->pNextNode = a_pNewNode;
}

void SLL_InsertNewHead(Node** a_ppHead, Node* a_pNewNode)
{
	if(*a_ppHead == NULL)
		*a_ppHead = a_pNewNode;
	else
	{
		a_pNewNode->pNextNode = *a_ppHead;
		*a_ppHead = a_pNewNode;
	}
}

void SLL_RemoveNode(Node** a_ppHead, Node* a_pRemove)
{
	if(*a_ppHead == a_pRemove)
		*a_ppHead = a_pRemove->pNextNode;
	else
	{
		Node* pCurrent = *a_ppHead;
		while(pCurrent != NULL && pCurrent->pNextNode != a_pRemove)
			pCurrent = pCurrent->pNextNode;

		if(pCurrent != NULL)
			pCurrent->pNextNode = a_pRemove->pNextNode;
	}
}

Node* SLL_GetNodeAt(Node* a_pHead, int a_nLocation)
{
	Node* pCurrent = a_pHead;

	while(pCurrent != NULL && --a_nLocation >= 0)
		pCurrent = pCurrent->pNextNode;

	return pCurrent;
}

int SLL_GetNodeCount(Node* a_pHead)
{
	int nCount = 0;
	Node* pCurrent = a_pHead;

	while(pCurrent != NULL)
	{
		pCurrent = pCurrent->pNextNode;
		nCount++;
	}

	return nCount;
}
