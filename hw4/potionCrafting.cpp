// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 4 - Problem 3
#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() 
{
    // prompt user for what potion they want to prioritize 
     int priority ;
    cout << "Select a potion crafting priority:" << endl;
    cout << "1. Minor Mana" << endl;
    cout << "2. Minor Healing" << endl;
     cin >> priority;
     // make a loop for inavlid inputs 
     while ((priority != 1)&&(priority != 2))
      { 
        cout << "Invalid input." << endl;
        cout << "Select a potion crafting priority:" << endl;
    cout << "1. Minor Mana" << endl;
    cout << "2. Minor Healing" << endl;
     cin >> priority;
      }
      //prompt user for how many honeycombs they have 
      int honey_comb;
      cout << "How many Honeycombs do you have?" << endl;
      cin >> honey_comb;
      // make while loop for the honeycomb prompt to print invalid 
      while (honey_comb <0) 
      { 
        cout << "Invalid input. How many Honeycombs do you have?" << endl;
    cin >> honey_comb;
      }
      //repeat for all the user's inputs 
        int dande;
      cout << "How many Dandelions do you have?" << endl;
      cin >> dande;
      
      while (dande <0) 
      { 
        cout << "Invalid input. How many Dandelions do you have?" << endl;
        
    cin >> dande;
      }
    
      
       int coal;
      cout << "How many Coal do you have?" << endl;
      cin >> coal;
      
      while (coal <0) 
      { 
        cout << "Invalid input. How many Coal do you have?" << endl;
        
    cin >> coal;
      }
     
      
       int toad;
      cout << "How many Toadstools do you have?" << endl;
      cin >> toad;
     
      while (toad <0) 
      { 
        cout << "Invalid input." << endl;
         cout << "How many Toadstools do you have?" << endl;
    cin >> toad;
      }
      //if statement for if the user prioritizes 2nd potion 
      if ( priority == 2 )
      {
        //math for how many materials are needed to make the potion 
          int honey_health=  honey_comb / 5; 
          int coal_health = coal / 2;
          int toad_health = toad / 3;
          //find the minimum of how many goes in and that equals how many total potion they can make
          int minor_potion= min({honey_health, coal_health, toad_health});
          // find the leftovers 
          honey_comb = honey_comb - minor_potion *5;
          coal = coal-minor_potion*2;
          toad = toad - minor_potion *3; 
          //make the not prioritized potion with the leftovers 
          int honey_mana=  honey_comb / 5 ;
          int coal_mana = coal / 1;
          int dande_mana = dande / 3;
          int mana_potion= min({honey_mana, coal_mana, dande_mana});
      //output to user 
      cout << "You can make "<<minor_potion<< " Healing potion(s) and "<< mana_potion << " Mana potion(s)."<<endl;
      
      }
      //repeat for if the user prioritizes the 1st potion 
      if ( priority == 1 )
      {
        //equation for how many materials are needed for the first potion 
          int honey_mana=  honey_comb / 5 ;
          int coal_mana = coal /1;
          int dande_mana = dande / 3;
          //the minimum of how many potions we can make 
          int mana_potion= min({honey_mana, coal_mana, dande_mana});
          
        //leftovers for the less prioritized potion
          honey_comb = honey_comb - mana_potion *5;
          coal = coal-mana_potion*1;
          dande = dande - mana_potion *3; 
          // how many minimum potions we can make with leftovers for second potion
          int honey_health=  honey_comb / 5; 
          int coal_health = coal / 2;
          int toad_health = toad / 3;
          int minor_potion= min({honey_health, coal_health, toad_health});
          
      //output to user 
      cout << "You can make "<<mana_potion<< " Mana potion(s) and "<< minor_potion << " Healing potion(s)."<<endl;
      
      }
      
      
      
    }
    
    


    
    

