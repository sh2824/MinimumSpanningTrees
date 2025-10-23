#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

#include "kruskal.cpp"
#include "graph.h"
#include "tree.h"


using namespace std;

int main() {

    // start small create and test some edges
    /*
     * Edge structure
     * string source, destination
     * double weight
     */
    Edge bob = {"A", "B", 2.5};
    cout << bob.source <<", "<< bob.destination <<", "<< bob.weight << endl;

    // create some graphs to test on
    // graphs are adjacency lists

    // GRAPH A
    Graph graphA("Fortuna");
    graphA.addVertex("Eureka");

    graphA.addEdge("Fortuna", "Eureka", 18.0);
    graphA.addEdge("Eureka", "Trinidad", 22.9);
    graphA.addEdge("Eureka", "Fortuna", 18.0);

    graphA.print();

    // GRAPH B

    // GRAPH C



    // TESTS
}