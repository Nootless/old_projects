#ifndef LISTNODE_H
#define LISTNODE_H

#include "ItemType.h"

struct ListNode 
{
public:
    ItemType item;
    ListNode *next;
};

#endif