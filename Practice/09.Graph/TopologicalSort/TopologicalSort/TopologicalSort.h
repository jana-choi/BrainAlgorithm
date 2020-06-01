#ifndef _TOPOLOGICALSORT_H_
#define _TOPOLOGICALSORT_H_

#include "../../Graph/Graph/Graph.h"
#include "../LinkedList/LinkedList.h"

void TopologicalSort(Vertex* V, Node** List);
void TS_DFS(Vertex* V, Node** List);

#endif	// _TOPOLOGICALSORT_H_
