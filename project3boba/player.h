#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
    private:
        string name_;
        int gold_;
        int health_;
        int thirst_;
        //low thirst he dies game ends 
        int row_;
        int col_;
        vector<string> inventory_;

    public:
        Player(string name);
        string getName();
        int getGold();
        int getHealth();
        int getThirst();

        vector<string> getInventory();
        
        void setEnergy(int energy);
        void setThirst(int thirst);
        void setGold(int gold);
        void setHealth(int health);
        void addToInventory(string item);
        void removeFromInventory(string item);
        void setPosition(int row, int col);
        bool isThirsty();
        void drinkBeverage();
        void displayInventory();
};

#endif