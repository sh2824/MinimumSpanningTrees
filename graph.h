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

    // string to_string() {
    //     return "{s:"<<self.source<<" d:"<<self.destination<<" w:"<<self.weight<<"}";
    // }
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

        // return true if successful
        bool addVertex(string newVertex);   // cannot add a vertex that already exists
        bool addEdge(Edge newEdge);         // cannot add an edge that already exists
        bool addEdge(string sourceVertex, string destinationVertex, double newWeight);

        // load a graph from a json file
        void loadFromJson(const string& filename);

        vector<string> getAllVertices() const;
        vector<Edge> getAllEdges() const;
        void print() const;
    protected:
        // the adjacency list for the graph
        // string[node]: (string[neighbor], double[edgeWeight]), (x,y), ...;
        unordered_map<string, vector<pair<string, double>>> adjList;
    private:
        int vertexCount;
        int edgeCount;
};


#endif