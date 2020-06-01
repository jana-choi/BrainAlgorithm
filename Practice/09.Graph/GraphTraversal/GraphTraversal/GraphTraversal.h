#ifndef _GRAPH_TRAVERSAL_H_
#define _GRAPH_TRAVERSAL_H_

#include "../../Graph/Graph/Graph.h"
#include "../LinkedQueue/LinkedQueue.h"

void DFS(Vertex* V);						// Depth First Search
void BFS(Vertex* V, LinkedQueue* Queue);	// Breadth First Search

#endif	// _GRAPH_TRAVERSAL_H_
