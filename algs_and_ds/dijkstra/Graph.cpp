#include "Graph.h"
Graph::Graph(std::string const &fileName) {
    std::ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open input file <" << fileName << ">. Aborting." << "\n";
        return;
    }
    inputFile >> numberOfVertices;

    matrix = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
        for (int j = 0; j < numberOfVertices; j++)
        {
            inputFile >> matrix[i][j];
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[]matrix[i];
    }
    delete[]matrix;
}

void Graph::printGraph()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int Graph::findClosestVertexIndex(const int * const distanceToSourceVertex, const bool * const isVertexVisited)
{
    int minimalDistance = INT32_MAX;
    int minimalDistanceIndex;

    for (int i = 0; i < numberOfVertices; i++)
    {
        if (!isVertexVisited[i] && distanceToSourceVertex[i] <= minimalDistance)
        {
            minimalDistance = distanceToSourceVertex[i];
            minimalDistanceIndex = i;
        }
    }
    return minimalDistanceIndex;
}

int Graph::calculateMinimalDistanceBetweenNodes(const int startingNode)
{
    bool isVertexVisited[numberOfVertices];
    int distanceToSourceVertex[numberOfVertices];

    for (int i = 0; i < numberOfVertices; i++)
    {
        isVertexVisited[i] = false;
        distanceToSourceVertex[i] = INT32_MAX;
    }
    distanceToSourceVertex[startingNode] = 0;

    for (int i = 0; i < numberOfVertices - 1; i++)
    {
        int closestVertexIndex = findClosestVertexIndex(distanceToSourceVertex, isVertexVisited);
        isVertexVisited[closestVertexIndex] = true;

        for (int j = 0; j < numberOfVertices; j++)
        {
            if (!isVertexVisited[j] && matrix[closestVertexIndex][j] != 0 &&
                distanceToSourceVertex[closestVertexIndex] != INT32_MAX
                &&
                distanceToSourceVertex[closestVertexIndex] + matrix[closestVertexIndex][j] < distanceToSourceVertex[j])
            {
                distanceToSourceVertex[j] = distanceToSourceVertex[closestVertexIndex] + matrix[closestVertexIndex][j];
            }
        }
    }
    printSolution(distanceToSourceVertex);
}

void Graph::printSolution(int *dist)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numberOfVertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}