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
        NodeTree(int value, string key);
        NodeTree(int value, string key, NodeTree* parent);

        // variables
        int nodeValue;
        string nodeKey;
        NodeTree* nodeParent;

        // imported a set library to track children
        set<NodeTree*> children;
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
Class TreeMST {
    public:
        // CONSTRUCTORS
        TreeMST(NodeTree root);
        
        // GETTERS
        int getHeight();
        int getNodeCount();
        NodeTree* getRoot();

        bool containsNode(TreeNode node);

        // SETTERS
        bool addNode(TreeNode newNode, TreeNode Parent); // returns true if successfully added
        bool changeNodeKey(TreeNode node, string newKey);
        bool changeNodeVal(TreeNode node, int newVal);

    private:
        NodeTree* root;
};

// add node to tree

// change node in tree


