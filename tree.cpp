#include <cstdlib>
#include <cmath>
#include <string>
#include <set>

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

