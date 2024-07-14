#ifndef GAME_H
#define GAME_H
#include <fstream>
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "Item.h"
#include "Freddy.h"
#include "Player.h"
using namespace std;
//****************** what is in the post.cpp

//GAME STATE IDENTIFIERS 
#define GAME_STATE_PLAYING 1
#define GAME_STATE_ROOM_INTERACTION 2
#define GAME_STATE_NPC_INTERACTION 3
#define GAME_STATE_EXIT 4
#define GAME_STATE_DEAD 5
#define GAME_STATE_MENU 6
#define GAME_STATE_CLOCK 7
#define GAME_STATE_MESSAGE 8
#define GAME_STATE_HELP_MENU 9
#define GAME_STATE_SHOP 10
#define GAME_STATE_BAG 11
#define GAME_STATE_GAME_END 12


class Game
{
        private:
            // static const int posts_size_= 50;
            // static const int users_size_= 50;
            vector<Enemy> v;
            vector<Item> item;
            //User users_[50];
            int user_health = 0;
            int Freddy_health = 0;

            int gameState;
            int lastNPCInteraction;
            int lastRoomInteraction;
            int lastExitInteraction;
            Player player;
            
        public: 
        //Default: constructor
            Game();

            //Parameterized: constructor 
            Game(int, int);

            int split(string input_string, char separator, string arr[], int arr_size);

            int getFreddyHealth();

            int getPlayerHealth();
            // int Item();
            //int Cost();

            int fightEnemy(string fight);
            void showInvetory(string bag);
            void getTime(string time);
            int solveRiddle(int answer);
            int playGame(int product);
            void setGameState(int status);
            int getGameState();
            int getLastNPCInteraction();
            void setLastNPCInteraction(int id);
            int getLastExitInteraction();
            void setLastExitInteraction(int id);
            int getLastRoomInteraction();
            void setLastRoomInteraction(int id);
            Player getPlayer();
            void setPlayer(Player p);
            // int getLikes(string post_author, string username);
            // void getTime(string username_tag);
            // bool addPost(string post_body, string post_author, string date);
            // void printPopularPosts(int count, string year);
            // //User findLeastActiveUser();
            // int countUniqueLikes(string post_author);

            

};
//tell compiler to read it 
#endif