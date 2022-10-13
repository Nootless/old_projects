#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include "ListNode.h"
#include <string.h>
class SortedLinkedList 
{

public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType);
    void deleteItem(ItemType);
    int searchItem(ItemType);
    ItemType GetNextItem();
    void ResetList();
    void merge(std::string);
    void delAltNodes();
    void findCommonVals(std::string);
    void printItems() const;

private:
    ListNode* head;
    ListNode* currentPos;
    int size;
};

#endif