#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison { GREATER, LESS, EQUAL };

class ItemType
{
public:
    
    ItemType();
    Comparison compareTo(ItemType);
    int getValue() const;
    void initialize(int);
private:
    int value;

};

#endif