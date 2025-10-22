#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// ******************************************************
/* tree structure defined here as a linked list
 * the tree will be created by passing it a key and value for the root node
 * the tree is used to create minimum spanning trees
 * the weight will be saved as the values of the nodes
 * the keys will be the node key.
 * nodes in tree have children represented using a set
*/

// define node structure here (trees need nodes)
struct Node {
    string key;
    vector<Node> children;
};

// define tree structure here
class TreeMST {
    public:
        // CONSTRUCTORS
        TreeMST(Node* root);
        
        // GETTERS
        int getHeight();
        int getNodeCount();
        Node* getRoot();

        bool containsNode(Node node);

        // SETTERS
        bool addNode(Node newNode, Node Parent); // returns true if successfully added
        bool changeNodeKey(Node node, string newKey);
        bool changeNodeVal(Node node, int newVal);

    private:
        Node* root;
};

#endif