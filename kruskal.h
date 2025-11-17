#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

#include "graph.h"
#include "tree.h"

using namespace std;

class Kruskal {
    public:
        //build and run
        Kruskal() = default; // construuctor

        // takes a graph and outputs a Min Spanning Tree
        TreeMST run(const Graph& g);

    private:
        // helper: Disjoint set (union-find)
        struct DSU {
            vector<int> parent;
            vector<int> rank;

            DSU(int n);
            int find(int x);
            int unite(int a, int b);
        };
};

#endif 
