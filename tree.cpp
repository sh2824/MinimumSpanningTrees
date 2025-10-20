#include <cstdlib>
#include <cmath>
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
class NodeTree {
    public:
        // CONSTRUCTORS
        NodeTree(int value, string key)
        NodeTree(int value, string key, NodeTree* parent)

        // variables
        int nodeValue;
        string nodeKey;
        NodeTree* nodeParent;

        // imported a set library to track children
        set<NodeTree> children;
};

// CONSTRUCTORS
NodeTree::NodeTree(int value, string key) {
    this->nodeValue = value;
    this->nodeKey = key;
    this->nodeParent = nullptr;
}

NodeTree::NodeTree(int value, string key, NodeTree* parent) {
    this->nodeValue = value;
    this->nodeKey = key;
    this->nodeParent = parent;
}


// define tree structure here


// GETTERS

// height

// number of nodes

// SETTERS?? -- do we need these?

// add node to tree

// change node in tree


