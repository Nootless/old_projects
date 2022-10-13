#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"

using namespace std;

SortedLinkedList::SortedLinkedList() {
    ResetList();
    head = NULL;
    size = 0;

} // constructor

SortedLinkedList::~SortedLinkedList() {
    
    ListNode* temp = NULL; 
    while (head != NULL) // goes through all nodes
    {
        temp = head;
        head = head->next;
        delete temp;
    }
} // Destructor

int SortedLinkedList::length() const {
    return size;
} // length

void SortedLinkedList::insertItem(ItemType item) {
    
    if (size == 0) {
        // Case: list is empty
        head = new ListNode;
        head->item = item;
        size++;
    } else if (this->searchItem(item) != -1) {
        // Case: prevents duplicates    
        cout << "Sorry. You cannot insert the duplicate item." << endl;

    } else if (item.compareTo(head->item) == LESS) {
        // Case: putting at front of list
        ListNode* temp = new ListNode;
        temp->item = item; // new node that reassigns the head to itself
        temp->next = head;
        head = temp;
        size++;

    } else {
        // default case
        ListNode* preloc = NULL;
        ListNode* loc = head;
        ListNode* temp = new ListNode;
        temp->item = item;
    
        // used to get the node before and after the inserted node
        while (loc != NULL) {
            if(item.compareTo(loc->item) == LESS) {
                break;   
            } else {
                preloc = loc;
                loc = loc->next;
            }
        } // while
        // assigns the node into the ordered position
        preloc->next = temp;
        temp->next = loc;
        size++;
    }
} // insert

void SortedLinkedList::deleteItem(ItemType item) {

    // Case: non existant list
    if (head == NULL)
    {
        cout << "You cannot delete from an empty list." << endl;
    } else if (this->searchItem(item) == -1) {
        // Case: non-existant item
        cout << "Item not found." << endl;
    } else if (size == 1) {
        // Case: size is 1
        delete head;
        head = NULL;
        size--;

    } else if (item.compareTo(head->item) == EQUAL) {
        // Case: deleting first element
        ListNode* temp = head; // allows the previous head to be deleted 
        head = head->next; // moves the head one over
        delete temp;
        size--;

    } else {
        // default case
        ListNode* preloc = head;
        ListNode* loc = head;
        ListNode* temp;

        // goes through until they find the item to be deleted
        while (loc != NULL) {
            if (item.compareTo(loc->item) == EQUAL)
            {
                // sets the next between the 
                // pre location and post location
                // deletes the item in between
                temp = loc;
                loc = loc->next;
                preloc->next = loc;
                delete temp;
                break;
            } else {
                // shift place over by one
                preloc = loc;
                loc = loc->next;
            }
        } // while
        size--;
    } // if
    
} // delete

int SortedLinkedList::searchItem(ItemType item) {
    int index = 0;  
    ListNode* temp = head;

    // looks through the entire list for the value and
    // returns index if found, -1 if not
    while(temp != NULL) {
        if (temp->item.compareTo(item) == EQUAL) {
            return index;
        } // if
        temp = temp->next;
        index++;
    } // while

    return -1;

} // search

// Need to add return null
ItemType SortedLinkedList::GetNextItem() {
    // special cases:
    // List is empty
    // The current position is at the end of the list
    
    // gives it an error checking value
    ItemType nextItem;
    nextItem.initialize(-1);
    
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else if (currentPos == NULL) {
        // starts the count from the start
        currentPos = head;
        nextItem = currentPos->item;
    } else if(currentPos->next == NULL) {
        cout << "The end of the list has been reached" << endl;

    } else {
        // shifts current position and gets item
        currentPos = currentPos->next;
        nextItem = currentPos->item;
    }
    return nextItem;
} // GetNextItem

void SortedLinkedList::ResetList() {
    currentPos = NULL;
} // reset list

void SortedLinkedList::merge(string linkList) {
    int val = 0;
    int skip = 0;
    stringstream ss;
    ItemType item;
    ss << linkList;
    // goes through all the ints
    while (ss >> val) {
        item.initialize(val);
        if (this->searchItem(item) != -1 && skip != 1) {
            // prevents duplicates    
            cout << "Sorry. You cannot insert the duplicate item." << endl;
            skip = 1;
        }
    } // while O(n^2)
    // resets the iterator flag for the string stream and go through it again
    ss.clear();
    ss << linkList;
    while (ss >> val && skip == 0) {
        item.initialize(val);
        insertItem(item);
    } // while O(n^2)

    // Overall: O(2n^2)
} // merge

void SortedLinkedList::delAltNodes() {
        ListNode* temp = head;
        ListNode* iter = temp;
        while (temp->next != NULL) {
            // moves the iterator up and deletes every other
             iter = temp->next;
             temp = iter-> next;
             deleteItem(iter->item);
        }
    
} // deleteAlternateNodes

void SortedLinkedList::findCommonVals(string linklist) {
    stringstream ss;
    int val = 0;
    int found = 0;
    int headValue;
    ListNode* temp = head;
    ItemType item;

    ss << linklist;
    // compares all the values from the user input to the list
    // removes the ones that are not shared between the two
    while (temp != NULL) {

        while(ss >> val) {
            item.initialize(val);
            // shows that an item is found so it does not get deleted
            if (temp->item.compareTo(item) == EQUAL)
            {
                found = 1;
            }
        } // while

        if (found == 0) {
            deleteItem(temp->item);    
        } // if
        // reset for next iteration
        temp = temp->next;
        found = 0;
        ss.clear();
        ss << linklist;

    } // while 
} // findCommonValues

void SortedLinkedList::printItems() const { 
    string itemList = "";
    ListNode* temp = head;
    // loops through and concats all of the values 
    // into one string
    while (temp != NULL)
    {
        itemList += to_string(temp->item.getValue());
        itemList += " ";
        temp = temp->next;
    }
    cout << itemList << endl;
} // printItems