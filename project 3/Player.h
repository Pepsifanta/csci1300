#ifndef PLAYER_H //<- Helps when calling a class
#define PLAYER_H//<- Defines the class

#include <vector>
#include "Enemy.h"
#include "Item.h"

using namespace std;

class Player
{
private: //where variables go
    int player_health; //where the balance resides
    int coins;
    vector<Item> ownedItems;
    vector<Enemy> allEnemies;
    vector<Enemy> viewedEnemies; 

public: //where functions go
    //constructors:
    //default
    Player();//constructor: new object w/ banlance=0
    //overloaded/parameterized
    Player(int initial_health, int initial_coins);// new object
 
    void p_damage(int amount); //mutator
    //void add_interest(double rate);
    //----------------------------------
    //Accessors:
    const int getPlayerHealth(); //accessor

    int getCoins();
    void setCoins(int newCoins);

    vector<Item> getItemsOwned();
    void addItem(Item item);
    void removeItem(int index);

// //reads whole txt file are fills with all possible enemy names 
//     vector<Enemy> getEnemyBody();
//     void randomEnemy(int index);

// //reads random encountered enemy and adds to new vector
//     vector<Enemy> getEncounteredEnemy();
//     void addEnemy(Enemy enemy);


};
#endif