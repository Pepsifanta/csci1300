// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 3 - Problem 3
#include <iostream>

using namespace std;

int main() 
{
    //added bool so the code won't print multiple outputs to the user
  bool valid_input = false;
    char size ;
      int topping;
   //prompt user for the size
    cout << "What size pizza would you like to order?" << endl;
    cin >> size;
    //if user doesn't enter the letters S,M, or L it is not valid
         if (( size != 'S' ) && ( size != 'M' ) && ( size != 'L' ))
    {
        cout << "Please enter a valid input." << endl;
    }
   
   //variables in the code
   double base; 
   double per_top;

  // if statement for small pizza, what prices that would be
 if ( size == 'S' ) 
    {
        base= 4.99;
        per_top = 0.75 ;
    valid_input = true;
    }
    // prices for medium sized pizza
    else if ( size == 'M') 
    {
        base = 5.99;
        per_top= 1.50;
     valid_input = true; //apart of the bool
    }
    //if the user input a Large pizza
     else if ( size == 'L') 
    {
        base = 6.99;
        per_top= 2.25;
          valid_input = true;
    }
    if (valid_input)
    //prompt for how many toppings the user whats to add 
    cout << "How many toppings do you want?" << endl;
    cin >> topping;
    //if the user inputs a negative it will not work
        if (topping < 0 && valid_input)
    {
        cout << "Please enter a valid input." << endl;
    }
    //output and cost of users pizza based on size and price of toppings all together
    else if (valid_input)
 cout << "Your total is $"<<base+per_top*topping<<endl;
    
    return 0;
    
    
}