#include "DoublyLinkedList.h"

int main(void)
{
	int i = 0;
	int count = 0;
	Node* pList = NULL;
	Node* pCurrent = NULL;
	Node* pNewNode = NULL;

	for(i = 0; i < 5; i++)
	{
		pNewNode = DLL_CreateNode(i);
		DLL_AppendNode(&pList, pNewNode);
	}

	count = DLL_GetNodeCount(pList);
	for(i = 0; i < count; i++)
	{
		pCurrent = DLL_GetNodeAt(pList, i);
		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nInserting 3000 After [2] ... \n\n");

	pCurrent = DLL_GetNodeAt(pList, 2);
	pNewNode = DLL_CreateNode(3000);

	DLL_InsertAfter(pCurrent, pNewNode);

	count = DLL_GetNodeCount(pList);
	for(i = 0; i < count; i++)
	{
		pCurrent = DLL_GetNodeAt(pList, i);
		printf("pList[%d]: %d\n", i, pCurrent->eData);
	}

	printf("\nDestroying List ... \n\n");

	for(i = 0; i < count; i++)
	{
		pCurrent = DLL_GetNodeAt(pList, 0);
		if(pCurrent != NULL)
		{
			DLL_RemoveNode(&pList, pCurrent);
			DLL_DestroyNode(pCurrent);
		}
	}

	return 0;
}