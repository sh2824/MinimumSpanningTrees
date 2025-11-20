#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>

#include "tree.h"
#include "graph.h"
#include "kruskal.h"

using namespace std;

// ******************************************************
/* kruskalMST: graph -> tree
 * expects a weighted graph represented as an adjacency list
 * returns a minimum spanning tree represented as a linked list
 * Example: 
*/

TreeMST Kruskal::run(const Graph& g) {
    // first extract all edges
    vector<Edge> edges = g.getAllEdges();

    // create tree to be returned
    TreeMST mst;
    Graph tempGraph;

    // next sort edges
    sort(edges.begin(), edges.end(), 
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        }
    );

    // if no edges return empty tree
    if (edges.empty()) {
        return TreeMST();
    }

    // Kruskal
    for (const auto& e : edges) {
        string u = e.source;
        string v = e.destination;
        double c = e.weight;

        if (u != v && !tempGraph.wouldCreateCycle(u, v)) {
            // cout << "ADDED " << u << " - " << v << ": " << c << "\n";
            tempGraph.addEdge(u,v,c);
        }
    }

    // use a DFS through the graph to add nodes to the tree
    buildTreeFromGraph(tempGraph, mst, edges[0].source);

    // return
    return mst;
}


void Kruskal::buildTreeFromGraph(const Graph& g, TreeMST& t, const string& rootKey) {
    // set root
    Node* rootNode = new Node(rootKey, 0.0);
    t.setRoot(*rootNode);

    vector<string> visited;
    buildHelper(g, t, rootKey, rootNode, visited);
}
void Kruskal::buildHelper( // I love being able to use whitespace how I please
    const Graph& g, 
    TreeMST t, 
    const string& currentKey, 
    Node* parentNode, 
    vector<string> visited) {
    // make current node visited
    visited.push_back(currentKey);

    // get neighbors from graph for current
    const auto& neighbors = g.getNeighbors(currentKey);

    for (const auto& neighborPair : neighbors) {
        const string& neighborKey = neighborPair.first;
        double edgeWeight = neighborPair.second;

        // skip if already visited
        if (find(visited.begin(), visited.end(), neighborKey) != visited.end())
            continue;
        
        // create new node for the tree
        Node* newNode = new Node(neighborKey, edgeWeight);

        // add node to tree under parent
        t.addNode(*newNode, *parentNode);

        // go further into the graph
        buildHelper(g, t, neighborKey, newNode, visited);
    }
}
