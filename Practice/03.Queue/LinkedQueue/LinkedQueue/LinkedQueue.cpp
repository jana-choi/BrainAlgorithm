#pragma warning (disable:4996)	// https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?redirectedfrom=MSDN&view=vs-2019

#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while(!LQ_IsEmpty(Queue))
	{
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}

	free(Queue);
}

Node* LQ_CreateNode(const char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = (char*)malloc(strlen(NewData)+1);
	strcpy(NewNode->Data, NewData);

	NewNode->NextNode = NULL;

	return NewNode;
}

void LQ_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if(Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
	Queue->Count++;
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
	Node* Front = Queue->Front;

	if(Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
		Queue->Front = Queue->Front->NextNode;

	Queue->Count--;

	return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}
