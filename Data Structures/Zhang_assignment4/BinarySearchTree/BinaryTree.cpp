#include "BinaryTree.h"
#include <string>
#include <stdlib.h>
#include <iostream>

template <class T>
BinaryTree<T>::BinaryTree() {
    root = NULL; // set root to null
} // constructor

template <class T>
BinaryTree<T>::~BinaryTree() {
    Destroy(root); // destroys root and subnodes
} // destructor

template <class T>
void BinaryTree<T>::putItem(Node<T> *& node, T & item) {
    if (node == NULL) { // if the tree does not exist or leaf does not exist
        node = new Node<T>; // instantiates the 
        node->right = NULL;
        node->left = NULL;
        node->key = item;
    } else if (item == node->key) {
        std::cout << "Item already in tree." << std::endl;
    } else if (item < node->key) { // if the item is less than the current node
        putItem(node->left, item); // recursively creates the leaf
    } else if (item > node->key) { // if item is greater than current node
        putItem(node->right, item);
    } // if

} // putItem

template <class T>
void BinaryTree<T>::Destroy(Node<T>*& tree) {
    if (tree != NULL){ // deletes recursively through post order recursion
        // last nodes first 
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}
template <class T>
void BinaryTree<T>::insert(T & key) {
    putItem(root, key); // calls the putItem to recursively create item
} // insert

template <class T>
void BinaryTree<T>::recursiveDelete(Node<T>*&  tree, T & item) {
    if (tree == NULL) {
        std::cout << "Item not in tree." << std::endl;
    } else if (item  < tree->key) { // shift tree down left branch
        recursiveDelete(tree->left, item);
    } else if (item > tree->key) { // shift tree down right branch
        recursiveDelete(tree->right, item);
    } else if (item == tree->key) {
        deleteNode(tree); // node to delete found
    } // if
    
} // recursiveDelete

template <class T>
void BinaryTree<T>::deleteNode(Node<T>*& tree) {
    T data;
    Node<T>* temp = tree;
    if(tree->left == NULL) {
        tree = tree->right; // replace current node with right
        delete temp;
    } else if (tree->right == NULL) {
        tree = tree->left; // replace current node with left
        delete temp; 
    } else {
        getPredecessor(tree->left, data); 
        // gets the predecessor and replaces current node with it
        tree->key = data;
        recursiveDelete(tree->left, data); // delete replacing node
    }
} // deleteNode

template <class T>
void BinaryTree<T>::getPredecessor(Node<T>* tree, T& data) {
    // searches down entire right side of left branch
    while (tree->right != NULL) {
        tree = tree->right;
    } // while
    data = tree->key; // predecessor's info
} // getPredecessor

template <class T>
void BinaryTree<T>::deleteItem(T & key) {
    recursiveDelete(root, key);
} // deleteItem

template <class T>
void BinaryTree<T>::getItem(Node<T>* node, T & item, bool & found) const {
    if(node == NULL) {
        found = false; // item has not been found
    } else if (item < node->key) { // if item is less, move left
        getItem(node->left, item, found);
    } else if (item > node->key) { // if item is greater, move right
        getItem(node->right, item, found);
    } else {
        item = node->key; // setting the item and returning it as found
        found = true;
    }
} // getItem

template <class T>
void BinaryTree<T>::retrieve(T & item, bool & found) const {
    getItem(root, item, found); 
    // sets the item if found
    // NULL else
} // retrieve

template <class T>
void BinaryTree<T>::prePrint(Node<T> * tree) const {
    
    if(tree != NULL) { // prints first, starting with the parent
        std::cout << tree->key;
        std::cout << " ";
        prePrint(tree->left); // causes the left child to print
        prePrint(tree->right); // causes the right child to print
    } // if
 
} // prePrint

template <class T>
void BinaryTree<T>::preOrder() const {
    prePrint(root); // calls prePrint starting from root
} // preOrder

template <class T>
void BinaryTree<T>::orderPrint(Node<T> * tree) const {
    if(tree != NULL) {
        orderPrint(tree->left); // starts from the lowest value leaf and prints up
        std::cout << tree->key;
        std::cout << " ";
        orderPrint(tree->right); 
    } // if
} // orderPrint

template <class T>
void BinaryTree<T>::inOrder() const {
    orderPrint(root); // calls orderPrint starting from root
} // inOrder


template <class T>
void BinaryTree<T>::postPrint(Node<T>* tree) const {
    if(tree != NULL) {
        postPrint(tree->left);
        postPrint(tree->right);
        std::cout << tree->key; // prints node backwards 
        // bottom to up
        std::cout << " ";
    } // if
}

template <class T>
void BinaryTree<T>::postOrder() const {
    postPrint(root); // calls postPrint starting from root
}

template <class T>
int BinaryTree<T>::getLength() const {
    return countNodes(root); // calls countNodes to return
} // getLength

template <class T>
int BinaryTree<T>::countNodes(Node<T>* treeNode) const {
    if (treeNode == NULL) {
        return 0; // tree does not exist
    } else { // adds up all the nodes recursively
        return countNodes(treeNode->right) +
               countNodes(treeNode->left) + 1;
    } // if
} // countNodes

template <class T>
int BinaryTree<T>::singleParents(Node<T>* tree) const {
    if (tree == NULL) {
        return 0;
    } else if((tree->left == NULL && tree->right != NULL) ||
               (tree->left != NULL && tree->right == NULL)) {
        return 1; // only counts if only one child exists
    } else {
        // keeps going through the rest of the tree
        return singleParents(tree->right) + singleParents(tree->left);
    } // if
} // singleParents

template <class T>
int BinaryTree<T>::getNumSingleParent() const {
    return singleParents(root);
} // getNumSingleParent

template <class T>
int BinaryTree<T>::leafNodes(Node<T>* tree) const {
    // base case: no pointers down
    if (tree == NULL) {
        return 0;
        // case: leaf node
    } else if (tree->right == NULL && tree->left == NULL) {
        return 1;
    } else { // recursive case
        return leafNodes(tree->left) + leafNodes(tree->right);
    }
} // leafNodes

template <class T>
int BinaryTree<T>::getNumLeafNodes() const {
    return leafNodes(root);
} // getNumLeafNodes

template <class T>
T BinaryTree<T>::sumSubtree(Node<T>* tree, T subtreeVal, T& val) const {
    if(tree == NULL) {
        return 0;
    } else if (tree->key == subtreeVal) { // handles user inputted node
        // gets the sum of sub tree of current node
        val = sumSubtree(tree->left, subtreeVal, val) +
              sumSubtree(tree->right, subtreeVal, val);
        return val;
    } else {
        val = tree->key;
        // adds the current value of the node with the rest of the sub nodes
        return val + sumSubtree(tree->left, subtreeVal, val) +
               sumSubtree(tree->right, subtreeVal, val);
    } // if
} // sumSubtree

template <class T>
Node<T>* BinaryTree<T>::subtreeNode(Node<T>*& tree, T & key) const {
    if (tree->key == key) { // returns the reference to the tree
        return tree;
    } else if (key < tree->key) { // move left
        return subtreeNode(tree->left, key);
    } else if (key > tree->key) { // move right
        return subtreeNode(tree->right, key);
    } // if
    // error check
    return NULL;
} // subtreeNode

template <class T>
T BinaryTree<T>::getSumofSubtrees(T & key, T & val) const {
    Node<T>* temp = root; 
    Node<T>* temp2 = subtreeNode(temp, key); // gets the specific node
    // calls the recursive summation and returns te value
    val = sumSubtree(temp2,key,val);
    return val;

} // getSumofSubtrees


template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;