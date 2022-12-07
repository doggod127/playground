#include "Graph.h"

int main() {
    Graph graph("../test.txt");
    graph.printGraph();

    graph.calculateMinimalDistanceBetweenNodes(0);

    return 0;
}
