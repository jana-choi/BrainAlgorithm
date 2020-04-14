#include "LinkedListStack.h"

int main(void)
{
	int i = 0;
	int nCount = 0;
	Node* pPopped;

	LinkedListStack* pStack;
	LLS_CreateStack(&pStack);

	LLS_Push(pStack, LLS_CreasteNode("abc"));
	LLS_Push(pStack, LLS_CreasteNode("def"));
	LLS_Push(pStack, LLS_CreasteNode("efg"));
	LLS_Push(pStack, LLS_CreasteNode("hij"));

	nCount = LLS_GetSize(pStack);
	printf("Size: %d, Top: %s\n\n", nCount, LLS_Top(pStack)->pData);

	for(i = 0; i < nCount; i++)
	{
		if(LLS_IsEmpty(pStack))
			break;

		pPopped = LLS_Pop(pStack);
		printf("Popped: %s, ", pPopped->pData);
		LLS_DestroyNode(pPopped);

		if(!LLS_IsEmpty(pStack))
			printf("Current Top: %s\n", LLS_Top(pStack)->pData);
		else
			printf("Stack Is Empty.\n");
	}

	LLS_DestroyStack(pStack);

	return 0;
}