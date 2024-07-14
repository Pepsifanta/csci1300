// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 7- Problem 2: Read a DNA Sequence until STOP codon
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * Algorithm: read DNA 
 * 1. outputs the vector based on end and start points 
 * 2. first check for if the vector input is valid 
 * 3. then checks for the specific start and end strings to output everything inbetween  
 * Parameters: one string vector  
 * Returns/ outputs: the strings and letters inbetween the start and end 
 */

 //name function and make string vector    
string dnaRead(vector<string> v)
{
    //have variables 
    int start= -1;
    int end= v.size();
    string return_v= "";

// if(v.empty)
// {
    
// }
//for loop to check 
    for(int i = 0; i < v.size(); i ++)                
    {          
        //if not every sting is three characters long it is invalid                                
        if(v.at(i).length() != 3 )   

        {
            cout<< "Invalid sequence."<< endl; 
        }
        //if the first string letters dont equal the following 
         else if ((v.at(i)[0]!='A') && (v.at(i)[0]!='C') && (v.at(i)[0]!='G') && (v.at(i)[0]!='T') )  
        { 
        cout << "Invalid sequence." << endl;
    
        return "";
        } 
        //if the second string letters don't equal the following letters 
         else if ((v.at(i)[1]!='A') && (v.at(i)[1]!='C') && (v.at(i)[1]!='G') && (v.at(i)[1]!='T') )  
        { 
        cout << "Invalid sequence." << endl;
    
        return "";
        }   
        //if the third string letter doesn't equal the following letters 
         else if ((v.at(i)[2]!='A') && (v.at(i)[2]!='C') && (v.at(i)[2]!='G') && (v.at(i)[2]!='T') )  
        { 
        cout << "Invalid sequence." << endl;
    
        return "";
        }  
        //if it is specifically "ATG" that is the start index         
        else if(v[i]== "ATG")  
        {
         
           start= i;
            
        }  
        //if it is speciffically "TAA" "TAG" or "TGA"  those are end indexes 
        else if((v[i]== "TAA") || (v[i]== "TAG")|| (v[i]== "TGA") )  
        {

            end = i; 
            //break out of loop 
            break; 
        } 

           
    }  
    //if the start value changes then cout the vector 
    if(start!=-1)
    {
    for (int i = start+ 1; i < end; i ++)   
    {
       return_v= return_v + v.at(i);
    }
    }
//return the vector of the stuff between the start and the end
return return_v;

}

int main ()
{

vector<string> dna{ "ATG", "TAC", "TGA", "TAA"};
assert(doublesEqual(min(arr, arr_size), 1.240));
assert(doublesEqual(sum(arr, arr_size), 10.376));
assert(doublesEqual(average(arr, arr_size), 3.459));

// //test 1
// vector<string> dna{ "ATG", "TAC", "TGA", "TAA"};

// cout<<dnaRead(dna);
// //expected output TAC

// //test 2
// vector<string> dna2{"CAT", "AT", "GAC", "TAA", "ACT", "TAC"};
// cout << dnaRead(dna2) << endl;
// //expected output invalid sequence 

// //test 3
// vector<string> dna3{"ATG", "CAT", "ACT", "GAC", "TAA", "ACT", "TAC"};
// cout << dnaRead(dna3) << endl;
//expected output CATACTGAC

}