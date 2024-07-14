// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 2
#include <iostream>
#include <cassert>

using namespace std;
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
    }
        // if the second part of user input is equal to the following numbers, valid will be true
     if (user_input [1] == '0' ||user_input [1] == '1' || user_input [1] == '2' || user_input [1] == '3' || user_input [1] == '4' || user_input [1] == '5' ||user_input [1] == '6' ||user_input [1] == '7' ||user_input [1] == '8' ||user_input [1] == '9') 
        {
        valid = true; 
        }
        else 
        {
            valid = false; 
            return valid; 
        }
         return valid;
    } 

//bool function named isValidTune
bool isValidTune(string user_input) 
{
    //start bool as true 
 bool valid = true;
 // if the user input length is less then 2 its false 
if(user_input.length()<2) 
{
  valid = false;  
}
//for loop to check user input, every two 
 for (int i=0; i< user_input.length(); i+=2)
 {
    // since bool is originally true it will stay true
    //go to if statement that says if the user input doesnt pass isValidNote for every two substrings it is false
  if (!isValidNote(user_input.substr(i,2)))
  {
 valid = false; 
  }
 }
 return valid; 
}

int main ()
{
  assert(isValidTune("A2B4C7")==true);
  assert(isValidTune("M5D2E1")==false);
  assert(isValidTune("A5D2E11")==false);
  assert(isValidTune("Hello1300")==false);
}