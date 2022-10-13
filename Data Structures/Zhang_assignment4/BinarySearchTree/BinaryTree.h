#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdlib.h>

template <class T>
struct Node
{
    T key;
    Node<T>* left;
    Node<T>* right;
}; // Node

template <class T>
class BinaryTree {
    public:
    BinaryTree();
    ~BinaryTree();
    void putItem(Node<T>*&, T &);
    void insert(T &);
    void Destroy(Node<T>*&);
    void recursiveDelete(Node<T>*&, T &);
    void deleteNode(Node<T>*&);
    void getPredecessor(Node<T>*, T&);
    void deleteItem(T &);
    void getItem(Node<T>*, T &, bool&) const;
    void retrieve(T &, bool &) const;
    void prePrint(Node<T>*) const;
    void preOrder() const;
    void orderPrint(Node<T>*) const;
    void inOrder() const;
    void postPrint(Node<T>*) const;
    void postOrder() const;
    int getLength() const;
    int countNodes(Node<T>*) const;
    int singleParents(Node<T>*) const;
    int getNumSingleParent() const;
    int leafNodes(Node<T>*) const;
    int getNumLeafNodes() const;
    T sumSubtree(Node<T>*, T, T&) const;
    Node<T>* subtreeNode(Node<T>*&, T & key) const;
    T getSumofSubtrees(T &, T &) const;
    private:
    Node<T>* root;
    
}; // BinaryTree
#endif
