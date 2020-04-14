#ifndef _LINKEDLIST_STACK_H_
#define _LINKEDLIST_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* pData;
	struct tagNode* pNextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* pList;
	Node* pTop;
} LinkedListStack;


void LLS_CreateStack(LinkedListStack** a_ppStack);
void LLS_DestroyStack(LinkedListStack* a_pStack);

Node* LLS_CreasteNode(const char* a_pData);
void LLS_DestroyNode(Node* a_pNode);

void LLS_Push(LinkedListStack* a_pStack, Node* a_pNode);
Node* LLS_Pop(LinkedListStack* a_pStack);

Node* LLS_Top(LinkedListStack* a_pStack);
int LLS_GetSize(LinkedListStack* a_pStack);
int LLS_IsEmpty(LinkedListStack* a_pStack);

#endif // !_LINKEDLIST_STACK_H_
