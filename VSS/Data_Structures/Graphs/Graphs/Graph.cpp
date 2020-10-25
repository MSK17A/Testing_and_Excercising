#include "Graph.h"

bool proccessed[MAXV + 1];
bool discovered[MAXV + 1];
int parent[MAXV + 1];

#define UNCOLORED 0
#define BLACK 1
#define WHITE 2
#define TREE 0;
#define BACK 1;
int color[MAXV + 1];

int time = 0;
int entry_time[MAXV + 1];
int exit_time[MAXV + 1];
int tree_out_degree[MAXV + 1]; /* Degree of each vertex in DFS tree */
int reachable_ancestor[MAXV + 1];
bool finished = false;

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

void initialize_search(Graph* G)
{
    for (int i = 0; i < G->nVertices; i++)
    {
        proccessed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

void BFS(Graph* G, int startV)
{
    std::queue<int> Q; /* A FIFO queue of discovered vertices */
    int v; /* Current vertex */
    int y; /* Successor vertex */
    Edgenode* p; /* Temporary pointer to the edges */

    Q.push(startV);
    discovered[startV] = true;

    while (!Q.empty())
    {
        v = Q.front(); /* First in first out */
        Q.pop(); /* Deletes the first element */
        p = G->edges[v];
        proccess_vertex_early(v);

        while (p != NULL)
        {
            y = p->y;
            if ((proccessed[y] == false) || G->directed)
                proccess_edge(v, y);
            if (discovered[y] == false)
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
    reachable_ancestor[v] = v;
}

void proccess_vertex_late(int v)
{
    std::cout << "proccessed vertex " << v;
    std::cout << std::endl;

    bool root; /* is the vertex the root of the DFS tree? */ 
    int time_v; /* earliest reachable time for v */ 
    int time_parent; /* earliest reachable time for parent[v] */

    if (parent[v] < 1) /* Root test (if it has no parent then it is a root */
    {
        if (tree_out_degree[v] > 1)
        {
            std::cout << "Root articulation vertex: " << v << std::endl;
        }
        return;
    }

    root = (parent[parent[v]] < 1); /* Test if parent[v] is root */

    if (!root)
    {
        if (reachable_ancestor[v] == parent[v])
        {
            std::cout << "Parent articulation vertex: " << parent[v] << std::endl;
        }

        if (reachable_ancestor[v] == v)
        {
            std::cout << "Bridge articulation vertex: " << parent[v] << std::endl;
        }
        if (tree_out_degree[v] > 0) /* Test if v is not a leaf */
        {
            std::cout << "Bridge articulation vertex: " << v << std::endl;
        }

        time_v = entry_time[reachable_ancestor[v]];
        time_parent = entry_time[reachable_ancestor[parent[v]]];

        if (time_v < time_parent)
        {
            reachable_ancestor[parent[v]] = reachable_ancestor[v];
        }
    }
}

void proccess_edge(int x, int y)
{
    std::cout << "proccessed edge (" << x << "," << y << ")";
    std::cout << std::endl;

    /*if (color[x] == color[y])
    {
        std::cout << "Not bipartite because of edge (" << x << "," << y << ")";
        std::cout << std::endl;
    }

    color[y] = oppositeColor(color[x]);*/
    int Class;
    Class = edge_classification(x, y);

    if (Class == 0)
        tree_out_degree[x]++;
    if((Class == 1) && (parent[x] != y))
        if (entry_time[y] < entry_time[reachable_ancestor[x]]) /* to ensure that reachable_ancestor of x is the oldest ancestor */
        {
            reachable_ancestor[x] = y;
            std::cout << reachable_ancestor[x] << std::endl;
        }
}

void connected_components(Graph* G)
{
    int c = 0;

    initialize_search(G);

    for (int i = 0; i < G->nVertices; i++)
    {
        if (discovered[i] == false)
        {
            c++;
            std::cout << c << std::endl;
            BFS(G, i);
        }
    }
}

void twocolor(Graph* G)
{

    for (int i = 0; i < G->nVertices; i++)
    {
        color[i] = UNCOLORED;
    }
    initialize_search(G);
    for (int i = 0; i < G->nVertices; i++)
    {
        if (discovered[i] == false)
        {
            color[i] = WHITE;
            BFS(G, i);
        }
    }
}

int oppositeColor(int color)
{
    if (color == WHITE)
        return BLACK;
    if (color == BLACK)
        return WHITE;

    return UNCOLORED;
}

void DFS(Graph* G, int v)
{
    Edgenode* p;
    int y;

    discovered[v] = true;
    time++;
    entry_time[v] = time;

    proccess_vertex_early(v);
    p = G->edges[v];
    while (p != NULL)
    {
        y = p->y;
        if (!discovered[y])
        {
            parent[y] = v;
            proccess_edge(v, y);
            DFS(G, y);
        }
        else if ((!proccessed[v] && parent[v] != y) || G->directed)
            proccess_edge(v, y);

        if (finished) return;
        p = p->next;
    }
    proccess_vertex_late(v);
    time++;
    exit_time[v] = time;

    proccessed[v] = true;
}

int edge_classification(int x, int y)
{
    if (parent[y] == x) return(0);
    if (discovered[y] && !proccessed[y]) return(1);
    if (proccessed[y] && (entry_time[y] > entry_time[x])) return(2);
    if (proccessed[y] && (entry_time[y] < entry_time[x])) return(3);
}

void find_path(int startV, int endV, int parent[])
{
    if ((startV == endV) || endV == -1)
        std::cout << startV;
    else
    {
        find_path(startV, parent[endV], parent);
        std::cout << endV;
    }
}
