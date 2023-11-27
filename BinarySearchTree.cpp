/***********************************************
 * Author: Vincent Bardinelli
 * Date: November 26, 2023
 * Class: CSDP 250 Fall 2023
 * Program Purpose:
 * This file contains the implementation of the BinarySearchTree class methods.
 * It provides the functionality for inserting, searching, deleting nodes, tree traversals,
 * and checking if the tree maintains AVL tree properties.
 ***********************************************/
#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm> // For std::max

using namespace std;

//Constructor: Initializes a new node with given data
Node::Node(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}

//Constructor: Initializes an empty Binary Search Tree
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

//Destructor: Deletes all nodes to prevent memory leaks
BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

//Inserts a new value into the tree
void BinarySearchTree::insert(int value) {
    root = insertNode(root, value);
}

//Searches for a value in the tree
bool BinarySearchTree::search(int value) const {
    return searchNode(root, value);
}

//Deletes a node with the specified value from the tree
void BinarySearchTree::deleteNode(int value) {
    root = deleteNodeRecursively(root, value);
}

//Displays the tree in in-order traversal
void BinarySearchTree::displayInOrder() const {
    displayInOrder(root);
    cout << "\n";
}

//Displays the tree in pre-order traversal
void BinarySearchTree::displayPreOrder() const {
    displayPreOrder(root);
    cout << "\n";
}

//Displays the tree in post-order traversal
void BinarySearchTree::displayPostOrder() const {
    displayPostOrder(root);
    cout << "\n";
}

//Checks if the tree is an AVL tree
bool BinarySearchTree::isAVL() const {
    return isAVLRecursively(root);
}

//Private methods...

//Recursively deletes all nodes from the tree
void BinarySearchTree::deleteTree(Node* node) {
    if (node) {
        deleteTree(node->leftChild);
        deleteTree(node->rightChild);
        delete node;
    }
}

//Helper function for inserting a node into the tree
Node* BinarySearchTree::insertNode(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->leftChild = insertNode(node->leftChild, value);
    } else if (value > node->data) {
        node->rightChild = insertNode(node->rightChild, value);
    }
    return node; // Return unchanged node pointer
}

//Helper function for recursively deleting a node from the tree
Node* BinarySearchTree::deleteNodeRecursively(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }
    if (value < node->data) {
        node->leftChild = deleteNodeRecursively(node->leftChild, value);
    } else if (value > node->data) {
        node->rightChild = deleteNodeRecursively(node->rightChild, value);
    } else {
        if (node->leftChild == nullptr) {
            Node* temp = node->rightChild;
            delete node;
            return temp;
        } else if (node->rightChild == nullptr) {
            Node* temp = node->leftChild;
            delete node;
            return temp;
        }
        Node* temp = findMinValueNode(node->rightChild);
        node->data = temp->data;
        node->rightChild = deleteNodeRecursively(node->rightChild, temp->data);
    }
    return node;
}

//Helper function for searching a node in the tree
bool BinarySearchTree::searchNode(Node* node, int value) const {
    if (node == nullptr) {
        return false;
    }
    if (value < node->data) {
        return searchNode(node->leftChild, value);
    } else if (value > node->data) {
        return searchNode(node->rightChild, value);
    }
    return true; // Found value
}

//Helper function to find the node with minimum value
Node* BinarySearchTree::findMinValueNode(Node* node) {
    Node* current = node;
    while (current && current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}

//Helper function for in-order traversal display
void BinarySearchTree::displayInOrder(Node* node) const {
    if (node) {
        displayInOrder(node->leftChild);
        cout << node->data << " ";
        displayInOrder(node->rightChild);
    }
}

//Helper function for pre-order traversal display
void BinarySearchTree::displayPreOrder(Node* node) const {
    if (node) {
        cout << node->data << " ";
        displayPreOrder(node->leftChild);
        displayPreOrder(node->rightChild);
    }
}

//Helper function for post-order traversal display
void BinarySearchTree::displayPostOrder(Node* node) const {
    if (node) {
        displayPostOrder(node->leftChild);
        displayPostOrder(node->rightChild);
        cout << node->data << " ";
    }
}

//Helper function to get the height of a node
int BinarySearchTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
}

//Helper function to get the balance factor of a node
int BinarySearchTree::getBalanceFactor(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->leftChild) - getHeight(node->rightChild);
}

//Helper function to check if the tree is AVL recursively
bool BinarySearchTree::isAVLRecursively(Node* node) const {
    if (node == nullptr) {
        return true;
    }

    int balanceFactor = getBalanceFactor(node);
    if (abs(balanceFactor) > 1) {
        return false; // Unbalanced
    }

    return isAVLRecursively(node->leftChild) && isAVLRecursively(node->rightChild);
}
