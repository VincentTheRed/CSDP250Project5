/***********************************************
 * Author: Vincent Bardinelli
 * Date: November 26, 2023
 * Class: CSDP 250 Fall 2023
 * Program Purpose:
 * This header file defines the structure of the Node and the BinarySearchTree class.
 * It includes methods for tree operations like insertion, deletion, search, and
 * traversals, as well as a method to check if the tree is an AVL tree.
 ***********************************************/
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct Node {
    int data; //Node data
    Node* leftChild; //Pointer to left child
    Node* rightChild; //Pointer to right child
    Node(int value); //Constructor for node
};

class BinarySearchTree {
public:
    BinarySearchTree(); //Constructor for BST
    ~BinarySearchTree(); //Destructor for BST
    void insert(int value); //Insert value into BST
    bool search(int value) const; //Search value in BST
    void deleteNode(int value); //Delete node from BST
    void displayInOrder() const; //In-order traversal of BST
    void displayPreOrder() const; //Pre-order traversal of BST
    void displayPostOrder() const; //Post-order traversal of BST
    bool isAVL() const; //Check if BST is AVL

private:
    Node* root; //Root of the BST
    Node* insertNode(Node* node, int value); //Helper for insert
    Node* deleteNodeRecursively(Node* node, int value); //Helper for deleteNode
    bool searchNode(Node* node, int value) const; //Helper for search
    Node* findMinValueNode(Node* node); //Find min value node
    int getHeight(Node* node) const; //Get height of a node
    int getBalanceFactor(Node* node) const; //Get balance factor of a node
    bool isAVLRecursively(Node* node) const; //Helper for isAVL
    void displayInOrder(Node* node) const; //Helper for displayInOrder
    void displayPreOrder(Node* node) const; //Helper for displayPreOrder
    void displayPostOrder(Node* node) const; //Helper for displayPostOrder
    void deleteTree(Node* node); //Helper for destructor
};

#endif
