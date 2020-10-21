#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph* g = new Graph();
    graph_init(g, false);

    insert_edge(g, 1, 2, false);
    insert_edge(g, 1, 3, false);
    insert_edge(g, 3, 5, false);
    insert_edge(g, 2, 4, false);
    insert_edge(g, 2, 3, false);
    insert_edge(g, 4, 5, false);

    print_Graph(g);

    BFS(g, 1);
    return 0;
}