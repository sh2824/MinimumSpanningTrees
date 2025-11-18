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

    // create DSU
    DSU dsu;
    
    // create tree to be returned
    TreeMST mst;

    // next sort edges
    sort(edges.begin(), edges.end(), 
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        }
    );

    for (auto& e : edges) {
        dsu.makeSet(e.source);
        dsu.makeSet(e.destination);
    }
    
    // Pick ANY node from the graph to serve as the root
    if (!edges.empty()) {
        mst.setRoot(edges[0].source);
        cout << edges[0].source << endl;
    } else {
        return TreeMST();
    }

    // cout << edges[0].source << endl;

    // Kruskal
    for (const auto& e : edges) {
        string u = dsu.find(e.source);
        string v = dsu.find(e.destination);
        double c = e.weight;
        Node n = {v, c};

        // cout << "e:" << e.to_string() <<" n:"<<n<<endl;

        // cout << "u:" << u << " v:"<<v<<endl;

        if (u != v) {
            dsu.unite(u, v);
            mst.addNode(n, e.source);
        }
    }

    // return
    return mst;
}
