// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 3 - Problem 2
#include <iostream>

using namespace std;

int main() 
{
  //variable and prompt user for their budget
    double budget;
   
    cout << "What is your budget?" << endl;
    cin >> budget;
    //if user puts in negative input it will output invalid
     if ( budget <= 0 ) 
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    //prompt user for which type of transportation they would like 
     char transport;

    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> transport;
   //if user input is not A, T, or B capitalized it will be invalid 
  if (( transport != 'A' ) && ( transport != 'T' ) && ( transport != 'B' ))
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    //put in how much each mode of transport costs into a variable
int B = 175.25;
int T = 240.66;
int A = 350.93;
   
    // depending on user input if they have enough money for the specific transport they want
    if ( budget >= 175.25 ) 
    {
        cout << "Yes, this vacation is within your budget!" << endl;
    }
    //numbers are for how much the transports each cost in the order, bus, train, then air 
     else if ( budget >= 240.66 ) 
    {
        cout << "Yes, this vacation is within your budget!" << endl;
    }
    
     else if ( budget >= 350.93 ) 
    {
        cout << "Yes, this vacation is within your budget!" << endl;
    }
    
     else
     //if user input for their budget is less then the cost of the transport they chose it will output out of budget
    {
        cout << "Sorry, this vacation is outside your budget." << endl;
    }

    return 0;
}