// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 4 - Problem 2
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    //prompt user for input 
    int int_val;
    cout << "Enter  a value between 1 and 1000:" << endl;
    cin >> int_val;
    //if the user input is not between 1 and 1000 it will be invalid 
    while ( (int_val <= 1) || (int_val >=1000)) 
{
    cout << "Invalid input." << endl;
        cout << "Enter  a value between 1 and 1000:" << endl;
    cin >> int_val;
}
//
cout << int_val<< endl;
    while (int_val!=1)
    {
        //because the % remainder will be 0 when the number is even
        if (int_val % 2 == 0)
        {
            // if the input is even it gets divided by 2
            int_val = floor(int_val / 2);
            cout << int_val<< endl;
        }
        else 
        {
            // if input is odd multiply input by 3 and add 1
        int_val = int_val*3 + 1;
        cout << int_val<< endl;
      
        }

    }
    
}