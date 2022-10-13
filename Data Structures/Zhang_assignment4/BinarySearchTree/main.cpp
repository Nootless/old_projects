#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include "BinaryTree.h"

using namespace std;

void printIntro() { // used to clean up main
    cout << "Enter tree type (i - int, f - float, s - std:string): ";
} // printIntro
void printCommands() { // prints commands
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n) "
         << "pre-order (p), post-order (o), getNumSingleParent (s), "
         << "getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;
} // printCommands

int main(int argc, char* argv[]) 
{
    ifstream ifs(argv[1], ios::in);
    if (!ifs) { // file check
        cerr << "Error: File has failed to open or does not exist." << endl;
        exit(1);
    } // if
    
    char command;
    char treeType = 'a';
    // after file selection in command line
    
    printIntro();
    cin >> treeType; // type given by user
    
    switch (treeType) { 
        // switch based on what type of tree
        // int, float, string
        case 'i': {
            BinaryTree<int> tree;
            int item;

            while (ifs >> item) {
                tree.insert(item);
            } // while
            printCommands();

            while (command != 'q') 
            {
                cout << "Enter a command: ";
                cin >> command;
                int val = 0;
                switch (command) {
                    case 'i': { // insert through user given value and print in order
                        cout << "Item to insert: ";
                        cin >> val;
                        tree.insert(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'd': { // delete and then print in order
                        cout << "Item to delete: ";
                        cin >> val;
                        tree.deleteItem(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'r': { // retrieve and return if item is found
                        bool found;
                        cout << "Item to be retrieved: ";
                        cin >> val;
                        tree.retrieve(val, found);
                        if (found) {
                            cout << "Item found in tree." << endl;
                        } else {
                            cout << "Item not in tree." << endl;
                        } // if
                        cout << endl;
                        break;
                    }
                    case 'l': { // gives length of tree
                        cout << "Tree Length: " << tree.getLength(); 
                        cout << endl << endl;
                        break;
                    }
                    case 'n': { // print in order
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'p': { // print pre order
                        cout << "Pre-Order: ";
                        tree.preOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'o': { // print in post order
                        cout << "Post-Order: ";
                        tree.postOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 's': { // print number of single parents
                        cout << "Number of Single Parents: " 
                             << tree.getNumSingleParent() << endl;
                        cout << endl;
                        break;
                    }
                    case 'f': { // prints number of leaf nodes
                        cout << "Number of leaf Nodes: " 
                             << tree.getNumLeafNodes() << endl;
                        cout << endl;
                        break;
                    }
                    case 't': { // gets the sum of sub nodes of the given value
                        cout << "Item to get sum of subtree: ";
                        cin >> val;
                        bool found;
                        tree.retrieve(val, found);
                        if (found) {
                            int val2 = 0;
                            tree.getSumofSubtrees(val, val2);
                            cout << "Sum of Subtrees: " << val2 << endl << endl;
                        } else {
                            cout << "Item not in tree." << endl << endl;
                        }
                        break;
                    }
                    case 'q': {
                        cout << "Quitting program..." << endl;
                        break;
                    }
                    default: {
                        cout << "Command not recognized. Try again" << endl;
                        cout << endl; 
                        break;
                    }
                } // switch
            } // while
            
            break;
        }
        case 'f': {
            BinaryTree<float> tree;
            float item;

            while (ifs >> item) { // inserts item
                tree.insert(item);
            } // while
            printCommands();

            while (command != 'q') 
            {
                cout << "Enter a command: ";
                cin >> command;
                float val = 0;
                switch (command) {
                    case 'i': { // insert and print in order
                        cout << "Item to insert: ";
                        cin >> val;
                        tree.insert(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'd': { // delete and print in order
                        cout << "Item to delete: ";
                        cin >> val;
                        tree.deleteItem(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'r': { // retrieve and print if found
                        bool found;
                        cout << "Item to be retrieved: ";
                        cin >> val;
                        tree.retrieve(val, found);
                        if (found) {
                            cout << "Item found in tree." << endl;
                        } else {
                            cout << "Item not in tree." << endl;
                        } // if
                        cout << endl;
                        break;
                    }
                    case 'l': { // print length
                        cout << "Tree Length: " << tree.getLength();
                        cout << endl << endl;
                        break;
                    }
                    case 'n': { // print in order
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'p': { // print pre order
                        cout << "Pre-Order: ";
                        tree.preOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'o': { // print post order
                        cout << "Post-Order: ";
                        tree.postOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 's': { // print number of single parents
                        cout << "Number of Single Parents: " 
                             << tree.getNumSingleParent() << endl;
                        cout << endl;
                        break;
                    }
                    case 'f': { // print number of leaf nodes
                        cout << "Number of leaf Nodes: " 
                             << tree.getNumLeafNodes() << endl;
                        cout << endl;
                        break;
                    }
                    case 't': { // print the sum of the subnodes of the inputtted node
                        cout << "Item to get sum of subtree: ";
                        cin >> val;
                        bool found;
                        tree.retrieve(val, found);
                        if (found) {
                            float val2 = 0;
                            tree.getSumofSubtrees(val, val2);
                            cout << "Sum of Subtrees: " << val2 << endl << endl;
                        } else {
                            cout << "Item not in tree." << endl << endl;
                        }
                        break;
                    }
                    case 'q': { // quit
                        cout << "Quitting program..." << endl;
                        break;
                    }
                    default: {
                        cout << "Command not recognized. Try again" << endl;
                        cout << endl; 
                        break;
                    }
                } // switch
            } // while
            break;
        }
        case 's': {
            BinaryTree<string> tree;
            string item;

            while (ifs >> item) { // inserts item in to tree
                tree.insert(item);
            } // while
            printCommands();

            while (command != 'q') 
            {
                cout << "Enter a command: ";
                cin >> command;
                string val;
                switch (command) {
                    case 'i': { // insert and print
                        cout << "Item to insert: ";
                        cin >> val;
                        tree.insert(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'd': { // delete and print
                        cout << "Item to delete: ";
                        cin >> val;
                        tree.deleteItem(val);
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'r': { // retrieve and status of found
                        bool found;
                        cout << "Item to be retrieved: ";
                        cin >> val;
                        tree.retrieve(val, found);
                        if (found) {
                            cout << "Item found in tree." << endl;
                        } else {
                            cout << "Item not in tree." << endl;
                        } // if
                        cout << endl;
                        break;
                    }
                    case 'l': { // prints length
                        cout << "Tree Length: " << tree.getLength();
                        cout << endl << endl;
                        break;
                    }
                    case 'n': { // print in order
                        cout << "In-Order: ";
                        tree.inOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'p': { // print pre order
                        cout << "Pre-Order: ";
                        tree.preOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 'o': { // print post order
                        cout << "Post-Order: ";
                        tree.postOrder();
                        cout << endl << endl;
                        break;
                    }
                    case 's': { // print number of single parents
                        cout << "Number of Single Parents: " 
                             << tree.getNumSingleParent() << endl;
                        cout << endl;
                        break;
                    }
                    case 'f': { // print number of leaf nodes
                        cout << "Number of leaf Nodes: " 
                             << tree.getNumLeafNodes() << endl;
                        cout << endl;
                        break;
                    }
                    case 't': { // prints the sum of the sub nodes of user given node
                        cout << "Item to get sum of subtree: ";
                        cin >> val;
                        bool found;
                        tree.retrieve(val, found);
                        if (found) {
                            string val2;
                            tree.getSumofSubtrees(val, val2);
                            cout << "Sum of Subtrees: " << val2 << endl << endl;
                        } else {
                            cout << "Item not in tree." << endl << endl;
                        }
                        break;
                    }
                    case 'q': {
                        cout << "Quitting program..." << endl;
                        break;
                    }
                    default: {
                        cout << "Command not recognized. Try again" << endl;
                        cout << endl; 
                        break;
                    }
                } // switch
            } // while
            
            break;
        }
        default: { // invalid input at program entry
            cerr << "Error: Invalid tree type provided." << endl;
            exit(1);
            break;
        } // default 
    } // switch
} // main