#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
 * Edge structure is used to connect the vertices in a graph
 *
*/

struct Edge {
    string source, destination;
    double weight;
};

/*
 * Graph class is an object that will be made of vertices and edges connecting
 * those vertices. 
 * 
*/

class Graph {
    public:
        bool addVertex(string newVertex);
        bool addEdge(string sourceVertex, string destinationVertex, double newWeight);
        vector<Edge> getAllEdges() const;
    private:
        unordered_map<string, vector<pair<string, double>>> adjList;
}