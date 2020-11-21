#pragma once

#include <iostream>
#include <queue>

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

void initialize_search(Graph* G);
void BFS(Graph* G, int startV);
void proccess_vertex_early(int v);
void proccess_vertex_late(int v);
void proccess_edge(int x, int y);
void connected_components(Graph* G);
void twocolor(Graph* G);
int oppositeColor(int color);
void DFS(Graph* G, int startV);
int edge_classification(int x, int y);
void find_path(int startV, int endV, int parent[]);