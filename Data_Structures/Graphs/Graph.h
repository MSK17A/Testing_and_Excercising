#pragma once

#define MAXV    1000 /* Maximum number of vertices */

class Egdenode
{
    int y; /* Adjency info */
    int weight; /* edge weight */
    Egdenode* next; /* Next edge in list */
};

class Graph
{
public:
    Egdenode* edges[MAXV+1]; /* adjacency info */
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nVertices; /* number of vertices */
    int nEdges; /* number of edges */
    bool directed; /* is the graph directed? */

    Graph(/* args */);
    ~Graph();
};

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}

void graph_init(Graph *g, bool directed);