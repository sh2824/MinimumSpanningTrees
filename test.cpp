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

    // Trees & nodes
    /*
     * need to first create a node to use as root
     * create a tree and pass it that node as a root
     * then we can add nodes to the tree
     * 
     * we can also create an empty tree then set its root to a created Node
     * 
    */

    cout << "\nTESTING TREES\n";

    TreeMST treeA;

    cout << "Created empty treeA\n"
         << "Printing empty tree\n";
    treeA.print();

    cout << "\nCreating Node for root of tree A\n";
    Node treeArootNode = {"A", 0, {}};

    cout << "Setting Node as root\n";
    treeA.setRoot(treeArootNode);
    cout << "Setting Node as root again. should FAIL\n";
    treeA.setRoot(treeArootNode);

    cout << "\nprinting tree A\n";
    treeA.print();

    Node treeAchild1 = {"B", 2.5, {} };
    Node treeAchild2 = {"C", 1.2, {} };
    Node treeAchild3 = {"D", 3.7, {} };
    Node treeAchild4 = {"E", 0.5, {} };
    Node treeAchild5 = {"F", 4.1, {} };

    treeA.addNode(treeAchild1, treeArootNode);
    treeA.addNode(treeAchild2, treeArootNode);
    treeA.addNode(treeAchild3, treeAchild1);
    treeA.addNode(treeAchild4, treeAchild1);
    treeA.addNode(treeAchild5, treeAchild4);

    cout << "\nprinting tree A\n";
    treeA.print();

    // what if theres a cycle in th tree???

    cout << "cycle test\n"; 
    treeA.addNode(treeAchild1, treeAchild4);
    treeA.print();

    cout << "user input tree\n";
    TreeMST treeB;
    bool flag = true;
    cout << "skip? [y/n]";
    string skipInput;
    getline(cin, skipInput);

    if (skipInput == "y") flag = false;

    while (flag) {
        cout << "Enter key<string>: ";
        string keyin;
        getline(cin, keyin);
        keyin = (string)keyin;
        cout << "Enter cost<double>: ";
        string costin;
        getline(cin, costin);
        double costin_d = 0.0;

        try {
            costin_d = stod(costin);
        } catch (...) {
            cerr << "Invalid cost, try again.\n";
            break;
        }

        Node* inputNode = new Node;

        inputNode->key = keyin;
        inputNode->cost = costin_d;

        if (!treeB.getRoot()) {
            // if there is no root
            cout << "No root detected setting root: " << keyin << endl;
            treeB.setRoot(*inputNode);
            continue;
        }

        cout << "Parent node key: ";
        getline(cin, keyin);
        keyin = (string)keyin;

        // use my DFS to get the node belonging to that key and add input Node
        // as a child of returned node
        Node* parent_ptr = treeB.findNodeDFS(keyin, treeB.getRoot());

        treeB.addNode(*inputNode, *parent_ptr);
        cout << "EXIT? [y/n]";
        getline(cin, keyin);
        if (keyin == "y") {
            flag = false;
        }
    }

    cout << "print treeB\n";
    treeB.print();

    
}