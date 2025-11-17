#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

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

Kruskal::DSU::DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int Kruskal::DSU::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void Kruskal::DSU::unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) 
            rank[a]++;
    }
}

TreeMST Kruskal::run(const Graph& g) {
    // first extract all edges
    auto edges = graph.getEdges();

    // next sort edges

    // create DSU

    // create tree to be returned
    TreeMST mst;

    // Kruskal

    // return
    return mst;
}
