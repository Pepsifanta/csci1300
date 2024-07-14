// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 3 - Problem 5
#include <iostream>

using namespace std;

int main ()
{
   //make variable for all the sections 
    int section;
    int classin;
    int department;
   
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> department;
    // use the input to declare first switch
    switch(department)
    {
        //department case
        case 1: 
        //first case is for compsci prompt user for what compsci class they want 
            cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl;
            cin >> classin;
    
            switch(classin)
            {
                // compsci case
                case 1:
                // compsci classes case
                //ask for input for section of class user inputs
                    cout << "Select a section: (1)Section 100 (2)Section 200" <<endl;
                    cin>> section;
                    switch (section)
                    {
                        //open new switch for what is outputted to the user
                    case 1:
                        cout <<"You've been enrolled in Section 100 of Starting Computing!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 200 of Starting Computing!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                    }
                    return 0;
                case 2:
                
                    //switch options for second class option
                cout << "Select a section: (1)Section 101 (2)Section 201" <<endl;
                cin>> section;
                   switch (section)
                   {
                    case 1:
                        cout <<"You've been enrolled in Section 101 of Data Structures!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 201 of Data Structures!"<< endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                   }
                   return 0;
                case 3:
                
                    //third section for Algorithms 
                    cout << "Select a section: (1)Section 102 (2)Section 202" <<endl;
                    cin>> section;
                   switch (section)
                   {
                    case 1:
                        cout <<"You've been enrolled in Section 102 of Algorithms!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 202 of Algorithms!" << endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                   }
                   return 0;
                default:
                //bad input for the second switch
                    cout << "Please enter a valid input." << endl;
                    break;
                
            }
            
            break;
        //department case
        case 2: 
            //read in from user
            cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl;
             cin >> classin;
            switch(classin)
            {
                //math case
                case 1:
                    //switch for Calc class
                    cout << "Select a section: (1)Section 400 (2)Section 500" <<endl;
                    cin >> section;
                   switch (section)
                    {
                        //output which section they choose
                    case 1:
                        cout <<"You've been enrolled in Section 400 of Calculus 1!" <<endl;
                    break;
                    case 2:
                        cout <<"You've been enrolled in Section 500 of Calculus 1!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                        }
                        return 0;
                break;
                return 0;
                case 2:
                    //new switch for second math class calc 2
                    cout << "Select a section: (1)Section 401 (2)Section 501" <<endl;
                    cin >> section;
                    switch (section)
                    {
                        //outputs the section user selects
                    case 1:
                        cout <<"You've been enrolled in Section 401 of Calculus 2!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 501 of Calculus 2!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                    }
                    return 0;
                case 3:
                // last case switch for class linear algebra
                    cout << "Select a section: (1)Section 402 (2)Section 502" <<endl;
                    cin >> section;
                   switch (section)
                    {
                        //outputs to user what section they select
                    case 1:
                        cout <<"You've been enrolled in Section 402 of Linear Algebra!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 502 of Linear Algebra!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                    }
                    return 0;
                    //always have default after all switches
                default:
                    cout << "Please enter a valid input." << endl;
                break;
                
            }
            return 0;
        
            break;
            // Last big switch for science classes
            //prompt user for what class they want to join
        case 3: 
            cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl;
            cin >> classin;
            //apply it to the switch
             switch (classin)
            {
            //science case
            case 1:
                //prompt user for what section of gen chem they want
                cout << "Select a section: (1)Section 700 (2)Section 800" <<endl;
                cin >> section;
                   switch (section)
                    {
                        //output the section and class that user entered 
                    case 1:
                        cout <<"You've been enrolled in Section 700 of General Chemistry 1!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 800 of General Chemistry 1!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                    }
                    return 0;
            case 2:
                // if they chose physics prompt which section of physics class they want
                cout << "Select a section: (1)Section 701 (2)Section 801" <<endl;
                cin >> section;
                   switch (section)
                    {
                        //output to the user which class and section they enter to be enrolled in
                    case 1:
                        cout <<"You've been enrolled in Section 701 of Physics 1!" <<endl;
                        break;
                    case 2:
                        cout <<"You've been enrolled in Section 801 of Physics 1!" <<endl;
                        break;
                    default:
                        //bad input
                        cout << "Please enter a valid input." << endl;
                        break;
                    }
                    return 0;
                    //default for if they enter wrong
            default:
                cout << "Please enter a valid input." << endl;
                break;
            
            }
            break;
        //department case
        default:
            //print not valid input
                cout << "Please enter a valid input." << endl;
                break;
    }
    
    
    
}