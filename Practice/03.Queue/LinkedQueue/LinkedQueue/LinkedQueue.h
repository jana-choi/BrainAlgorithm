#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char*			Data;
	struct tagNode*	NextNode;
} Node;

typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;


void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

Node* LQ_CreateNode(const char* NewData);
void LQ_DestroyNode(Node* _Node);

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif	// _LINKED_QUEUE_H_
