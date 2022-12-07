#ifndef MST_GRAPH_H
#define MST_GRAPH_H

#include <iostream>
#include <vector>
#include <fstream>


class Graph
{
    int numberOfVertices;
    std::vector<char> vertices;
    int** matrix;

    int findClosestVertexIndex(const int *, const bool *);


public:
    Graph(std::string const &);
    ~Graph();
    void printGraph();
    void printSolution(int *);

    int calculateMinimalDistanceBetweenNodes(int );


};


#endif //MST_GRAPH_H
