#include "ArrayStack.h"

int main(void)
{
	int i = 0;
	ArrayStack* pStack = NULL;

	AS_CreateStack(&pStack, 10);

	AS_Push(pStack, 3);
	AS_Push(pStack, 37);
	AS_Push(pStack, 11);
	AS_Push(pStack, 12);

	printf("Capacity: %d, Size: %d, Top: %d\n\n", pStack->nCapacity, AS_GetSize(pStack), AS_Top(pStack));

	for(i = 0; i < 4; i++)
	{
		if(AS_IsEmpty(pStack))
			break;

		printf("Popped: %d, ", AS_Pop(pStack));

		if(!AS_IsEmpty(pStack))
			printf("Current Top: %d\n", AS_Top(pStack));
		else
			printf("Stack Is Empty.\n");
	}

	AS_DestroyStack(pStack);


	return 0;
}