// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 4 - Problem 4
#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() 
{
    // prompt user for their DNA code 
     string dna_s ;
    cout << "Enter the DNA Sequence:" << endl;
     cin >> dna_s;
     // find length of their input so we don't just check only the first letter 
     int s_length= dna_s.length();
  // for loop to check each letter 
     for (int i=0; i <s_length; i++)
     {
      // an if function to print invalid if the user input doesn't match
         if ((dna_s[i]!='A') && (dna_s[i]!='C') && (dna_s[i]!='G') && (dna_s[i]!='T') )  
      { 
        cout << "This is not a valid DNA sequence." << endl;
    
    return 0;
      }
     }
     // do the same thing for user input for the fragment 
    string dna_f ;
    cout << "Enter the DNA fragment to be searched:" << endl;
     cin >> dna_f;
     //find the whole length of the fragment so you can compare the whole thing
     int f_length= dna_f.length();

     for (int i=0; i <f_length; i++)
     {
      // if the fragment doesn't match the letters in the if statement then its invalid
         if ((dna_f[i]!='A') && (dna_f[i]!='C') && (dna_f[i]!='G') && (dna_f[i]!='T') )  
      { 
        // output to user that its invalid 
        cout << "This is not a valid DNA sequence" << endl;
      return 0;
      }
     }

// for main string 
int agree= 0;
// how to check how many times the fragment can match the sequence
//each time it matches if can skip it and go to the next one
for (int i=0; i<= dna_s.length()-dna_f.length();i++)
{
// keep checking until the first letter of the fragment equals the section
//then it moves into the second for loop to compare the second letter to the segment 
    bool is_match= true;
    for (int j=0; j<dna_f.length();j++)
    {
      // compare how many times both the fragment letters match the segment and that will make the bool how many times true
        if (dna_s [i+j]!=dna_f[j])
        {
        is_match=false;
        }
    }
    //count how many times the fragment matched
    if (is_match)
    {
      //agree is the amount the fragments are matched 
     agree ++;
    }

}
//output the count 
 cout << "Number of occurrences: " << agree << endl;
}