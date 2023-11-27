/***************************************************************
 * Author: Vincent Bardinelli
 * Date: November 26, 2023
 * Class: CSDP 250 Fall 2023
 * Program Purpose:
 * This is the main program that utilizes the BinarySearchTree
 * class. It generates random numbers, constructs a binary search
 * tree, performs various tree traversals,
 * allows user interaction for node deletion, and checks if the
 * tree is an AVL tree.
 ***************************************************************/
#include "BinarySearchTree.h"
#include <iostream>
#include <ctime> //For time

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    BinarySearchTree bst;

    cout << "\nThis is a demonstration of specific functions of the BinarySearchTree class." << endl;
    cout << "The system will generate 35 random numbers between 0 and 99, and makes a linked list." << endl;
    cout << "A binary tree is then setup using a linked list. It is displayed with in order DFS." << endl;
    cout << "You will then be prompted to delete a node, and the tree will display with the update." << endl;
    cout << "Finally, the program will test if the tree is an AVL tree or not, using a recursive function." << endl;

    int generatedNumbers[35];

    //Create at least 35 random natural numbers less than 100 and insert them into the BST
    for (int i = 0; i < 35; ++i) {
        generatedNumbers[i] = rand() % 100;
        bst.insert(generatedNumbers[i]);
    }

    //Display the BST using in-order traversal
    cout << "\nIn-order traversal: ";
    bst.displayInOrder();

    int numToDelete;
    bool validInput = false;

    do {
        cout << "\nEnter a number to delete from the tree: ";
        cin >> numToDelete;

        //Check if the entered number is in the generated numbers
        for (int i = 0; i < 35; ++i) {
            if (generatedNumbers[i] == numToDelete) {
                validInput = true;
                bst.deleteNode(numToDelete);
                break;
            }
        }

        if (!validInput) {
            cout << "Number not found in the tree. Please try again." << endl;
        }
    } while (!validInput);

    cout << "Post-order traversal after deletion: ";
    bst.displayPostOrder();

    //Check if the tree is an AVL tree
    cout << "\nIs the tree an AVL tree? " << (bst.isAVL() ? "Yes" : "No") << endl;

    return 0;
}
