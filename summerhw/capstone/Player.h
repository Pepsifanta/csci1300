#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Enemy.h"
#include "Item.h"

// Avoid using namespace std in header files, so remove it here

//Used inheritance in this header 
class Character
{
protected:
    int player_health;
    int coins;
    int health;
    std::vector<Item> ownedItems;
    std::vector<Enemy> allEnemies;
    std::vector<Enemy> viewedEnemies;

public:
    int getPlayerHealth() const { // Make the function const to indicate it doesn't modify the object
        return player_health;
    }

    void p_damage(int amount) {
        const int PENALTY = 10;
        if (amount > player_health) {
            player_health = player_health - PENALTY;
        } else {
            player_health = player_health - amount;
        }
    }

    int getCoins() const { // Make the function const to indicate it doesn't modify the object
        return coins;
    }

    void setCoins(int newCoins) {
        coins = newCoins;
    }

    std::vector<Item> getItemsOwned() const {
        return ownedItems;
    }

     void addItem(Item item) {
        ownedItems.push_back(item);
    }

    void removeItem(int index) {
        if (index >= 0 && index < ownedItems.size()) {
            ownedItems.erase(ownedItems.begin() + index);
        }
    }
    // Character member functions here
};

class Player : public Character {
public:
    Player(); // Default constructor
    Player(int initial_health, int initial_coins); // Overloaded constructor

    void p_damage(int amount);

    const int getPlayerHealth();
    int getCoins();
    void setCoins(int newCoins);

    std::vector<Item> getItemsOwned();
    void addItem(Item item);
    void removeItem(int index);
};

class Freddy : public Character {
public:
    Freddy(); // Default constructor
    Freddy(int initial_health); // Overloaded constructor

    void re_charge(int amount);
    void damage(int amount);

    int getFreddyHealth();
};

#endif
