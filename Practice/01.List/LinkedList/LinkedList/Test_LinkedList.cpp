#include "LinkedList.h"

int main(void)
{
	int i = 0;
	int count = 0;
	Node* pList = NULL;
	Node* pCurrent = NULL;
	Node* pNewNode = NULL;

	for(i = 0; i < 5; i++)
	{
		pNewNode = SLL_CreateNode(i);
		SLL_AppendNode(&pList, pNewNode);
	}

	pNewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&pList, pNewNode);

	pNewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&pList, pNewNode);

	count = SLL_GetNodeCount(pList);
	for(i = 0; i < count; i++)
	{
		pCurrent = SLL_GetNodeAt(pList, i);
		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nInserting 3000 After [2] ... \n\n");

	pCurrent = SLL_GetNodeAt(pList, 2);
	pNewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(pCurrent, pNewNode);

	count = SLL_GetNodeCount(pList);
	for(i = 0; i < count; i++)
	{
		pCurrent = SLL_GetNodeAt(pList, i);
		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nDestroying List ... \n\n");

	for(i = 0; i < count; i++)
	{
		pCurrent = SLL_GetNodeAt(pList, 0);
		if(pCurrent != NULL)
		{
			SLL_RemoveNode(&pList, pCurrent);
			SLL_DestroyNode(pCurrent);
		}
	}

	return 0;
}