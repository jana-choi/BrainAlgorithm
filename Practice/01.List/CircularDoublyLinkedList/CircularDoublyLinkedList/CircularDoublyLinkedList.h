#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType		eData;
	struct tagNode* pPrevNode;
	struct tagNode* pNextNode;
} Node;


Node* CDLL_CreateNode(ElementType a_eNewData);
void CDLL_DestroyNode(Node* a_pNode);
void CDLL_AppendNode(Node** a_ppHead, Node* a_pNewNode);
void CDLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode);
void CDLL_RemoveNode(Node** a_ppHead, Node* a_pRemove);
Node* CDLL_GetNodeAt(Node* a_pHead, int a_nLocation);
int CDLL_GetNodeCount(Node* a_pHead);

#endif // !CIRCULAR_DOUBLY_LINKEDLIST_H
