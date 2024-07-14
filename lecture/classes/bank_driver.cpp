//this is how to actually access yout class

#include "bank.h"//link driver and cpp file  
#include <iostream>
using namespace std;


int main()
{
   
    bank account_1 = bank();// calling default constructor
    double current_balance= account_1.getbalance();
    cout<< "account 1 balance:"<< current_balance<<endl;
    
    double initial_amount = 1000;
    bank account_2 = bank(initial_amount);
    cout<<"account 2 balance:"<< account_2.getbalance()<<endl;
    
    return 0;

    //multiple file compile 
}