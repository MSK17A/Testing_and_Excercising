#pragma once
#include "Graph.h"

class DepthFirstSearch
{
public:
	void initialize_search(Graph* G);
	void DFS(Graph* G, int startV);
	void proccess_vertex_early(int v);
	void proccess_vertex_late(int v);
	void proccess_edge(int x, int y);
};

