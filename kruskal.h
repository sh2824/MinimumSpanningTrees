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
        void buildTreeFromGraph(const Graph& g, TreeMST& t, const string& rootKey);
        void buildHelper(const Graph& g, TreeMST t, const string& currentKey, Node* parentNode, vector<string> visited);

};

#endif 
