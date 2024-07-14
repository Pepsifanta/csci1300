// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 3 - Problem 6
#include <iostream>

using namespace std;

int main ()
{
    
    //declare var category and instrument
    int category;
   
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> category;

    //prompt user to enter and read in category
    
    //switch 
    switch(category)
    {
        case 1: 
         int instrument;
   //prompt user for what instrument they would want in first section/case
    cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
    cin >> instrument;
    
            switch(instrument)
            {
                //based on user input of what instrument output the price of that 
                case 1:
                cout << "Your instrument will be $350." <<endl;
                break;
                case 2:
                 cout << "Your instrument will be $400." <<endl;
                break;
                default:
                //bad input that doesn't make sense 
                cout << "Please enter a valid input." << endl;
                break;
                
            }
            
            break;
        case 2: //woodwind
            //read in instrument from user
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
    cin >> instrument;
            switch(instrument)
            {
                case 1:
                cout << "Your instrument will be $325." <<endl;
                break;
                case 2:
                cout << "Your instrument will be $425." <<endl;
                break;
                
                default:
                cout << "Please enter a valid input." << endl;
                break;
                
            }
        
            break;
        case 3: // percussion
          cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
    cin >> instrument;
             switch (instrument)
            {
                //output what the user picks, the price of that choice
            case 1:
             cout << "Your instrument will be $275." <<endl;
                break;
            case 2:
            cout << "Your instrument will be $200." <<endl;
                break;
            default:
            cout << "Please enter a valid input." << endl;
                break;
            
            }
            break;
        default:
            //print not valid input
            cout << "Please enter a valid input." << endl;
                break;
            break;
        
    }
    
    
    
}