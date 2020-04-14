#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType		eData;
	struct tagNode*	pNextNode;
} Node;


Node* SLL_CreateNode(ElementType a_eData);
void SLL_DestroyNode(Node* a_pNode);
void SLL_AppendNode(Node** a_ppHead, Node* a_pNewNode);
void SLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode);
void SLL_InsertNewHead(Node** a_ppHead, Node* a_pNewNode);
void SLL_RemoveNode(Node** a_ppHead, Node* a_pRemove);
Node* SLL_GetNodeAt(Node* a_pHead, int a_nLocation);
int SLL_GetNodeCount(Node* a_pHead);

#endif // !LINKEDLIST_H

