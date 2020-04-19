#ifndef _REDBLACKTREE_H_
#define _REDBLACKTREE_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

#define	RED		0
#define	BLACK	1

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	int Color; //enum {RED, BLACK} Color;

	ElementType Data;
} RBTNode;


void RBT_DestroyTree(RBTNode* Tree);

RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestroyNode(RBTNode* Node);

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);
RBTNode* RBT_SearchMinNode(RBTNode* Tree);
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode);
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode);
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data);
void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X);
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor);

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount);
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);

#endif	// _REDBLACKTREE_H_