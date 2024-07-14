------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 Enemy.cpp Freddy.cpp Map.cpp Item.cpp Player.cpp Game.cpp GameDriver.cpp
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Enemy.h, Freddy.h, Item.h, Map.h, Player.h and Game.h must be in the same directory as the cpp 
files in order to compile.
- all .txt, .h and .cpp files need to be in the same folder as GameDriver.cpp
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Nicole Ren
Recitation: 1300-304 – Nikhith Sannidhi
Date: Dec 1, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This project is based of a game called FNAF Security breach. 
In the game the user is trapped in a building filled with enemy animatronics
The user needs to escape the building at 6AM, when the front doors of the building open again
The user will face enemies and have to enter rooms 
Every enemy will have a riddle for the user to solve
To break out they not only have to survive til the end of the game but the user will also have to get their teammate Freddy's health up
Even if they get to the door they won't be able to leave until Freddy is strong enough to break the player out
To Access enough health while also move as little as possible so Vanny's (Main enemy) anger level doesn't go all the way up is to enter rooms 
Entering rooms will grant the player access to Freddy upgrades which is the same price as a regular health recharge but also adds double the health.
Beware not to lose all your health becuase player health is not rechargable, so when player's health is all the way down- game ends 
Try and escape! 