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

void Kruskal::DSU::makeSet(const string& node) {
    if (nodeToIndex.count(node)) return;

    int idx = parent.size();
    
    nodeToIndex[node] = idx;
    indexToNode.push_back(node);
    parent.push_back(idx);
    rank.push_back(0);
}

int Kruskal::DSU::findInt(int x) {
    if (parent[x] != x) parent[x] = findInt(parent[x]);
    return parent[x];
}

string Kruskal::DSU::find(const string& node) {
    if (!nodeToIndex.count(node))
        makeSet(node);

    int idx = nodeToIndex[node];
    int rootIdx = findInt(idx);
    return indexToNode[rootIdx];
}

void Kruskal::DSU::unite(const string& a, const string& b) {
    makeSet(a);
    makeSet(b);

    int rootA = findInt(nodeToIndex[a]);
    int rootB = findInt(nodeToIndex[b]);

    if (rootA == rootB) return;

    if (rank[rootA] < rank[rootB]) swap(rootA, rootB);

    parent[rootB] = rootA;
    if (rank[rootA] == rank[rootB]) rank[rootA]++;
    
}

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
void Kruskal::buildHelper(const Graph& g, TreeMST t, const string& currentKey, Node* parentNode, vector<string> visited) {
    // make current node visited
    visited.push_back(currentKey);

    // get neighbors from graph for current
    
}
