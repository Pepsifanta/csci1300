// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 4 - Extra Credit 
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    //prompt user for input 
    double freq;
    cout << "What is your frequency?:" << endl;
    cin >> freq;

     if ((freq < 32.7) && (freq > 4186 ))  
      { 
        cout << "Your note is not on a piano." << endl;
    
    return 0;
      }

    
      int character =  12*log2(freq/32.7)
    

}