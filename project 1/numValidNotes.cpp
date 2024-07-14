// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 3
#include <iostream>
#include <cassert>

using namespace std;
// include past function isValidNote

bool isValidNote(string user_input) 
{
    // store true or false in valid 
    bool valid = false;
    //if the user input is length of 2 long, one letter and one number, continue
    if (user_input.length() == 2) 
    {
        // if the first user input letter is the following valid will be true (1). 
        if (user_input [0] == 'A' || user_input [0] == 'B'||user_input [0] == 'C'||user_input [0] == 'D' ||user_input [0] == 'E' ||user_input [0] == 'F' ||user_input [0] == 'G')
        {
            valid = true;
        }
        //if user input for the letter was not the above it will be false and not continue
        else 
        {
            valid = false; 
            // if false it will return false and not continue 
            return valid; 
        }
        // if the second part of user input is equal to the following numbers, valid will be true
     if (user_input [1] == '0' ||user_input [1] == '1' || user_input [1] == '2' || user_input [1] == '3' || user_input [1] == '4' || user_input [1] == '5' ||user_input [1] == '6' ||user_input [1] == '7' ||user_input [1] == '8' ||user_input [1] == '9') 
        {
        valid = true; 
        }
        //if the second part of user input was not the following numbers it will be false
        else 
        {
            valid = false; 
            // if false it will return false and not continue 
            return valid; 
        }
    } 
   
    return valid;
}

int numValidNotes(string user_input) 
{
  //new varaiable "agree" starts at 0 
 int agree= 0;
 int valid = true;

//for loop if the user input length is greater then or equal to i, i adds one
for (int i=0; i<= user_input.length(); i++)
 {
  // new varaible user_in for holding the value of the substring for user_input, between i and 2
  string user_in= user_input.substr(i,2);
  //if using previous isValidNote function is true agree goes up one
  if (isValidNote(user_in)==true)
  {
    //everytime they match or is correct to function isValidNote agree variable adds/ goes up by one
    agree ++;
  }
 }
 //output how manytimes they match or output agree
 return agree; 
}

int main ()
{
assert(numValidNotes("I love comp sci!")==0);
assert(numValidNotes("F4E2B0")==3);
assert(numValidNotes("ADB3M7G4F")==2);
assert(numValidNotes("HC6MB1")==2);
}
