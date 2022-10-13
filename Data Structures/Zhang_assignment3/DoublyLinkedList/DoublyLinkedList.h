#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>

template<class T>
struct NodeType
{
    T data;
    NodeType<T>* next;
    NodeType<T>* back;
};

template<class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &);
    void deleteItem(T &);
    int lengthIs() const;
    void print();
    void printReverse();
    void deleteSubsection(T &, T &);
    T mode();
    void swapAlternate();
private:
    int numOccurences(T &);
    NodeType<T>* head;
    NodeType<T>* tail;
    int size;
};


#endif
