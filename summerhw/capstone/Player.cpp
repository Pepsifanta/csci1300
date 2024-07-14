#include "Player.h"
#include <iostream>
#include <ctime>

using namespace std;

// Player class implementation
Player::Player()
{
    player_health = 0;
    coins = 0;
}

Player::Player(int initial_health, int initial_coins)
{
    player_health = initial_health;
    coins = initial_coins;
}

void Player::p_damage(int amount)
{
    const int PENALTY = 10;
    if (amount > player_health)
    {
        player_health = player_health - PENALTY;
    }
    else
    {
        player_health = player_health - amount;
    }
}

const int Player::getPlayerHealth()
{
    return player_health;
}

int Player::getCoins()
{
    return coins;
}

void Player::setCoins(int newCoins)
{
    coins = newCoins;
}

void Player::addItem(Item item)
{
    ownedItems.push_back(item);
}

void Player::removeItem(int index)
{
    ownedItems.erase(ownedItems.begin() + index);
}

vector<Item> Player::getItemsOwned()
{
    return ownedItems;
}

// Freddy class implementation
Freddy::Freddy()
{
     health=10;
    // Constructor for Freddy class
    // Initialize Freddy-specific attributes here, if needed
}

Freddy::Freddy(int initial_health)
{
     health= initial_health;
}

void Freddy::re_charge(int amount)
{
    health = health + amount;
    // Freddy-specific implementation for recharge
}

void Freddy::damage(int amount)
{
     //what happens when they withdraw too much
    const int PENALTY = 10;
    if(amount > health)//if we withdraw more $ then $ stored then you get pentalty
    {
        health = health - PENALTY;
    }
    else 
    {
        health = health - amount;//withdraw amount is less then balance, regular oppuration
    }
    // Freddy-specific implementation for taking damage
}

int Freddy::getFreddyHealth()
{
    // Freddy-specific implementation for getting health
    return health; // Replace with actual implementation
}
