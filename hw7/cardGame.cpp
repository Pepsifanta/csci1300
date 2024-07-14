// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 7- Problem 3: Card Game
#include <vector>
#include <iostream>

using namespace std;


int main() {

/**
 * Algorithm: War (card game) 
 * 1. fill up vector and remove things based on inputs 
 * 2. for loop to check inout conditions 
 * 3. ends loop when input is 14(joker) and couts results  
 * Parameters: integers 
 * Returns/ outputs: who is the winner and what is in the vector at the end 
 */
    
    // Implementation here
      vector<int> v;
    bool cards = true; 
    int counter=0; 
    int input_1;

//do while because I want it to run once first becuase I need a input_1 to start the while loop
 do 
 //((input_1 !=14) && (cards ==true) )
    {
    // vector<int> v;
    ///////////////////////////////////////
    // cout<<"size"<< v.size()<<endl;
    //   for(int i = 0; i < v.size(); i ++)                      
    //      {                                                               
    //          cout<< v.at(i)<< " ";                             
    //      } 
    //      cout<<endl;
    //int input_1;
    //prompt user for card number 
        cout << "Please enter a number: " << endl;
        cin >> input_1;
    
        //cout<<"size"<<v.size()<<endl;
//if the number(card) is out of bounds then output to user 
        if( (input_1 > 14) || (input_1 <=0))
        {
            cout<<"The number should be an integer between 1 and 14."<<endl;
        }
        //if the user input is correct add to vector 
        else if((input_1>0)&& (input_1<14))
        {
            v.push_back(input_1);
        // v.insert(v.end(), input_1);
        }
        // if the size of the vector is greater then 1 then it removes the first two cards 
        if((v.size()>1)&&(input_1 == 1))
        {
            
            // v.push_back(input_1);
            v.erase(v.begin()+1);
            v.erase(v.begin());
       
        //counter goes up 2 for the other players points 
            counter +=2; 
            
        }
    //if there is only one thing in the vector it removes only one card instead 
        else if((v.size()==1)&&(input_1 == 1))
        {
        //     cout<<"line 60"<<endl;
        //     v.push_back(input_1);
               v.erase(v.begin());
        //    cout<<"line 59"<<endl;
        //counter only goes up 1
            counter ++; 
        }

        //if there is more then one card or the vector size is greater then one and they pull a 11, 12, or 13 
        //the player gets two cards from the back of their vector removed 
        if ((v.size()>1) && ((input_1 == 11) ||(input_1 == 12)||(input_1 == 13)))
        {
        //    cout<<"line 66"<<endl;
        //     // v.insert(v.end(), input_1);
        //     v.push_back(input_1);
                    v.pop_back();
                    v.pop_back();
                //  cout<<"line 69"<<endl;
        //counter goes up by 2
                    counter +=2;
        }
    //same thing that pulling a 1 does 
    //if there is only one card then it just removes it 
        else if ((v.size()==1) && ((input_1 == 11) ||(input_1 == 12)||(input_1 == 13)))
        {   
            // cout<<"line 81"<<endl;
            // v.insert(v.end(), input_1);
            // v.push_back(input_1);
                    v.pop_back();
        //    cout<<"line 78"<<endl;
        //counter goes up by 1
                    counter ++;
        }
        //if the user input is 14 then the game ends because they pulled a joker 
        //ends the while loop 
        else if (input_1 == 14)
        {
            cards = false; 
        }

        // for(int i = 0; i < v.size(); i ++)                      
        //  {                                                               
        //      cout<< v.at(i)<< " ";                             
        //  }
        //  cout << endl;
        //  cout<< "input1: " << input_1<<endl;
        //while loop requirments, has to not be 14 and bool has to be true 
    }while((input_1 !=14) && (cards ==true) );

    // cout<< "final value: " << input_1<<endl;

    //once the game ends what the game couts based on counter and vector amounts 
    if (input_1==14)
    {
        //cout the cards (integers)
        cout<<"Your remaining cards are: ";
        for(int i = 0; i < v.size(); i ++)                      
         {                                                               
             cout<< v.at(i)<< " ";                             
         } 
         cout<<endl;
        //cout the counger cards 
        cout <<"I have "<<counter<<" card(s)."<<endl; 

        //if else statements to see who has the most so who wins the game 
        if(counter > v.size())
        {
            cout<< "I win!"<<endl;
        }
        if(counter < v.size())
        {
            cout<<"You win!"<<endl;
        }
        if(counter == v.size())
        {
            cout<<"Tie!"<<endl;
        }
    }
    
    return 0;
}