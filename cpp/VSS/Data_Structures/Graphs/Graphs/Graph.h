#pragma once

#define MAXV    1000 /* Maximum number of vertices */

class Edgenode
{
public:
    int y; /* Adjency info */
    int weight; /* edge weight */
    Edgenode* next; /* Next edge in list */
};

class Graph
{
public:
    Edgenode* edges[MAXV + 1]; /* adjacency info */
    int degree[MAXV + 1]; /* outdegree of each vertex */
    int nVertices; /* number of vertices */
    int nEdges; /* number of edges */
    bool directed; /* is the graph directed? */

};

void graph_init(Graph* g, bool directed);
void insert_edge(Graph* g, int x, int y, bool directed);
void print_Graph(Graph* g);
void BFS(Graph* G, int startV);
void proccess_vertex_early(int v);
void proccess_vertex_late(int v);
void proccess_edge(int v, int y);