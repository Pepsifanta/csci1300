#include <iostream>
//Include the libraries for the codes needed to run 
#include <cmath>

using namespace std;

int main(){
    // make a variable for the number of bolts the user has
int bolts;
// creat correct prompt for user input
cout << "Enter the number of Bolts:"<<endl;
//enter that input into variable
cin>> bolts;
//make equation of how many times 23 bolts can go into making amount of gold
int gold= bolts/23;
//divide then take remainder of that with moduels
bolts = bolts%23;
// repeat with how many total gold can be made into gems using same method, divide then take remainder
int gems= gold/13;
gold = gold%13;
//output prompt with correct words then input of numbers within the sentences
cout << gems << " Gem(s) "<< gold << " GoldCoin(s) "<< bolts<< " Bolt(s) "<<endl;
}