#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType		eData;
	struct tagNode*	pPrevNode;
	struct tagNode*	pNextNode;
} Node;


Node* DLL_CreateNode(ElementType a_eNewData);
void DLL_DestroyNode(Node* a_pNode);
void DLL_AppendNode(Node** a_ppHead, Node* a_pNewNode);
void DLL_InsertAfter(Node* a_pCurrent, Node* a_pNewNode);
void DLL_RemoveNode(Node** a_ppHead, Node* a_pRemove);
Node* DLL_GetNodeAt(Node* a_pHead, int a_nLocation);
int DLL_GetNodeCount(Node* a_pHead);


#endif	// !DOUBLY_LINKEDLIST_H