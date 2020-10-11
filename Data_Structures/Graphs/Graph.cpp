#include "Graph.h"
#include <iostream>

void graph_init(Graph *g, bool directed)
{
    g ->nVertices = 0;
    g ->nEdges = 0;
    g ->directed = directed;

    for (int i=0; i<MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}