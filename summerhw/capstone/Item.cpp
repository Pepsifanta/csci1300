#include "item.h"

// Default constructor
Item::Item()
{
    item_ = "";
    cost_ = 0;
    nextItem = nullptr; // Initialize the pointer to nullptr
}

Item::Item(string item_name, int cost)
{
    item_ = item_name;
    cost_ = cost;

    if (cost_ < 0) {
        cost_ = 0;
    }

    nextItem = nullptr; // Initialize the pointer to nullptr
}

string Item::getItem()
{
    return item_;
}

void Item::setItem(string item_name)
{
    item_ = item_name;
}

int Item::getCost()
{
    return cost_;
}

void Item::setCost(int cost)
{
    if (cost >= 0) {
        cost_ = cost;
    }
}

Item* Item::getNextItem()
{
    return nextItem;
}

void Item::setNextItem(Item* next)
{
    nextItem = next;
}