// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 4 - Problem 5
#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() 
{
   //prompt user for a height for their pyramid 
   int height;
// variable for alphabet starting point 
   char alphabet = 'a';
    cout << "Enter the height:" << endl;
     cin >> height;
    // if user input is less then 0 then it is invalid 
   if (height <= 0)  
      { 
        cout << "Invalid input." << endl;
    
    return 0;
      }
// goes down by one for the height 
    for (int i =0; i<height; i++)
    {
        
        // going to the side, each time it makes a new row it gets bigger by 2 
        for (int j=0; j<((2*i)+1);j++ )
        { 
          //output to user 
           cout<< char (alphabet);
          //resets alphabet to a
          if (alphabet=='z' )
          {
            alphabet = 'a';
          }
          // once reset the alphabet keeps going up by one 
          else
          {
            alphabet ++;
          }
        }
      
        cout <<endl;
    }

  return 0;


}
