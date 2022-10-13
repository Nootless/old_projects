#include "ItemType.h"
#include <stdio.h>

ItemType::ItemType() {
    value = 0;
} // constructor

Comparison ItemType::compareTo(ItemType item) {
    // compares values to check equality
    if (value > item.getValue())
    {
        return GREATER;
    } else if (value < item.getValue()) {
        return LESS;
    } else if (value == item.getValue()) {
        return EQUAL;
    }
    // error handling
    return EQUAL;
} // compareTo

int ItemType::getValue() const{
    return value;
} // getValue

void ItemType::initialize(int num) {
    value = num;
}
