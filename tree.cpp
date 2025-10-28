#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

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
TreeMST::TreeMST() {
    root = nullptr;
};
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

/*
 * findNodeDFS: a recursive depth first search function
 *
 * parameters: string searchKey: the key of the node we are looking for
 *             Node* currentNode: the address of the node we are currently checking
 * 
 * logic: the search is initialized on the root node of a tree.
 *        base case: if the tree is empty return null pointer
 *        check the currentNode key and if its the key we are searching for return 
 *        current node.
 *        if not we run findNodeDFS on all the children of currentNode
 *        if we get to the end of this function then that means we never found the 
 *        key in the tree and we return null pointer.
*/
Node* TreeMST::findNodeDFS(string searchKey, Node* currentNode) {
    // base case
    if (!currentNode) return nullptr;

    // use DFS to find a node in a tree
    if (currentNode->key == searchKey) {
        return currentNode;
    }
    for (Node* child : currentNode->children) {
        Node* result = findNodeDFS(searchKey, child);
        if (result) return result;      
        // we only return if we hit null or our search so if we return nullptr
        // then its false and we skip this conditional but if we return th key
        // then we return the result all the way back to the bottom of the stack
    }
    
    return nullptr;
};

// MODIFIERS
bool TreeMST::setRoot(Node newRoot) {
    // check if there is a root
    if (root) {
        cout << "root already exists ABORTED\n";
        return false;
    } else {
        cout << "root set\n";
        root = &newRoot;
    }

    // if not we simply set th root and return true
    // if there is a root we need to make the old root a child of the new root
    // and set the tree root to the new one
    return true;
};
bool TreeMST::addNode(Node newNode, Node Parent) {
    // if there is no parent matching the parameter, return false
    Node* new_ptr = &newNode;
    Parent.children.push_back(new_ptr);
    return true;
};
bool TreeMST::addNode(Node newNode, string parentKey) {
    // if there is no parent matching the parameter, return false
    // add node
    return true;
};
bool TreeMST::changeNodeKey(Node node, string newKey) {
    node.key = newKey;
    return true;
};
bool TreeMST::changeNodeCost(Node node, double newCost) {
    node.cost = newCost;
    return true;
};

void TreeMST::print() {
    int depthCounter = 0;
    printHelper(root, depthCounter);
};
void TreeMST::printHelper(Node* currentNode, int depth) {
    // base case
    if (!currentNode) return;

    // print buffer
    for (int i = 0; i < depth; i++) {
        cout << "--";
    }

    // print current node
    cout << currentNode->key << ", " << currentNode->cost << endl;

    // print the kids recursively
    for (Node* child : currentNode->children) {
        //Node* child_ptr = &child;
        printHelper(child, depth + 1);
    }

    // bug fixing
    cout << "loop exit\n";
};