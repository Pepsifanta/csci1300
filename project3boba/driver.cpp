#include "Challenge.h"
#include "Drink.h"
#include "Player.h"
#include "Shop.h"
#include "Map.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
using namespace std;

Map setupMap() {

    // Construct a default map
    Map map;
   // cout << "Room #: " << map.getRoomCount() << endl;
   // cout << "Let's add some rooms: " << endl;

//adding random rooms 
    for(int i = 0; i<6; i++)
    {
        //rows/up and down
        //using rand function to make it random 
        int r = rand()%12;
        //colums/ side 
        int n = rand()%12;

        map.addRoom(r, n);
    }
    //adding random npc 
    for(int i =0; i<28; i++)
    {
        int s = rand()%12;
        int t = rand()%12;
        map.addNPC(s, t);
    }


//this shows how many rows and coloms of map there is 
    // cout<<map.getNumRows()<<endl;
    // cout<<map.getNumCols()<<endl;

    return map;
}

int getUserInput(int in1, int in2) 
{
    int user_input;
    cin >> user_input;
    return user_input;
}

// void saveGame(Player player, Map map, vector<tm> inventory) 
// {
//     ofstream outFile("save.txt");
//     if (!outFile.is_open()) 
//     {
//         cout << "Failed to save game." << endl;
//         return;
//     }
//     outFile << player.getPlayerRow() << endl;
//     outFile << player.getPlayerCol() << endl;
//     outFile << player.getGold() << endl;

//     // Save inventory
//     vector<Item> playerInventory = player.getInventory();
//     for (int i = 0; i < playerInventory.size(); i++) 
//     {
//         outFile << playerInventory[i].getName() << " " << playerInventory[i].getQuantity() << endl;
//     }

//     outFile.close();
//     cout << "Game saved successfully." << endl;
// }
void gameOver() 
{
    cout << "Game over!" << endl;
    exit(0); // Exit the program
}


void runGame() 
{
    // Initialize game objects
    Map gameMap;
    Player player("Player1");
    vector<string> menu = {"Milk Tea","Thai Tea", "Matcha Tea"};
    vector<int> prices = {3, 4, 4};
    Shop shop("Tea House", menu, prices);
    vector<Challenge> challenges;
    challenges.push_back(Challenge("Trivia", "Where did boba originate?", {"a) Taiwan", "b) China", "c) Japan"}, 1));
    challenges.push_back(Challenge("Math", "I have 5 boba drinks and drink 3. How many are left?", {"a) 4", "b) 3", "c) 2"}, 3));
    challenges.push_back(Challenge("Trivia", "What are boba pearls called?", {"a) Tolloca", "b) Pudding", "c) Tapioca"}, 3));
    


    // Set up game
    gameMap.resetMap();
    player.setPosition(5, 5);
    player.setGold(100);

    // Game loop
    while (true) 
    {
        // Display game stats
        cout << "------------------------";
        cout << "Money: $" << player.getGold() << endl;
        cout << "Inventory: ";
        if (player.getInventory().empty()) 
        {
            cout << "Empty";
        } 
        else 
        {
            vector<string> inventory = player.getInventory();
            for (int i = 0; i < inventory.size(); i++) 
            {
                cout << inventory[i] << " (1) ";
            }
            cout << endl;
        }

        // Display game menu
        cout << "What would you like to do?";
        cout << "1. Play";
        cout << "2. Controls";
        cout << "3. Inventory";
        cout << "4. Stats";
        cout << "5. Recipes";
        cout << "6. Exit";
        int choice = getUserInput(1, 6);

        // Process user choice
        switch (choice) 
        {
            case 1: {
                // Move player on map
                gameMap.displayMap();
                // int direction = getUserInput(1, 4);
                if (gameMap.movePlayer(direction, player)) 
                {
                    gameMap.exploreSpace(player.getPlayerRow(), player.getPlayerCol());

                    if (gameMap.isChallengeLocation(player.getPlayerRow(), player.getPlayerCol())) 
                    {
                        int challengeIndex = gameMap.getChallengeIndex(player.getPlayerRow(), player.getPlayerCol());
                        Challenge currentChallenge = challenges[challengeIndex];
                        cout << "You found a challenge! " << currentChallenge.getName() << endl;
                        if (player.getInventory().size() < currentChallenge.getRequiredIngredients()) 
                        {
                            cout << "You do not have enough ingredients to complete this challenge.";
                        } 
                        else 
                        {
                            int randomValue = rand() % 10 + 1; // generate a random number between 1 and 10 (inclusive)
                            if (randomValue > 7) 
                            {
                                cout << "Uh oh! Your drink didn't turn out as expected.";
                                player.removeInventory(currentChallenge.getIngredients());
                            }
                            else 
                            {
                                cout << "Congratulations! You completed the challenge and earned $" << currentChallenge.getReward() << ".";
                                player.addMoney(currentChallenge.getReward());
                                recipeBook.unlockRecipe(currentChallenge.getReward());
                                player.removeInventory(currentChallenge.getIngredients());
                            }
                        }
                       
                        // Check if player has completed a challenge
                        if (gameMap.isChallengeCompleted(player.getPlayerRow(), player.getPlayerCol())) 
                        {
                            Challenge completedChallenge = gameMap.getChallenge(player.getPlayerRow(), player.getPlayerCol());
                            player.completeChallenge(completedChallenge);
                            gameMap.removeChallenge(player.getPlayerRow(), player.getPlayerCol());
                            cout << "Congratulations! You completed the challenge: " << completedChallenge.getName() << endl;
                            cout << "You earned " << completedChallenge.getReward() << " coins!" << endl;
                        }
                    }
                }
                    // Game over
                    cout << "Game over. You earned a total of " << player.getGold() << " coins." << endl;
                    saveGame(player, inventory);
                    cout << "Game saved successfully!" << endl;
                    return 0;
            }
            
            case 2: // Controls
            {
                cout << "---- CONTROLS ----" << endl;
                cout << "W - Move Up" << endl;
                cout << "S - Move Down" << endl;
                cout << "A - Move Left" << endl;
                cout << "D - Move Right" << endl;
                break;
            }
            
            case 3:
            {
                // display inventory
                cout << "Inventory: " << endl;
                if (player.getInventory().empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    vector<string> inventory = player.getInventory();
                    for (int i = 0; i < inventory.size(); i++)
                    {
                        cout << inventory[i] << endl;
                    }
                }
                break;
            }

            case 4:
            {
                cout << "PLAYER STATS:" << endl;
                cout << "Health: " << player.getHealth() << endl;
                cout << "Money: " << player.getGold() << endl;
                cout << "Inventory: " << endl;
                player.displayInventory();
                break;
            }

            case 5:
            {
                int recipeInput = 0;
                cout << "=== Recipes ===" << endl;
                cout << "1. Classic Milk Tea" << endl;
                cout << "2. Taro Milk Tea" << endl;
                cout << "3. Strawberry Green Tea" << endl;
                cout << "4. Back to Main Menu" << endl;
                cout << "Enter recipe number: ";
                cin >> recipeInput;

                switch (recipeInput) 
                {
                    case 1: 
                    {
                        cout << "=== Classic Milk Tea Recipe ===" << endl;
                        cout << "1. Black Tea" << endl;
                        cout << "2. Milk" << endl;
                        cout << "3. Tapioca Pearls" << endl;
                        cout << "4. Ice" << endl;
                        break;
                    }
                    case 2: 
                    {
                        cout << "=== Taro Milk Tea Recipe ===" << endl;
                        cout << "1. Taro Syrup" << endl;
                        cout << "2. Milk" << endl;
                        cout << "3. Brown Sugar" << endl;
                        cout << "4. Tapioca Pearls" << endl;
                        cout << "5. Ice" << endl;
                        break;
                    }
                    case 3: 
                    {
                        cout << "=== Strawberry Green Tea Recipe ===" << endl;
                        cout << "1. Green Tea" << endl;
                        cout << "2. Strawberry Syrup" << endl;
                        cout << "3. Milk" << endl;
                        cout << "4. Tapioca Pearls" << endl;
                        cout << "5. Ice" << endl;
                        break;
                    }
                    case 4: 
                    {
                        break;
                    }
                    default: 
                    {
                        cout << "Invalid input. Please enter a number from 1-4." << endl;
                        break;
                    }
                }
                break;
            }

            case 6:
            {
            gameOver();
            break;
            }
        }
    }
}

int main()
{
    Map myMap;
    myMap.resetMap();

    // Set player position
    myMap.setPlayerPosition(0, 0);

    char moveDirection;
    bool isMoveSuccessful = false;

    while (true)
    {
        myMap.displayMap();

        cout << "Enter move direction (WASD): ";
        cin >> moveDirection;

        isMoveSuccessful = myMap.move(moveDirection);

        if (!isMoveSuccessful)
        {
            cout << "Invalid move. Please try again." << endl;
        }

        // Check if player has reached the exit
        if (myMap.isDungeonExit(myMap.getPlayerRow(), myMap.getPlayerCol()))
        {
            cout << "You have reached the dungeon exit!" << endl;
            break;
        }
    }
    return 0;
}