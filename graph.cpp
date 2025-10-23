#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "graph.h"

using namespace std;

Graph::Graph() {
    vertexCount = 0;
    edgeCount = 0;
};

Graph::Graph(string rootVertex) {
    vertexCount = 1;
    edgeCount = 0;
    adjList[rootVertex] = {};
};

bool Graph::addVertex(string newVertex) {
    adjList[newVertex] = {};
    return true;
};

bool Graph::addEdge(Edge newEdge) {
    // edgeCount++;
    cout << "addEdge(Edge): not yet functional\n";
    return true;
};

bool Graph::addEdge(string sourceVertex, string destinationVertex, double newWeight) {
    edgeCount++;
    adjList[sourceVertex].push_back({destinationVertex, newWeight});
    return true;
};

vector<string> Graph::getAllVertices() const {
    cout << "getAllVertices: not yet functional\n";
};

void Graph::print() const {
    cout << "print: not yet functional\n";
};