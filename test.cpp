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
    cout << "\n\nGraph A: cyclical directed weighted graph\n";
    
    Graph graphA("Fortuna");
    graphA.addVertex("Eureka");

    graphA.addEdge("Fortuna", "Eureka", 18.0);
    graphA.addEdge("Eureka", "Trinidad", 22.9);
    graphA.addEdge("Eureka", "Fortuna", 18.0);

    graphA.print();

    // GRAPH B
    cout << "\n\nGraph B: acyclical directed and weighted graph\n";
    Graph graphB;
    graphB.addVertex("A");
    graphB.addVertex("B");
    graphB.addVertex("C");
    graphB.addVertex("D");
    graphB.addVertex("E");
    graphB.addVertex("F");
    graphB.addVertex("G");
    graphB.addVertex("H");
    graphB.addVertex("I");
    graphB.addVertex("J");

    graphB.addEdge("A","B",1.2);
    graphB.addEdge("A","C",3.2);
    graphB.addEdge("C","D",2.1);
    graphB.addEdge("A","F",9.6);
    graphB.addEdge("B","F",3.1);
    graphB.addEdge("C","F",0.2);
    graphB.addEdge("C","E",14.3);
    graphB.addEdge("D","E",3.3);
    graphB.addEdge("E","J",5.6);
    graphB.addEdge("D","H",4.9);
    graphB.addEdge("H","F",0.1);
    graphB.addEdge("E","G",6.9);
    graphB.addEdge("G","I",7.8);
    graphB.addEdge("F","G",2.1);

    graphB.print();

    // GRAPH C
    cout << "\n\nGRAPH C: loaded from JSON file\n";

    // read from JSON file
    Graph graphC;
    graphC.loadFromJson("graphFriends.json");

    graphC.print();



    // TESTS
}