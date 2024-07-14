// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 6
#include <iostream>
#include <cmath>
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

double bestSimilarity(string inputTune, string targetTune) 
{
int length_tune= targetTune.length();

if(inputTune.length()<targetTune.length())
{
    return 0;
}
double best_sim = tuneSimilarity(targetTune, inputTune.substr(0,length_tune));

for (int j=0; j< inputTune.length()-targetTune.length()+1;j+=2)
{
 
  string input_sub = inputTune.substr(j,length_tune);
  double similarity= tuneSimilarity(targetTune, input_sub);
//each time the similarity is the greatest it replaces variable best_sim
  if(similarity>best_sim)
  {
    //sim replaces best_sim with the highest sim
    best_sim=similarity;
  }
}
return best_sim;
}


void printTuneRankings(string tune1, string tune2, string tune3, string targetTune) 
{

//make doubles for all the tunes and their similarity results 
double match_1= bestSimilarity(tune1, targetTune); 
double match_2= bestSimilarity(tune2, targetTune);
double match_3= bestSimilarity(tune3, targetTune);


//order them from best to worst
if ((match_1 > match_2)&&(match_1>match_3))
{
    //starting with tune 1 being the best then check for last two
    if(match_3>match_2)
    {
        //what should be outputted to user if 1 is best, 3 is better then 2
        cout<<"1) Tune 1, 2) Tune 3, 3) Tune 2"<<endl;
    }
    else
    {
        //what should be outputted if 1 is best and 2 is better then 3
        cout<<"1) Tune 1, 2) Tune 2, 3) Tune 3"<<endl;
    }
}
//second else if if tune 2 is the best
else if ((match_2>match_1)&&(match_2>match_3))
{
//for is 3 is second best
   if(match_3>match_1)
    {
        cout<<"1) Tune 2, 2) Tune 3, 3) Tune 1"<<endl;
      
    }
    //for if 1 is second best
    else
    {
        cout<<"1) Tune 2, 2) Tune 1, 3) Tune 3"<<endl;
      
    }
}
//lastly for if 3 is the best similarity match
else if ((match_3>match_1)&&(match_3>match_2))
{
  
   if(match_2>match_1)
    {
        //if 2 is second best
        cout<<"1) Tune 3, 2) Tune 2, 3) Tune 1"<<endl;
      
    }
    else
    {
        //if 1 is second best
        cout<<"1) Tune 3, 2) Tune 1, 3) Tune 2"<<endl;
       
    }

}
//if tune1 and tune3 are equal but less then tune 2
else if((match_1==match_3)&&(match_1>match_2))
{
 cout<<"1) Tune 1, 2) Tune 3, 3) Tune 2"<<endl;
}
//everything else, it things are equal to eachother it should always be in order
else
{
    cout<<"1) Tune 1, 2) Tune 2, 3) Tune 3"<<endl;
}


}

int main ()
{
//assert(printTuneRankings("C2E7", "D4B3", "A4D1", "A4B7")=="1) Tune 2, 2) Tune 3, 3) Tune 1");
 printTuneRankings("D3D4", "E3D4", "D3F4", "A7");
 //should output "1) Tune 1, 2) Tune 2, 3) Tune 3"
 printTuneRankings("B8", "C8", "A7", "C8");
 //should print "1) Tune 2, 2) Tune 1, 3) Tune 3"
 printTuneRankings("F4B2E6", "A1", "B6G2E4", "B7G4");
 //should print "1) Tune 3, 2) Tune 2, 3) Tune 1"
}