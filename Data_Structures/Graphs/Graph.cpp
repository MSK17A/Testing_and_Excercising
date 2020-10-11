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

void insert_edge(Graph* g, int x, int y, bool directed)
{
    Edgenode* p = new Edgenode(); /* Temporary pointer */
    p->y = y;
    p->weight = NULL;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;

    if(directed)
    {
        g->nEdges++; /* Keep track of edges number */
    }
    else
    {
        insert_edge(g,y,x,true); /* Re-insert from y to x becuase it is undirected edge */
    }
    
    
}

void print_Graph(Graph* g)
{
    int i;
    Edgenode *p;

    for (i=0; i<g->nVertices; i++)
    {
        std::cout<<i;
        p = g->edges[i];
        while (p != NULL)
        {
            std::cout<< p->y;
            p = p->next;
        }
        std::cout<< std::endl;
    }

}