#include "CircularDoublyLinkedList.h"

int main(void)
{
	int i = 0;
	int count = 0;
	Node* pList = NULL;
	Node* pCurrent = NULL;
	Node* pNewNode = NULL;

	for(i = 0; i < 5; i++)
	{
		pNewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&pList, pNewNode);
	}

	count = CDLL_GetNodeCount(pList);
	for(i = 0; i < count; i++)
	{
		pCurrent = CDLL_GetNodeAt(pList, i);
		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nInserting 3000 After [2] ... \n\n");

	pCurrent = CDLL_GetNodeAt(pList, 2);
	pNewNode = CDLL_CreateNode(3000);

	CDLL_InsertAfter(pCurrent, pNewNode);

	count = CDLL_GetNodeCount(pList);
	for(i = 0; i < count * 2; i++)
	{
		if(i == 0)
			pCurrent = pList;
		else
			pCurrent = pCurrent->pNextNode;

		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nDestroying List ... \n\n");

	for(i = 0; i < count; i++)
	{
		pCurrent = CDLL_GetNodeAt(pList, 0);
		if(pCurrent != NULL)
		{
			CDLL_RemoveNode(&pList, pCurrent);
			CDLL_DestroyNode(pCurrent);
		}
	}

	return 0;
}