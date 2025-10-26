#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>

#include "tree.h"

using namespace std;

// ******************************************************
/* tree structure defined here as a linked list
 * the tree will be created by passing it a key and value for the root node
 * the tree is used to create minimum spanning trees
 * the weight will be saved as the values of the nodes
 * the keys will be the node key.
 * nodes in tree have children represented using a set
*/

// CONSTRUCTOR
TreeMST::TreeMST(Node* root) {
    this->root = root;
};

// ACCESSORS
int TreeMST::getHeight() {
    // comment
    return 0;
};
int TreeMST::getNodeCount() {
    // comment
    return 0;
};
Node* TreeMST::getRoot() {
    return root;
}
bool TreeMST::containsNode(Node node) {
    // comment
    return false;
};


// MODIFIERS
bool TreeMST::addNode(Node newNode, Node Parent) {
    // add node
    return true;
};
bool TreeMST::changeNodeKey(Node node, string newKey) {
    // change is good
    return true;
};
bool TreeMST::changeNodeCost(Node node, double newCost) {
    // coupons i guess
    return true;
};

