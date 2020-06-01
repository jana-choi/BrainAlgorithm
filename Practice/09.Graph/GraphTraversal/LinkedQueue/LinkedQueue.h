#ifndef _LINKED_QUEUE_H_
#define _LINKED_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Graph/Graph/Graph.h"


typedef struct tagNode
{
	Vertex*			Data;
	struct tagNode*	NextNode;
} Node;

typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;


LinkedQueue* LQ_CreateQueue();
void LQ_DestroyQueue(LinkedQueue* Queue);

Node* LQ_CreateNode(Vertex* NewData);
void LQ_DestroyNode(Node* _Node);

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif	// _LINKED_QUEUE_H_
