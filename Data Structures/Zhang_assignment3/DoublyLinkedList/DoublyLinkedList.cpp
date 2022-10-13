#include "DoublyLinkedList.h"
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
} // constructor

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    NodeType<T>* temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    
} // destructor

template<class T>
void DoublyLinkedList<T>::insertItem(T &item){
    

    // special case: no items
    if(head == NULL) {
        NodeType<T>* node = new NodeType<T>;
        node->data = item; // assign new list
        head = node;
        tail = node;
        size++;
    } else if (item <= head->data) {
        NodeType<T>* node = new NodeType<T>;
        node->data = item;
        /// special case: adding to the beginning of the list
        node->next = head;
        head->back = node;
        head = node;
        size++;
    } else if (item >= tail->data) {
        NodeType<T>* node = new NodeType<T>;
        node->data = item;
        
        // special case: adding to the end of the list
        node->back = tail;
        tail->next = node;
        tail = node;
        size++;
    } else {
        // creates the pointers needed to sort through the list
        NodeType<T>* node = new NodeType<T>;
        node->data = item;
        NodeType<T>* preloc = NULL;
        NodeType<T>* loc = head;

        // used to get the node before and after the inserted node
        while (loc != NULL) {
            // checks if the nodes are at the location or not
            if(node->data <= loc->data) {
                break;   
            } else {
                preloc = loc;
                loc = loc->next;
            }
        } // while
        // Used to set the relationship between the values
        node->back = preloc;
        node->next = loc;
        preloc->next = node;
        loc->back = node;
        size++;
    }
} // insert item

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item){
    if(head == NULL) {
        cout << "You cannot delete from an empty list.";
    } else if (lengthIs() == 1 && item == head->data) {
        // if there is only one item left
        NodeType<T>* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        size--;
    } else if (item == head->data) {
        // moves head forward 1 and deletes original
        NodeType<T>* loc = head;
        head = head->next;
        head->back = NULL;
        delete loc;
        size--;

    } else if (item == tail->data) {
        // moves the tail backwards 1
        NodeType<T>* loc = tail;
        tail = tail->back;
        tail->next = NULL;
        delete loc;
        size--;

    } else {
        // set up of seach nodes
        NodeType<T>* preloc = NULL;
        NodeType<T>* loc = head;
        NodeType<T>* nextloc;
        bool found = 0;

        while(!(loc == NULL || found == 1)) {
            if (loc->data == item) {
                // combine the previous and the next
                // and remove the center
                nextloc = loc->next;
                nextloc->back = preloc;
                preloc->next = nextloc;
                delete loc;
                found = 1; // prevents loop from continuing
                size--;
            } else {
                // shift all the locations up one
                preloc = loc;
                loc = loc->next;
            }
        } // while

        if (!found) {
            // let user know item not in list
            cout << "Item not in list!" << endl;
        } // if
    } // if
} // delete item

template<class T>
int DoublyLinkedList<T>::lengthIs() const {
    return size;
} // length

template<class T>
void DoublyLinkedList<T>::print() {
    // create a temp node and cycle through the
    // list and print them out starting from head
    NodeType<T>* temp = head;    
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    } // while
    cout << endl;
} // print

template<class T>
void DoublyLinkedList<T>::printReverse() {
    // same as print() except starts from tail 
    NodeType<T>* temp = tail;    
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->back;
    } // while
    cout << endl << endl;
} // print reversed

template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &lower, T &upper) {

    // checks to make sure atleast one value is in range
    NodeType<T>* temp = head;
    NodeType<T>* hold;
    
    while(temp != NULL) {
        // checks if temp is within range to then delete said temp
        if (temp->data >= lower && temp->data <= upper) {
            hold = temp;
            temp = temp->next;
            deleteItem(hold->data);
        } else { // moves to next node
            temp = temp->next;
        } // if

    } // while

   
} // deleteSubsection

template<class T>
int DoublyLinkedList<T>::numOccurences(T &value) {
    NodeType<T>* temp = head;
    int counter = 0;
    // used to find out how many times a specific value occurs
    while (temp != NULL) {
        if (temp->data == value) { 
            counter++;
        } // if
        temp = temp->next;
    } // while
    return counter;
} // numOccurences

template<class T>
T DoublyLinkedList<T>::mode() {
    NodeType<T>* temp = head;
    T mode;
    int count = 0;
    int maxCount = 0;

    while (temp != NULL) {
        // gets the value with the most counts and
        // returns that
        count = numOccurences(temp->data);
        if (count > maxCount) {
            maxCount = count;
            mode = temp->data;
        } // if
        temp = temp->next;
    }
    return mode;
} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T>* temp = head;
    NodeType<T>* backNode;
    NodeType<T>* nextNode;
    int nodesLeft = lengthIs();
    // checks for odd number of nodes and also null
    // O(n)
    while(!(temp == NULL || nodesLeft == 1)) {
        backNode = temp;
        nextNode = temp->next;
        // assigns the outer bounds
        backNode->next = nextNode->next;
        nextNode->back = backNode->back;            
        nextNode->next = backNode;
        backNode->back = nextNode;
        
        // checks for nulls for outer bounds
        if (backNode->next != NULL) {
            // the nextNode's previous next
            backNode->next->back = backNode;
        } // if
        if (nextNode->back != NULL) {
            // the backNode's previous back
            nextNode->back->next = nextNode;
        } // if
        // checks for special case to move head or tail
        if(backNode == head) {
            head = nextNode;
        } // if
        if(nextNode == tail) {
            tail = backNode;
        }
        temp = temp->next;
        nodesLeft -= 2;
    } // while 
} // Swap Alternate

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<string>;
