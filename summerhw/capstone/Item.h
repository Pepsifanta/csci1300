#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item {
private:
    string item_;
    int cost_;
    Item* nextItem; // Pointer to the next item

public:
    Item();
    Item(string item_name, int cost);

    string getItem();
    void setItem(string item_name);

    int getCost();
    void setCost(int cost);

    // Get the next item in the linked list
    Item* getNextItem();

    // Set the next item in the linked list
    void setNextItem(Item* next);
};
#endif