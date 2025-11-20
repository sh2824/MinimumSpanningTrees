#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "graph.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

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

bool Graph::edgeExists(Edge edgeCheck) const {
    // if an edge exists in adjList then we return true else false
    string src = edgeCheck.source;
    string dest = edgeCheck.destination;
    double weg = edgeCheck.weight;

    return edgeExists(src, dest, weg);
};

bool Graph::edgeExists(string source, string destination, double weight) const {
    //
    if ((adjList.find(source) == adjList.end()) && (adjList.find(destination) == adjList.end())) {
        return false; // neither nodes on edge are a source
    }

    // check edges from given source
    auto sourceNode = adjList.find(source);
    if (sourceNode != adjList.end()) {
        for (const auto& [d, w] : sourceNode->second) {
            if (d == destination) return true;
        }
    }
    // check edges from given destination as source
    auto destinationNode = adjList.find(destination);
    if (destinationNode != adjList.end()) {
        for (const auto& [d, w] : destinationNode->second) {
            if (d == source) return true;
        }
    }
    return false;
};

bool Graph::wouldCreateCycle(string sourceVertex, string destinationVertex) const {
    // if either vertex doesn't exist it can't create a cycle
    if (adjList.find(sourceVertex) == adjList.end() || adjList.find(destinationVertex) == adjList.end()) return false;

    vector<pair<string, string>> myStack; // is pair to track parents
    vector<string> visited;

    myStack.push_back({sourceVertex, ""}); // "" = no parent

    while (!myStack.empty()) {
        // while it is not the case that the stack is empty
        auto [current, parent] = myStack.back();
        myStack.pop_back();

        // check if we been here
        bool alreadyVisited = false;
        for (const string& v : visited) {
            if (v == current) {
                alreadyVisited = true;
                break;
            }
        }
        if (alreadyVisited) continue;

        visited.push_back(current);

        if (current == destinationVertex) 
            return true; // cycle would form

        auto vertexIterator = adjList.find(current);
        if (vertexIterator != adjList.end()) {
            const auto& neighbors = vertexIterator->second; // vector<pair<string, double>>
            for (const auto& neighborPair : neighbors) {
                const string& neighbor = neighborPair.first;
                if (neighbor == parent) continue;
                myStack.push_back({neighbor, current});
            }
        }
        
    }
    return false; // cycle not possible
};

void Graph::loadFromJson(const string& filename) {
    // load the json file into the program
    ifstream file(filename);
    // error catching
    if (!file.is_open()) {
        cerr << "Error: cannot open file " << filename << endl;
    }

    // store the json into a variable
    json data;
    file >> data;

    // check if directed and weighted
    /*
     * In the case that a graph is undirected we create two edges per one in json
     * file. One going each direction. 
     * In the case that a graph is unweighted, we set all weights to 1.
     */
    int directed = data["Directed"];
    int weighted = data["Weighted"];

    // initialize the vertices (including isolated)
    for (const auto& v : data["vertexList"]) {      // for each vertex in the list
        adjList[v.get<string>()] = {};                // create an empty set to represent it
    }

    // initialize edges
    // if w=unweighted set all weights to 1
    // if undirected do it forwards and backwards
    for (const auto& e : data["edgeList"]) {
        string source = e["source"];
        string dest = e["destination"];
        double w = weighted ? e["weight"].get<double>() : 1.0;
        addEdge(source, dest, w);
        // if undirected do it forwards and backwards
        if (!directed) {
            addEdge(dest, source, w);
        }
    }
};

vector<string> Graph::getAllVertices() const {
    cout << "getAllVertices: not yet functional\n";
    vector<string> collection;

    // for (const auto& v : adjList) {
    //     collection.push_back(v);
    //     cout << v << ", ";
    // }
    cout << endl;

    return collection;
};

vector<Edge> Graph::getAllEdges() const {
    vector<Edge> edges;
    for (const auto& [node, neighbors] : adjList) {
        for (const auto& [neighbor, weight] : neighbors) {
            edges.push_back({node, neighbor, weight});
        }
    }
    return edges;
}

void Graph::print() const {
    for (const auto& [node, neighbors] : adjList) {
        cout << node << "->";
        for (const auto& [neighbor, weight] : neighbors) {
            cout << "(" << neighbor << ", " << weight << ")";
        }
        cout << endl;
    }
};