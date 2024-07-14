#include "Player.h"
#include <iostream>
#include <ctime>
using namespace std;

//copy and paste all the public functions over
Player::Player()
{
    player_health=0;// base value is = zero
    coins = 0;
    //give all the functions their own scope
}


Player::Player(int initial_health, int initial_coins)
{
    player_health= initial_health;//balance set to user input
    coins = initial_coins;
}
void Player::p_damage(int amount)
{   
    //what happens when they withdraw too much
    const int PENALTY = 10;
    if(amount > player_health)//if we withdraw more $ then $ stored then you get pentalty
    {
        player_health = player_health - PENALTY;
    }
    else 
    {
        player_health = player_health - amount;//withdraw amount is less then balance, regular oppuration
    }
    
}
// void Freddy::add_interest(double rate)
// {
//     //calculation for interest
//     double amount = balance * (rate/100);
//     deposit(amount);//calling other class function deposit
// }
const int Player::getPlayerHealth() //accessor
{
    return player_health; //returning private variable
}

int Player::getCoins() {
    return coins;
}

void Player::setCoins(int newCoins) {
    coins = newCoins;
}

void Player::addItem(Item item) {
    ownedItems.push_back(item);
}

void Player::removeItem(int index)
{
    ownedItems.erase(ownedItems.begin()+index );
}

vector<Item> Player::getItemsOwned()
{
    return ownedItems;
}

// void Player::randomEnemy()
// {

// }

// void Player::addEnemy(Enemy enemy)
// {

// }