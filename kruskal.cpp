#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

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
    makeSet(node);
    int rootIdx = findInt(nodeToIndex[node]);
    return indexToNode[rootIdx];
}

void Kruskal::DSU::unite(const string& a, const string& b) {
    makeSet(a);
    makeSet(b);

    int rootA = findInt(nodeToIndex[a]);
    int rootB = findInt(nodeToIndex[b]);

    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) rank[rootA]++;
    }
}

TreeMST Kruskal::run(const Graph& g) {
    // first extract all edges
    vector<Edge> edges = g.getAllEdges();

    // next sort edges
    sort(edges.begin(), edges.end(), 
        [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        }
    );

    // create DSU
    DSU dsu;

    // create tree to be returned
    TreeMST mst;

    // Kruskal
    for (const auto& e : edges) {
        if (dsu.find(e.source) != dsu.find(e.destination)) {
            dsu.unite(e.source, e.destination);
            Node node = {e.destination, e.weight};
            mst.addNode(node, e.source);
        }
    }

    // return
    return mst;
}
