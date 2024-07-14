#include <iostream>
#include "Game.h"
#include <fstream>
#include "Enemy.h"
//#include "Freddy.h"
#include "Item.h"
#include "Player.h"


using namespace std;

/**
 * Algorithm: Split 
 * 1. stringf for inputline, a separater, and array to fill and an array size 
 * 2. loop to split and fill new array 
 * 3. splits string into diffrent components 
 * Parameters: split(string input_string, char separator, string arr[], int arr_size)
 * Returns: a int
 */

int Game::split(string input_string, char separator, string arr[], int arr_size)
{
  //counter that starts at 0
    int count =0;
    //new variable for input_string length
    int length= input_string.length();
// if the length is equal to zero it will return 0
    if (length==0)
    {
        return 0;
    }
    int num_sep=0;
for (int i = 0; i < input_string.length(); i++)
{
  if(input_string[i]==separator)
  {
  num_sep++;
  }
}
if (num_sep>=arr_size)
{
  return -1;
}
// for loop to go through the input_string
  for(int i=0; i < length; i++)
  {
    // if else statement that if part of the input string is not equal to the separator
    if (input_string[i] != separator )
    {
      //the part of the array becomes the array plus the inputstring that does not equal the separator
        arr[count] = arr[count]+ input_string [i];

    }
    //if the array is equal to the separator 
    if (input_string[i] == separator )
    {
      //count goes up
        count ++;
    }
  }
//if the amount of peices we split up is bigger and cant fit into the array retunr -1
  if (count>= arr_size)
  {
    
    return -1;
  }
  return count+1;


}
  
  Game::Game()
  {
    user_health = 0;
    Freddy_health = 0;
    gameState = GAME_STATE_MENU;
    lastNPCInteraction = -1;
    lastRoomInteraction = -1;
    lastExitInteraction = -1;
  }
            //Parameterized: constructor ARE THERE NONE????
    Game::Game(int uhealth, int fhealth)
            {
                user_health= uhealth;
                Freddy_health = fhealth;
                gameState = GAME_STATE_MENU;
                lastNPCInteraction = -1;
                lastRoomInteraction = -1;
            }

            int Game::getLastNPCInteraction() {
              return lastNPCInteraction;
            }

            void Game::setLastNPCInteraction(int id) {
              lastNPCInteraction = id;
            }

             int Game::getLastExitInteraction() {
              return lastExitInteraction;
            }

            void Game::setLastExitInteraction(int id) {
              lastExitInteraction = id;
            }

            int Game::getLastRoomInteraction() {
              return lastRoomInteraction;
            }

            void Game::setLastRoomInteraction(int id) {
              lastRoomInteraction = id;
            }
            
            int Game::getFreddyHealth()
            {
                return Freddy_health;
            }
            int Game::getPlayerHealth()
            {
                return user_health;
            }

    /**
 * Algorithm: fightEnemy 
 * 1. string to see if they want to fight or not 
 * 2. Will activate a game, or a riddle for the user to win
 * 3. f user wins, the user gains, if user loses Freddy's health decreases 
 * Parameters: fightEnemy(string fight)
 * Returns: an int in the health 
 */        
    int Game::fightEnemy(string fight)
         {
            return 2;
         }
    /**
 * Algorithm: showInvetory 
 * 1. an option on the menu to open their bag
 * 2. this will show a list of their invetory 
 * 3. this helps see if they need to earn more to get more charges for freddy 
 * Parameters: showInvetory(string bag)
 * Returns: nothing bc its a void so it outputs the invetory menu to the user 
 */ 
    void Game::showInvetory(string bag)
    {
      return;
    }
      /**
 * Algorithm: getTime 
 * 1. an option on the menu to open their fazzbear watch to see the time 
 * 2. this will show how far into the map they are to see what time it is (bc they have to make it to 6am to win the game)
 * 3. This will also show the user what level of monsters they are fighting 
 * Parameters: getTime(string time)
 * Returns: nothing bc its a void so it outputs the invetory menu to the user 
 */ 
    void Game::getTime(string time)
    {
      return;
    }
    
        /**
 * Algorithm: solveRiddle 
 * 1. When user encounters a lower level enemy they will have to solve a riddle 
 * 2. The riddle is just a simple math problem and they have to get the right answer
 * 3. If they get it right they can leave unharmed, if they get it wrong Fredy will get damaged 
 * Parameters: solveRiddle(int answer)
 * Returns: damages on Freddy
 */  
    int solveRiddle(int answer)
    {
        return -2;
    }

void Game::setGameState(int newState) {
  gameState = newState;
}

int Game::getGameState() {
  return gameState;
}

Player Game::getPlayer() {
  return player;
}

void Game::setPlayer(Player p) {
  player = p;
}