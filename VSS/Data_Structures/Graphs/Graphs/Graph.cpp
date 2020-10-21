#include "Graph.h"
#include <iostream>
#include <queue>

void graph_init(Graph* g, bool directed)
{
    g->nVertices = 6;
    g->nEdges = 0;
    g->directed = directed;

    for (int i = 0; i < MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(Graph* g, int x, int y, bool directed)
{
    Edgenode* p = new Edgenode(); /* Temporary pointer */
    p->y = y;
    p->weight = 0;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;

    if (directed)
    {
        g->nEdges++; /* Keep track of edges number */
    }
    else
    {
        insert_edge(g, y, x, true); /* Re-insert from y to x becuase it is undirected edge */
    }


}

void print_Graph(Graph* g)
{
    int i;
    Edgenode* p;

    for (i = 0; i < g->nVertices; i++)
    {
        std::cout << i << "|";
        p = g->edges[i];
        while (p != NULL)
        {
            std::cout << p->y;
            p = p->next;
            if(p != NULL)
                std::cout << "->";
        }
        std::cout << std::endl;
    }

}

bool proccessed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

void BFS(Graph* G, int startV)
{
    std::queue<int> Q; /* A FIFO queue of discovered vertices */
    int v; /* Current vertex */
    int y; /* Successor vertex */
    Edgenode* p; /* Temporary pointer to the edges */

    for (int i = 0; i < G->nVertices; i++)
    {
        proccessed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
    Q.push(startV);
    discovered[startV] = true;

    while (!Q.empty())
    {
        v = Q.front(); /* First in first out */
        Q.pop();
        p = G->edges[v];
        proccess_vertex_early(v);

        while (p != NULL)
        {
            y = p->y;
            if (!proccessed[y] || G->directed)
                proccess_edge(v, y);
            if (!discovered[y])
            {
                Q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        proccessed[v] = true;
        proccess_vertex_late(v);
    }
}

void proccess_vertex_early(int v)
{
}

void proccess_vertex_late(int v)
{
    std::cout << "proccessed vertex " << v;
    std::cout << std::endl;
}

void proccess_edge(int v, int y)
{
    std::cout << "proccessed edge (" << v << "," << y << ")";
    std::cout << std::endl;
}
