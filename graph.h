#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>

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
        Graph();
        Graph(string rootVertex);

        bool addVertex(string newVertex);
        bool addEdge(Edge newEdge);
        bool addEdge(string sourceVertex, string destinationVertex, double newWeight);
        vector<Edge> getAllEdges() const;
        void print() const;
    private:
        // the adjacency list for the graph
        // string[node]: (string[neighbor], double[edgeWeight]), (x,y), ...;
        unordered_map<string, vector<pair<string, double>>> adjList;
        int vertexCount;
};


#endif