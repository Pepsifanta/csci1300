// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 4
#include <iostream>
#include <cassert> 
#include <assert.h>

using namespace std;
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
//valid noe function
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
//numvalidnote function
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
//new function for question four 
double tuneSimilarity(string tune1, string tune2) 
{
   
//for similarity = (number of matching notes / total number of notes) 
            //+ number of matching notes with matching pitches 
            //- number of different notes with different pitches
double match_note=0;
double similarity=0;
//total amount of notes using numValNotes function 
int total_note = numValidNotes(tune1);  
int match_match=0;  
int different_different=0;

//if the two tune lengths don't equal eachother return 0
if(tune1.length()!=tune2.length())
{
    return 0;
}
// for loop that goes through the tune length by 2 so it checks pairs 
for(int j=0; j< tune1.length();j+=2)
{
  //if the tune note matches the tune note
    if (tune1[j]==tune2[j])
    {
        //match note goes up by 1
        match_note +=1; 
        //if tune1 pitch matches tune2 pitch
        if(tune1[j+1]==tune2[j+1])
        {
            //number of matching notes with matching pitches (match_match) goes up by 1
            match_match++; 
        }
    }
    //otherwise if the tune pitches don't match and the tune notes also dont match
    else if (tune1[j+1]!=tune2[j+1])
    {
    //number of different notes with different pitches add up by 1 each time
    different_different ++; 
    }

}
//caulculate similarity with equation from github
similarity= match_note/total_note+match_match-different_different;
//return similarity results 
return similarity; 

}
int main ()
{

assert(doublesEqual(tuneSimilarity("D5G2", "F7D1E4G4"), 0));
assert(doublesEqual(tuneSimilarity("A0B0C0D0", "D1C1B1A1"), -4));
assert(doublesEqual(tuneSimilarity("G4E5D4", "G4F4D5"), 0.666667));
assert(doublesEqual(tuneSimilarity("E5E5G5A6G5D5", "E5G5A6G5D5D5"), 0.333333));

}