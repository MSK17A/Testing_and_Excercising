#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph* g = new Graph();
    graph_init(g, false);

    insert_edge(g, 1, 6, false);
    insert_edge(g, 1, 2, false);
    insert_edge(g, 1, 5, false);
    insert_edge(g, 2, 3, false);
    insert_edge(g, 2, 5, false);
    insert_edge(g, 3, 4, false);
    insert_edge(g, 4, 5, false);

    print_Graph(g);

    //BFS(g, 1);
    initialize_search(g);
    DFS(g,1);

    return 0;
}