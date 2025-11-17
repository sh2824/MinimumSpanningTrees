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
            DSU() = default;
            void makeSet(const string& node);
            string find(const string& node);
            void unite(const string& a, const string& b);
            
        private:
            int findInt(int x);
            vector<int> parent;
            vector<int> rank;

            unordered_map<string, int> nodeToIndex;
            vector<string> indexToNode;
        };
};

#endif 
