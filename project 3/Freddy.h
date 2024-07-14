#ifndef FREDDY_H //<- Helps when calling a class
#define FREDDY_H//<- Defines the class

using namespace std;

class Freddy
{
    public: //where functions go
    //constructors:
    //default
    Freddy();//constructor: new object w/ banlance=0
    //overloaded/parameterized
    Freddy(int initial_health);// new object
    //--------------------------------
    //accessors or mutators 
    //accessors -> get something, return 
    //mutators -> access and then update
    //----------------------------------
    //mutators: only way to motify the contents of the balance after creating the object
    void re_charge(int amount); //mutator
    void damage(int amount); //mutator
    //void add_interest(double rate);
    //----------------------------------
    //Accessors:
    int getFreddyHealth(); //accessor

private: //where variables go
    int health; //where the balance resides

};
#endif