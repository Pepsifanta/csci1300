#ifndef BANK_H //<- Helps when calling a class
#define BANK_H//<- Defines the class

using namespace std;

//bank_account class:
//Operations:
//-Deposits funds 
//-Withdraws funds
//-Add interest
//-Check current balance (implied operation)

class bank
{
    public: //where functions go
    //constructors:
    //default
    bank();//constructor: new object w/ banlance=0
    //overloaded/parameterized
    bank(double initial_balance);// new object
    //--------------------------------
    //accessors or mutators 
    //accessors -> get something, return 
    //mutators -> access and then update
    //----------------------------------
    //mutators: only way to motify the contents of the balance after creating the object
    void deposit(double amount); //mutator
    void withdraw(double amount); //mutator
    void add_interest(double rate);
    //----------------------------------
    //Accessors:
    double getbalance() const; //accessor

private: //where variables go
    double balance; //where the balance resides

};
#endif