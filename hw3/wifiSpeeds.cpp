// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 3 - Problem 4
#include <iostream>

using namespace std;

int main() 
{
    //make variables for all days of wifi user inputs 
    double wifi1;
    double wifi2;
    double wifi3;
    
    int wifi;
//user input will go correctly into all the three diffrent days of wifi varaibles
    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> wifi1>>wifi2>>wifi3;
    //if user inputs less then 0 or neg number it will be invaild
     if ( wifi1 <= 0 ) 
    {
        cout << "Please enter a valid input." << endl;
        return 0;
        }
      if ( wifi2 <= 0 ) 
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
      if ( wifi3 <= 0 ) 
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    //if day 1 is less then 2 and 2 is less then 3 the users wifi is getting faster
    if ( wifi1<wifi2  && wifi2<wifi3)
    {
        cout << "The wifi is getting faster!" << endl;
    }
    //if wifi1 is more then 2 and 2 is more then 3 then wifi is getting slower
     else if ( wifi1>wifi2 && wifi2>wifi3 )   
    {
        cout << "The wifi is getting slower!" << endl;
    }
    else
    //if user wifi is not consistant it will be unpredictable
    {
        cout << "The wifi speed is changing unpredictably." << endl;
    }

    return 0;
}