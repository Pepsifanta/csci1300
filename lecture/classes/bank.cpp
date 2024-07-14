#include "bank.h"
#include <iostream>
using namespace std;

//copy and paste all the public functions over
bank::bank()
{
    balance=0;// base value is = zero
    //give all the functions their own scope
}


bank::bank(double initial_balance)
{
    balance= initial_balance;//balance set to user input
}
void bank::deposit(double amount) 
{
    balance = balance + amount;//adds to balance
}
void bank::withdraw(double amount)
{   
    //what happens when they withdraw too much
    const double PENALTY = 10;
    if(amount > balance)//if we withdraw more $ then $ stored then you get pentalty
    {
        balance = balance - PENALTY;
    }
    else 
    {
        balance = balance - amount;//withdraw amount is less then balance, regular oppuration
    }
    
}
void bank::add_interest(double rate)
{
    //calculation for interest
    double amount = balance * (rate/100);
    deposit(amount);//calling other class function deposit
}
double bank::getbalance() //accessor
{
    return balance; //returning private variable
}

