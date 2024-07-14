#include "Freddy.h"
#include <iostream>
using namespace std;

//copy and paste all the public functions over
Freddy::Freddy()
{
    health=10;// base value is = zero
    //give all the functions their own scope
}


Freddy::Freddy(int initial_health)
{
    health= initial_health;//balance set to user input
}
void Freddy::re_charge(int amount) 
{
    health = health + amount;//adds to balance
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
    
}
// void Freddy::add_interest(double rate)
// {
//     //calculation for interest
//     double amount = balance * (rate/100);
//     deposit(amount);//calling other class function deposit
// }
int Freddy::getFreddyHealth() //accessor
{
    return health; //returning private variable
}

// int main()
// {
    
// }