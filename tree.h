#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <cmath>
#include <string>
#include <set>

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
struct NodeTree {
    string key;
    vector<NodeTree*> children;
};

// define tree structure here
class TreeMST {
    public:
        // CONSTRUCTORS
        TreeMST(NodeTree root);
        
        // GETTERS
        int getHeight();
        int getNodeCount();
        NodeTree* getRoot();

        bool containsNode(NodeTree node);

        // SETTERS
        bool addNode(NodeTree newNode, NodeTree Parent); // returns true if successfully added
        bool changeNodeKey(NodeTree node, string newKey);
        bool changeNodeVal(NodeTree node, int newVal);

    private:
        NodeTree* root;
};

#endif