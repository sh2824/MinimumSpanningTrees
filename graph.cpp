#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "graph.h"

using namespace std;

Graph::Graph() {
    vertexCount = 0;
};

Graph::Graph(string rootVertex) {
    vertexCount = 1;
    adjList[rootVertex] = {};
};

bool Graph::addVertex(string newVertex) {
    adjList[newVertex] = {};
    return true;
};

bool Graph::addEdge(Edge newEdge) {
    cout << "not yet functional\n";
    return true;
};

bool Graph::addEdge(string sourceVertex, string destinationVertex, double newWeight) {
    cout << "not yet functional\n";
    return true;
};