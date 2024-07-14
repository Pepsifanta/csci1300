#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>
#include <stdio.h>
#include <string>
#include <vector>

#include "Enemy.h"
#include "Item.h"
#include "Player.h"
//#include "Freddy.h"
#include "Map.h"
#include "Game.h"


using namespace std; 

//reads enemy.txt 
//void readEnemies(string filename)

    // Enemy 
    // vector<string>enemies;
    // ifstream myFile(filename);
    //     string line;
    //     while(getline(myFile, line))
    //     {
    //         enemies.push_back(line), 
    //     }
    //     myFile.close();
    // return enemies;
    // //return vector of enemies 
int split(string input_string, char separator, string arr[], int arr_size)
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

vector<Enemy> readEnemies(string file_name)

{
    vector<Enemy>enemies;
        ifstream fin;

        fin.open(file_name);
        // if (num_posts_ == posts_size_)
        // {
        //     return -2;
        // }
        // if (!fin.is_open())
        // {

        //     return -1;
        // }

        string line = "";

        while (getline(fin, line))
        {

            string arr[2];
            //vector<string>enemies;
            int n = split(line, ',', arr, 2);
            if (line.empty())
            {
                continue;
            }

            if ((n > 2) || (n < 2))
            {
                continue;
            }

            Enemy p;
            p.setEnemyBody(arr[0]);
            p.setEnemyLevel(stoi(arr[1]));
            // p.setPostLikes(stoi(arr[2]));
            // p.setPostDate(arr[3]);

            enemies.push_back(p);
            //posts_[num_posts_] = p;

            // num_posts_ += 1;
            // if (num_posts_ == posts_size_)
            // {
            //     return num_posts_;
            // }
        }
        return enemies;
}



Map setupMap() {

    // Construct a default map
    Map map;
   // cout << "Room #: " << map.getRoomCount() << endl;
   // cout << "Let's add some rooms: " << endl;

//adding random rooms 
    for(int i = 0; i<6; i++)
    {
        //rows/up and down
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

//function for menu 
int mainMenu() {


    cout << "-- PIZZA PLEX --" << endl;
    cout << "Choose an option:" << endl << "1: Play" << endl << "2: Help" << endl << "3: Clock ⏰" << endl << "4: Open Bag"<<endl;
    cout << "5: Print Special Message" << endl << "6: Exit" <<endl;
    //BAG player.getitems 
    char inp;
    cin >> inp;
    switch (inp) {
        case '1':
        //starts map 
            return GAME_STATE_PLAYING;
        break;
        case '2':
        //How to work the map 
            return GAME_STATE_HELP_MENU;
        break;
        case '3':
        //exits code 
            return GAME_STATE_CLOCK;
        break;
        case '4':
        //exits code 
            return GAME_STATE_BAG;
        break;
        case '5':
        //exits code 
            return GAME_STATE_MESSAGE;
        break;
        case '6':
        //exits code 
            return GAME_STATE_EXIT;
        break;
        // case '4':
        // //exits code 
        //     cout<< game.showInvetory <<endl; 
        // break;
        default:
        //if user input invalid 
            cout << "Please enter a valid option!!" << endl;
            return mainMenu();
        break;
    }
}


//function for the game loop (looping through map etc)
void gameLoop(Game game, Map map) 
{
    char input;
    Freddy freddy=Freddy();
    srand(time(0));
    int vannyAnger = 0;
    Character player = game.getPlayer();
    vector<Enemy>enemies= readEnemies("enemy.txt");
    // cout << "game loop" << endl;
    vector<Enemy>enemiesViewed; 
    int coinsPlayerHas = player.getCoins();

    //while loop to run the game 
    while (true)
    {
        //sets the player object to the game 
        // Player player = game.getPlayer();
    //
        switch (game.getGameState()) 
        {
            case GAME_STATE_PLAYING: //game state 1
            {
                //what to outpu when game starts 
                cout << "Health: " << player.getPlayerHealth() << " || Freddy: " << freddy.getFreddyHealth() << " || Coins: " << player.getCoins() << " || Room #: " << map.getRoomNumber() << "|| Vanny Anger: "<<vannyAnger<<endl;
                map.displayMap();                                                                                           //player.getCoins()//coinsPlayerHas
                cout<<"Enter your input:" << endl;
                cin >> input; 

                // Make the input all lowercase so the game will read "A" and "a" as the same thing
                input = tolower(input);

                if (input == 'q')
                {
                    cout << "Bye bye!!!" << endl;
                    // Set the game state to exit so next time through the loop it calls return
                    game.setGameState(GAME_STATE_EXIT);
                } 
                else 
                {
                    map.move(input); 

                    int row_p= map.getPlayerRow();
                    int col_p= map.getPlayerCol();

                    if(map.isExplored(row_p, col_p)== 0 )
                    {
                            //player.setCoins(player.getCoins() + 2);
                        int randCoin= rand()%4;
                        if((randCoin==0) || (randCoin==1)||(randCoin==2)||(randCoin==3))
                        {
                            player.setCoins(player.getCoins() + 1);
                        }
                            if(randCoin==4)
                        {
                            player.setCoins(player.getCoins() -1 );
                        }
                    }

                    if(map.isExplored(row_p, col_p)== 0 )
                    {
                        vannyAnger= vannyAnger+4;

                    }
                
                    if (vannyAnger== 500)
                    {
                        cout<<"Vanny is at her limit of anger and decided to handle this on her own"<<endl;
                        game.setGameState(GAME_STATE_DEAD);
                    }
                    if (player.getPlayerHealth()== 0)
                    {
                        cout<<"You lost all your health."<<endl;
                        game.setGameState(GAME_STATE_DEAD);
                    }
            //This gets location of the player 
                    int row = map.getPlayerRow();
                    int col = map.getPlayerCol();
            //check loop if you ran into npc
                    bool ranIntoNPC = false;
                    bool ranIntoRoom = false;

                    if (game.getLastExitInteraction() == -1 && map.isDungeonExit(row, col)&& freddy.getFreddyHealth()==40) 
                    {
                        //&& game.getFreddyHealth()==40
                            //to get index of the npc your talking to (in the array)
                        game.setGameState(GAME_STATE_GAME_END);
                        ranIntoRoom = true ;
                    }

                    if (game.getLastExitInteraction() == -1 && map.isDungeonExit(row, col) && freddy.getFreddyHealth()<40)
                    {
                        //to get index of the npc your talking to (in the array)
                        cout<<"You made it to 6AM and you found the exit door!"<<endl;
                        cout<<"╔═.✵.══════════╗" <<endl;
                        cout<<"      EXIT      "<<endl;
                        cout<<"╚══════════.✵.═╝"<<endl;

                        cout<<"Oh no! but it seems like you can't leave yet!"<<endl; 
                        cout<<"^---^"<<endl;
                        cout<<"(҂`_´)"<<endl;
                        cout<<"<,︻╦╤─ ҉ - -"<<endl;
                        cout<<"/﹋/"<<endl;
                        cout<<"To Exit you need to get Freddy's health to 40 so he can break you out!"<<endl;
                        cout<<"Find more enemies beat them and get into their shops"<<endl;
                        cout<<"Buy more recharges for Freddy, then come back so you can exit!"<<endl;
                        cout<<"Once Freddy's health is at 40 and you come back to the exit door you will automatically be able to leave"<<endl;
                        char ans;
                        cout<<"Would you like to continue? (y/n)"<<endl; 
                        cin>>ans;
                        ranIntoRoom = true ;

                        if(ans == 'y')
                        {
                            game.setGameState(GAME_STATE_PLAYING);
                        }
                        else if(ans == 'n')
                        {
                            game.setGameState(GAME_STATE_EXIT);
                        }
                        else 
                        {
                            cout<<"Invalid input"<<endl; 
                            game.setGameState(GAME_STATE_PLAYING);
                        }
                    }

                //-1 means no npc run into 
                    if (game.getLastNPCInteraction() == -1 && map.isNPCLocation(row, col)) 
                    {
                        //to get index of the npc your talking to (in the array)
                        game.setGameState(GAME_STATE_NPC_INTERACTION);
                        int NPCId = map.getNPCId(row, col);
                        game.setLastNPCInteraction(NPCId);
                        ranIntoNPC = true;
                    }
                    // cout <<  map.isRoomLocation(row, col);
                    // If we didn't run into an NPC this game loop
                    if (!ranIntoNPC) 
                    {
                        // Set the last interaction to no NPC (-1) so that we can interact with one if we run into one
                        game.setLastNPCInteraction(-1);
                    }
                
                    if (game.getLastRoomInteraction() == -1 && map.isRoomLocation(row, col)) 
                    {
                        // Enter room
                        game.setGameState(GAME_STATE_ROOM_INTERACTION);
                        ranIntoRoom = true ;
                        //cout << "Entering room...";
                    }

                    //map.displayMap();
                    if (!ranIntoRoom) 
                    {
                        // Set the last interaction to no NPC (-1) so that we can interact with one if we run into one
                        game.setLastNPCInteraction(-1);
                    }
                }
                
                break;
            }
            //switch for if player runs into room
        
            case GAME_STATE_ROOM_INTERACTION: //game state 2
            {
                char action;
                cout << "You found a Room! What will you do?" << endl;
                cout << "1: Interact" << endl;
                cout << "2: Ignore and go around" << endl; 
                cin >> action;
                //*****************HOW TO DO KEY *******
                // for loop through vector to find 
                if (action == '1')
                {
                    bool security_b = false ;
                    // cout<<"HI1"<<endl;
                    cout<<player.getItemsOwned().size()<<endl;
                    // vector<Item> final_op = player.getItemsOwned();
                    // for (int i=0; i<final_op.size(); i++)
                    // {
                    //     cout << final_op.at(i) << endl;
                    // }
                    // cout << "check 2" << player.getItemsOwned() >> endl;
                    if(player.getItemsOwned().size()==0)
                        {
                            cout<<"You don't have a security badge to unlock the room!"<<endl<<"Please find an NPC beat their game and buy a Security badge in their shop!"<<endl;
                            game.setGameState(GAME_STATE_PLAYING);
                        }
                    else if(player.getItemsOwned().size()>0)
                    {
                        for(int i = 0; i < player.getItemsOwned().size(); i ++)                      
                        {  
                            //cout<<"key 1"<<player.getItemsOwned().at(i).getItem()<<endl;
                            // cout<<"hi2"<<endl;
                            // cout<<"Hi2 item"<<player.getItemsOwned().at(i).getItem()<<endl;
                            //checks if player has a key   
                            if (player.getItemsOwned().at(i).getItem() == "Security Badge")
                            {
                                security_b= true ;
                            } 
                            else if ((action == '1') && (player.getItemsOwned().at(i).getItem() != "Security Badge")) 
                            {
                                security_b= false; 
                            }

                         } 
                         if (security_b == true )
                         {
                              char ans;
                                cout<<"You have a security badge would you like to use it to go into this room? (y/n)"<<endl; 
                                cin>>ans;

                                if (ans== 'y')
                                {
                                    for(int i = 0; i < player.getItemsOwned().size(); i ++)   
                                    {
                                    //removes security badge from their 
                                    if (player.getItemsOwned().at(i).getItem() == "Security Badge")
                                    {
                                    player.removeItem(i);
                                    }
                                    }
                                    cout<<"You've entered the room..."<<endl;
                                    Item secretItem("secretItem", 0);
                                    //cout<<"You found a secretItem!"<<endl;
                                    player.addItem(secretItem);
                                    cout<<"BOO You've encountered an enemy"<<endl;
                                    cout<<"You have to play my game and if you win you can enter my shop"<<endl;
                                    game.setGameState(GAME_STATE_NPC_INTERACTION);

                                }
                                else if (ans== 'n')
                                {
                                    cout<<"Oh no! Hope to see you back at the room later!"<<endl;
                                    game.setGameState(GAME_STATE_PLAYING);
                                }
                                else
                                {
                                    cout<<"Invalid input"<<endl; 
                                    game.setGameState(GAME_STATE_PLAYING);
                                }
                                break;
                         }
                         else if ( security_b == false )
                         {
                             cout<<"You don't have a security badge to unlock the room!"<<endl<<"Please find an NPC beat their game and buy a Security badge in their shop!"<<endl;
                                game.setGameState(GAME_STATE_PLAYING);
                         }
                    }
                }

                else if(action == '2')
                {
                    cout << "Goodbye!";
             //gamestate playing will resume the game 
                    game.setGameState(GAME_STATE_PLAYING);

                }

                else 
                {
                cout<<"invalid"<<endl;
                game.setGameState(GAME_STATE_ROOM_INTERACTION);
                }


                break;
            }
            //switch case for if you run into npc 
            case GAME_STATE_NPC_INTERACTION: //GAME STATE 3
            {
            //    vector<string>enemiesViewed; //readEnemies
                int enemyIndex= rand()%enemies.size();
                cout << "You encountered the "<< enemies.at(enemyIndex).getEnemyBody()<< " enemy! What will you do?" << endl;
                cout << "1: Interact" << endl;
                cout << "2: Ignore them" << endl;
                char action;
                cin >> action;
                enemiesViewed.push_back(enemies.at(enemyIndex));
                enemies.erase(enemies.begin()+enemyIndex);

                switch (action) 
                {
                    case '1': 
                    {
                        // Interact with NPC
                        cout<<""<<endl;
                        cout << "NPC: BOO! to pass you have to solve my riddle. " << endl;
                        //ENEMY DIFFICULTY 
                        int difficulty=1;
                        bool correct;
                        //use a srand() to randomly pick questions of a list. preferably with time and % how many questions you have.
                        //void Riddle(int answer)
                        
                        switch(rand()%6+1)//used to pull up question
                        {
                            case 1:
                            {
                                int ans;
                                cout<<"What is 2+2?"<<endl;
                                cin >> ans;
                                if(ans==4)
                                {
                                    Item collectable("collectable", 0);
                                    cout<<"You found a collectable!"<<endl;
                                    player.addItem(collectable);
                                    correct = true;
                                }
                                else 
                                {
                                    correct = false; 
                                }
                                break;
                            }
                                //test your bool 
                            //if true can open shop 
                            case 2:
                            {
                            //NESTED FOR LOOOPPP
                              for (int i = 0; i < 5; i++)
                                {
                                    for (char j = 'A'; j < 'E'; j++)
                                        {
                                            cout << j << ' ';
                                        }
                                    cout << endl;
                                }
                                int ans;
                                cout<<"How many Letter 'C's are in this image?"<<endl;
                                cin>>ans;

                                if(ans==5)
                                {
                                    correct = true;
                                }
                                else 
                                {
                                    correct = false; 
                                }
                                    break;
                            }
                            case 3:
                            {
                            //NESTED FOR LOOOPPP
                                cout<<"You tripped! There is a random chance you will lose health."<<endl;

                                int ans= rand()%6;

                                if((ans==5) || (ans == 1) || (ans == 2) || (ans ==3))
                                    {
                                        correct = true;
                                    }
                                else 
                                    {
                                        correct = false; 
                                    }
                                    break;
                            }
                            case 4:
                            {
                                int ans;
                                cout<<"1:Rock!🤛 2:Paper!🧻 3:Scissors!✂️ Shoot!🐣"<<endl;
                                cin >> ans;

                                int villan= rand()%3+1; 

                                if(ans==villan)
                                {
                                    correct = true;
                                }
                                else 
                                {
                                    correct = false; 
                                }
                                break;
                            }
                            case 5:
                            {
                                int ans;
                                cout<<"I will flip a coin, 1:Heads or 2:Tails??"<<endl;
                                cin >> ans;

                                int coin= rand()%2+1; 

                                if(ans==coin)
                                {
                                    Item collectable("collectable", 0);
                                    cout<<"You found a collectable!"<<endl;
                                    player.addItem(collectable);
                                    correct = true;
                                }
                                else 
                                {
                                    correct = false; 
                                }
                                break;
                            }
                            case 6:
                            {
                                int ans;
                                cout<<"What is the volume of a carton of milk that has the side lengths of 4"<<endl<<"And the height of 4? (enter two digit number)"<<endl;
                                cin>>ans;
                                //save variables into double to have decimal answers 
                                double side= 4;
                                double height= 4;
                                //step one of math, find the area of base
                                double side2 = side*side;
                                // find volume with base and height
                                double area = side2*height;//=64
                                // setprecision makes the answer round correctly (manipulators)
                                // fixed manipulates it to be fixed points
                                 if(ans==64)
                                {
                                    //cout<<"That is correct!"<<endl; 
                                    Item collectable("collectable", 0);
                                    cout<<"You found a collectable!"<<endl;
                                    player.addItem(collectable);
                                    correct = true;
                                }
                                else 
                                {
                                    correct = false; 
                                }
                                break;
                            }
                            default:
                            cout<<"invalid"<<endl;

    

                        }

                        //if win
                        if(correct== true)
                        {
                            char inp;
                            cout<<"You passed! 😊"<<endl;
                            cout<<"Would you like to open the shop? 🏪 (y/n)"<<endl;
                            cin >> inp;
                            if (inp=='y') 
                            {
                                //made new variable in the game.h and makes it equal to eachother 
                                game.setGameState(GAME_STATE_SHOP);
                            }
                            else 
                            {
                            cout << "Goodbye!";
                            //gamestate playing will resume the game 
                            game.setGameState(GAME_STATE_PLAYING);
                            }
                        }
                        else if(correct == false)
                        {
                            // Freddy freddy = game.getFreddyHealth();
                            // int oldHealth = freddy.getFreddyHealth
                            cout<<"You failed, You will deal damage 💀"<<endl;
                            int fred = freddy.getFreddyHealth();
                            if (fred>10)
                            {
                                freddy.damage(10);
                                // freddy.setFreddyHealth(oldHealth - 10)
                                cout << "Goodbye!";
                                //gamestate playing will resume the game 
                                game.setGameState(GAME_STATE_PLAYING);
                            }
                            else if (fred<10)
                            {
                                player.p_damage(10);
                                // freddy.setFreddyHealth(oldHealth - 10)
                                cout << "Goodbye!";
                                //gamestate playing will resume the game 
                                game.setGameState(GAME_STATE_PLAYING);
                            }
                        }
                        else 
                        {
                            cout << "Goodbye!";
                            //gamestate playing will resume the game 
                            game.setGameState(GAME_STATE_PLAYING);
                        }
                        
                        // Pressing enter isn't gonna be a real key, instead pressing enter will just get passed cin
                        break;
                }
                
                //CASE 2 FOR IGNORE
                case '2':
                {
                    int chance= rand()%4;
                    if(player.getItemsOwned().size()==0)
                    {
                        cout<<"You tried escaping with no flashlight"<<endl;
                        cout<<"You couldn't see in the dark so you got hurt"<<endl;
                        cout<<"You delt 10 damage trying to escape"<<endl; 
                        int fred = freddy.getFreddyHealth();
                        if (fred>=10)
                        {
                            freddy.damage(10);
                        }
                        else if (fred<10)
                        {
                            player.p_damage(10);
                        }
                         game.setGameState(GAME_STATE_PLAYING);
                        break;
                    }
                    // Ignore NPC
                    //to ignore npc they get a higher probability of escaping, without a flashlight they
                    //have a lower possiblility of escaping (use same way to get security badge to enter room)
                    for(int i = 0; i < player.getItemsOwned().size(); i ++)  
                    {
                        
                        if(player.getItemsOwned().at(i).getItem() == "flashlight_1")//ur mom
                        {
                            cout << "You tried to ignore the NPC." << endl;
                            cout<<"You have a level 1 flashlight"<<endl;
                        //int chance= rand()%4; //(0,1,2,3,4)
                                if(chance == 0)
                                {
                                    cout<<"You escaped with no damage)"<<endl;
                                    game.setGameState(GAME_STATE_PLAYING); 
                                }
                                else
                                {
                                    cout<<"You escaped, but with damage"<<endl;
                                
                                    int fred = freddy.getFreddyHealth();
                                    if (fred>10)
                                    {
                                        freddy.damage(10);
                                        // freddy.setFreddyHealth(oldHealth - 10)
                                        cout << "Goodbye!";
                                        //gamestate playing will resume the game 
                                        game.setGameState(GAME_STATE_PLAYING);
                                    }
                                    else if (fred<10)
                                    {
                                        player.p_damage(10);
                                        // freddy.setFreddyHealth(oldHealth - 10)
                                        cout << "Goodbye!";
                                        //gamestate playing will resume the game 
                                        game.setGameState(GAME_STATE_PLAYING);
                                    }
                            
                                }

                            //game.setGameState(GAME_STATE_PLAYING);
                            break;
                        }
                        else if (player.getItemsOwned().at(i).getItem() == "flashlight_2")
                        {
                            cout << "You tried to ignore the NPC." << endl;
                            cout<<"You have a level 2 flashlight"<<endl;
                            //(0,1,2,3,4)
                        
                            if((chance == 0) || (chance == 1))
                            {
                                cout<<"You escaped with no damage)"<<endl;
                                game.setGameState(GAME_STATE_PLAYING); 
                            }
                            else
                            {
                                cout<<"You escaped, but with damage"<<endl;
                                int fred = freddy.getFreddyHealth();
                                if (fred>=10)
                                {
                                    freddy.damage(10);
                                // freddy.setFreddyHealth(oldHealth - 10)
                                    cout << "Goodbye!";
                                    //gamestate playing will resume the game 
                                    game.setGameState(GAME_STATE_PLAYING);
                                }
                                else if (fred<10)
                                {
                                    player.p_damage(10);
                                    // freddy.setFreddyHealth(oldHealth - 10)
                                    cout << "Goodbye!";
                                    //gamestate playing will resume the game 
                                    game.setGameState(GAME_STATE_PLAYING);
                                }
                                
                            }

                            //game.setGameState(GAME_STATE_PLAYING);
                            break;

                        }
                        else if (player.getItemsOwned().at(i).getItem() == "flashlight_3")
                        {
                            cout << "You tried to ignore the NPC." << endl;
                            cout<<"You have a level 3 flashlight"<<endl;
                            //int chance= rand()%3; //(0,1,2,3)
                            if((chance == 0) || (chance == 1) || (chance == 2))
                            {
                                cout<<"You escaped with no damage)"<<endl;
                                game.setGameState(GAME_STATE_PLAYING); 
                            }
                            else
                            {
                                cout<<"You escaped, but with damage"<<endl;
                            
                                int fred = freddy.getFreddyHealth();
                                    if (fred>=10)
                                    {
                                        freddy.damage(10);
                                    // freddy.setFreddyHealth(oldHealth - 10)
                                        cout << "Goodbye!";
                                    //gamestate playing will resume the game 
                                        game.setGameState(GAME_STATE_PLAYING);
                                    }
                                else if (fred<10)
                                {
                                    player.p_damage(10);
                                    // freddy.setFreddyHealth(oldHealth - 10)
                                    cout << "Goodbye!";
                                    //gamestate playing will resume the game 
                                    game.setGameState(GAME_STATE_PLAYING);
                                }
                                
                            }

                            //game.setGameState(GAME_STATE_PLAYING);
                            break;
                        }
                        else 
                        {
                            cout<<"You tried escaping with no flashlight"<<endl;
                            cout<<"You couldn't see in the dark so you got hurt"<<endl;
                            cout<<"You delt 10 damage trying to escape"<<endl; 
                            int fred = freddy.getFreddyHealth();
                            if (fred>=10)
                            {
                                 freddy.damage(10);
                            // freddy.setFreddyHealth(oldHealth - 10)
                                 //gamestate playing will resume the game 
                                 game.setGameState(GAME_STATE_PLAYING);
                            }
                             else if (fred<10)
                            {
                             player.p_damage(10);
                             // freddy.setFreddyHealth(oldHealth - 10)
                             //gamestate playing will resume the game 
                             game.setGameState(GAME_STATE_PLAYING);
                            }
                        break;
                        }
                    }
                    break;

                }
                default:
                {
                    // Player input an invalid input
                    cout << "Please enter a valid action!!" << endl;
                    break;
                }
                
            }
                break;
                //BREAKS CAN BREAK YOU OUT OF LOOPS
        }
                
        //switch case if you quit game 
        case GAME_STATE_EXIT: //GAME STATE 4
        {
            cout<<"Leaving game...💔💔"<<endl;
            return;
            break;
        }
        //lose gamw if you die
        case GAME_STATE_DEAD: //game state 5
        {
            cout << "You died!!⚰️⚰️ Game over!!😔😔😔" << endl;
            return;
            break;
        }
        //prints the menu 
        case GAME_STATE_MENU: //game state 6
        {
            // Render main menu
            int newGameState = mainMenu();
            game.setGameState(newGameState);
            break;
        }
        case GAME_STATE_CLOCK://game state 7
        {
            ifstream myFile("clock.txt");
            string line;
            while(getline(myFile, line))
            {
                cout<< line <<endl; 
            }
            myFile.close();
            game.setGameState(GAME_STATE_MENU);
            break;
        }
        case GAME_STATE_MESSAGE://game state 8
        {
            ifstream myFile("Freddy.txt");
            string line;
            while(getline(myFile, line))
            {
                cout<< line <<endl; 
            }
            myFile.close();

            cout<< "PRESS ANY KEY TO GO BACK TO MAIN MENU" << endl;
            char inp;
            cin >> inp;

            game.setGameState(GAME_STATE_MENU);
            break;
        }

        case GAME_STATE_HELP_MENU : //game state 9
        {
            // Print out controls
            cout << "W: Move Up" << endl 
            << "A: Move Left" << endl 
            << "S: Move Down" << endl 
            << "D: Move Right" << endl 
            << "Q: Exit Game" << endl
            << "PRESS ANY KEY TO GO BACK TO MAIN MENU" << endl;
            char inp;
            cin >> inp;
            
            // Pressing enter isn't gonna be a real key, instead pressing enter will just get passed cin
            
            // Set game state back to main menu
            game.setGameState(GAME_STATE_MENU);
            break;
        }

        case GAME_STATE_SHOP: //game state 10
        {
            cout<<"Player Coins:"<<player.getCoins()<<endl;
            cout << "Shop:" << endl;
            cout << "┌──❀*̥˚──◌-----◌───❀*̥˚-----Help menu----◌───❀*̥---◌──❀*̥˚─┐" << endl;
            cout << "Having a flashlight will help you have a higher chance of escape" << endl;
            cout << "Freddy Charges will heal Freddy's health" << endl;
            cout << "You NEED security Badges to enter rooms" << endl;
            cout << "Can only get a Freddy Upgrade if user enters a room (+20 Freddy Health)" << endl;
            cout << "Selling collectables will give you more money" << endl;
            cout << "└◌───❀*̥˚----◌───❀*̥˚------Shop----------◌───❀*̥---◌───❀*̥˚┘" << endl;
            cout << "1. Flashlight - 5 coins-20 coins" << endl;
            cout << "2. Security Badge(key to enter rooms) - 20 coins" << endl;
            cout << "3. Freddy Charge (+10 health) - 10 coins" << endl;
            cout << "4. Freddy Upgrade- 10 coins " << endl;
            cout << "5. Sell Collectables- Gain 15 coins"<<endl;
            cout << "6. Quit back to game" << endl;
                    ///**************************************** ITEMS INSIDE OF iTEmS 
            char itemId;
            cin >> itemId;

                  // Figure out which item they want to buy
            switch (itemId) 
            {
                case '1':
                {
                    char flash;
                    cout<<"Which Flashlight do you want?"<<endl;
                    cout<<"1: level 1 Flashlight"<<endl;
                    cout<<"2: level 2 Flashlight"<<endl;
                    cout<<"3: level 3 Flashlight"<<endl;
                    cin>>flash;
                    switch(flash)
                    {
                        case '1':
                        {
                            int cost_1 = 5;

                            // They entered "1" so they want to buy the flash light
                            Item flashlight_1("flashlight_1", cost_1);

                            // Check to make sure player can afford the item
                            //Player player = game.getPlayer();
                            //int coinsPlayerHas = player.getCoins();
                            //player.getCoins()
                            if (coinsPlayerHas >= cost_1) 
                            {
                                // They have enough coins
                                player.addItem(flashlight_1);
                                
                                // Take away coins after purchase
                                player.setCoins(coinsPlayerHas - cost_1);
                                cout<< ""<<endl;
                                cout << "Thank you for your purchase!" << endl;
                                cout<< ""<<endl;
                                //game.setGameState(GAME_STATE_SHOP);
                                game.setGameState(GAME_STATE_SHOP);
                            }
                            else 
                            { 
                                cout<< ""<<endl;
                                cout << " too broke";
                                cout<< ""<<endl;
                    
                            }
                            break;
                        }
                        case '2':
                        {
                            int cost_2 = 10;

                            // They entered "1" so they want to buy the flash light
                            Item flashlight_2("flashlight_2", cost_2);

                            // Check to make sure player can afford the item
                            //Player player = game.getPlayer();
                            // int coinsPlayerHas = player.getCoins();

                            if (coinsPlayerHas >= cost_2) 
                            {
                                // They have enough coins
                                player.addItem(flashlight_2);
                                
                                // Take away coins after purchase
                                player.setCoins(coinsPlayerHas - cost_2);
                                cout<< ""<<endl;
                                cout << "Thank you for your purchase!" << endl;
                                cout<< ""<<endl;
                                //game.setGameState(GAME_STATE_SHOP);
                                game.setGameState(GAME_STATE_SHOP);
                            } 
                            else 
                            { 
                                cout<< ""<<endl;
                                cout << " too broke";
                                cout<< ""<<endl;
                    
                            }
                            break;
                        }
                        case '3':
                        {
                            int cost_3 = 15;

                            // They entered "1" so they want to buy the flash light
                            Item flashlight_3("flashlight_3", cost_3);

                            // Check to make sure player can afford the item
                            //Player player = game.getPlayer();
                            //int coinsPlayerHas = player.getCoins();

                            if (coinsPlayerHas >= cost_3) 
                            {
                                // They have enough coins
                                player.addItem(flashlight_3);
                                
                                // Take away coins after purchase
                                player.setCoins(coinsPlayerHas - cost_3);
                                cout<< ""<<endl;
                                cout << "Thank you for your purchase!" << endl;
                                cout<< ""<<endl;
                            // game.setGameState(GAME_STATE_SHOP);
                                game.setGameState(GAME_STATE_SHOP);
                            } 
                            else 
                            { 
                                cout<< ""<<endl;
                                cout << " too broke";
                                cout<< ""<<endl;
                                
                            }
                            break;
                        }
                    }

                        
                        break;

                 }
                case '2':
                {
                    int cost_4 = 10;

                    // They entered "2" so they want to buy the room key
                    Item RoomKey("Security Badge", 20);

                    // Check to make sure player can afford the item
                    // Player player = game.getPlayer();
                    // int coinsPlayerHas = player.getCoins();
                    // vector<Item> op_1 = player.getItemsOwned();
                    // cout << "Before insert " << op_1.size() << endl;
                    if (coinsPlayerHas >= cost_4) 
                    {
                        // They have enough coins
                        player.addItem(RoomKey);
                        // vector<Item> op = player.getItemsOwned();
                        // cout << "After insert " << op.size() << endl;

                        
                        // Take away coins after purchase
                        player.setCoins(coinsPlayerHas - cost_4);
                        cout<< ""<<endl;
                        cout << "Thank you for your purchase!" << endl;
                        cout<< ""<<endl;
                        for(int i = 0; i < player.getItemsOwned().size(); i ++) 
                        {
                        cout<<player.getItemsOwned().at(i).getItem()<<endl;
                        }
                        game.setGameState(GAME_STATE_SHOP);

                    } 
                    else 
                    { 
                        cout<< ""<<endl;
                        cout << " too broke"<<endl;
                        cout<< ""<<endl;
                    
                    }

                        
                        break;

                }
                case '3':
                {
                    int cost_5 = 10;

                    // They entered "3" so they want to buy the charge 
                    Item FredReCharge("Freddy Charge", cost_5);

                    // Check to make sure player can afford the item
                    // Player player = game.getPlayer();
                    // int coinsPlayerHas = player.getCoins();

                    if (player.getCoins() >= cost_5) 
                    {
                        // They have enough coins
                        player.addItem(FredReCharge);
                        freddy.re_charge(10);
                        
                        // Take away coins after purchase
                        player.setCoins(coinsPlayerHas - cost_5);
                        cout<< ""<<endl;
                        cout << "Thank you for your purchase!" << endl;
                        cout<< ""<<endl;
                        //game.setGameState(GAME_STATE_SHOP);
                        game.setGameState(GAME_STATE_SHOP);
                    } 
                    else if(player.getCoins()< cost_5)
                    { 
                        cout<< ""<<endl;
                        cout << " too broke"<<endl;
                        cout<< ""<<endl;
                        game.setGameState(GAME_STATE_SHOP);
                        
                    }

                                
                    break;

                }
                case '4':
                {
                    bool upgrade_b= false ;
                    int cost_6 = 10;

                    // They entered "3" so they want to buy the charge 
                    Item Upgrade("Upgrade", cost_6);
                    if(player.getItemsOwned().size()==0)
                        {
                            char yes; 
                            cout<<"You haven't been in a room yet!"<<endl;
                            cout<<"To unlock an upgrade for Freddy enter a room first."<<endl;
                            cout<<"Go find a room (y/y)"<<endl;
                            cin>> yes; 
                            if(yes=='y')
                            {
                            game.setGameState(GAME_STATE_SHOP);
                            }
                            else{
                                cout<<"Press 'y' key to state that you understand."<<endl;
                            }
                        }
                    // Check to make sure player can afford the item
                    // Player player = game.getPlayer();
                    // int coinsPlayerHas = player.getCoins();
                    for(int i = 0; i < player.getItemsOwned().size(); i ++)                      
                    { 
                        if(player.getItemsOwned().at(i).getItem() =="secretItem")
                        {
                          upgrade_b= true; 
                        
                        }
                        else if(player.getItemsOwned().at(i).getItem() !="secretItem")
                        {
                           upgrade_b = false ; 
                        }

                    }
                    if(upgrade_b == true )
                    {
                          if (coinsPlayerHas >= cost_6) 
                            {
                                  // They have enough coins
                                //player.addItem(FredReCharge);
                                freddy.re_charge(20);
                                
                                // Take away coins after purchase
                                player.setCoins(coinsPlayerHas - cost_6);
                                cout<< ""<<endl;
                                cout << "Thank you for your purchase!" << endl;
                                cout<< ""<<endl;
                                //game.setGameState(GAME_STATE_SHOP);
                                game.setGameState(GAME_STATE_SHOP);
                            // mainMenu();
                            } 
                    }
                    else if (upgrade_b == false)
                    {
                         cout<<"Enter another room! One upgrade per room 😟"<<endl;
                            cout<<"No upgrade avalible."<<endl; 
                            game.setGameState(GAME_STATE_SHOP);
                    }
                    else 
                    { 
                        cout<< ""<<endl;
                        cout << " too broke";
                        cout<< ""<<endl;
                        game.setGameState(GAME_STATE_SHOP);
                            
                    }
                        
                        break;

                }
                case '5':
                {
                    bool collectable = false;
                    int cost_1 = 15;
                    if(player.getItemsOwned().size()==0)
                        {
                            char yes;
                            cout<<"You don't have any collectables.👒💍👑"<<endl;
                            cout<<"Find an enemy! Sometimes they will drop collectables."<<endl;
                            cout<<"Go find an enemy (y/y)"<<endl;
                            cin>> yes; 
                            if(yes=='y')
                            {
                            game.setGameState(GAME_STATE_SHOP);
                            }
                            else{
                                cout<<"Press 'y' key to state that you understand."<<endl;
                            }
                            game.setGameState(GAME_STATE_SHOP);
                        }
                    for(int i = 0; i < player.getItemsOwned().size(); i ++)                      
                    { 
                        if(player.getItemsOwned().at(i).getItem() == "collectable")
                        {
                            collectable = true ;
                        }

                        else if (player.getItemsOwned().at(i).getItem() != "collectable")
                        {
                            collectable = false ; 
                            // They have enough coins
                            //player.addItem(FredReCharge);
                            
                            // Take away coins after purchase
                            //player.setCoins(coinsPlayerHas + cost)
                            // mainMenu();
                        }
                    }
                   if (collectable == true)
                   {
                 
                      cout<<"Oh you have a collectable"<<endl;
                            cout<<"I will buy that from you for 15 coins!"<<endl;
                            player.setCoins(coinsPlayerHas + cost_1);
                            game.setGameState(GAME_STATE_SHOP);
                   }
                   else if(collectable == false )
                   {
                       cout << "You do not have any collectables :(" << endl;
                            cout<<"Find an enemy! Sometimes they will drop collectables."<<endl;
                            game.setGameState(GAME_STATE_SHOP);
                   }
                    // else 
                    // { 
                    //     cout << " too broke";
                
                    // }

                        
                        break;

                }
                case '6':
                {
           
                    //mainMenu();  
                    game.setGameState(GAME_STATE_PLAYING);
                    break;

                }
                default: break;
            }

                //game.setGameState(GAME_STATE_SHOP);
                //original- 
                //game.setGameState(GAME_STATE_PLAYING); 
                //int gameState = buyItem(game, inp);
                break;
        }

        case GAME_STATE_BAG://game state 11
        {
          // vector<string> v= player.getItemsOwned();
          //for loop to get all of the items
          cout<<"Items in bag:"<<endl;
           // cout<<"If nothing prints that means you have no items yet!"<<endl; 
            if(player.getItemsOwned().size()==0)
            {
                cout<<"If nothing prints that means you have no items yet!"<<endl; 
                  game.setGameState(GAME_STATE_MENU);
                 break;
            }
          //cout<<"If nothing prints that means you have no items yet!"<<endl; 
          else if(player.getItemsOwned().size() > 0)
          {
            for(int i = 0; i < player.getItemsOwned().size(); i ++)                      
            {    
              //this gets the item name from player item list                                                                   
              cout<< player.getItemsOwned().at(i).getItem()<<endl;                                 
            } 
            
          }
           
            game.setGameState(GAME_STATE_MENU);
            break;   
        }
        
        case GAME_STATE_GAME_END://game state 12
        {
                cout<<"You made it to the end! You can Finally leave the Pizza Plex! :) 🐻"<<endl;
                ifstream myFile("house.txt");
                string line;
                while(getline(myFile, line))
                {
                    cout<< line <<endl; 
                }
                myFile.close();
                cout<<"Finally stepping outside you get to see the world again..."<<endl; 
                cout<<"You won! 🎉🎉🎉🎉"<<endl;
                cout<<"Here are the list of enemies you encountered this game:"<<endl;
                //enemiesViewed.()
                ofstream fout;
                fout.open("EnemyEncounter.txt");
                for(int i = 0; i < enemiesViewed.size(); i ++) 
                {
                fout<<enemiesViewed.at(i).getEnemyBody()<<endl;
                }
                fout.close();
                //////output file 
                //cout<<"Enemies you encountered:" <<endl;            
                ifstream myFile_1("EnemyEncounter.txt");
                string line_1;
                while(getline(myFile_1, line_1))
                {
                    cout<< line_1 <<endl; 
                }
                myFile.close();
                //cout file with encountered enemies 
                // while(fin.eof())
                // {
                //     getline(fin,str);
                //     cout<<str<<endl;
                // }

                game.setGameState(GAME_STATE_EXIT);
                break;
        }
    }

       

}
 

}


int main()
{

    srand(time(NULL));

    cout<<"Welcome to the Pizza Plex!"<<endl;
    cout<<"You are stuck inside and in order to escape you need survive until 6am (or reach the end of the map)"<<endl;
    cout<<"(There is also a catch to this you will see once you meet the exit)"<<endl; 
    cout<<"You will encounter Enemies randomly on the map, if you defeat one you will be able to open their shop"<<endl;
    cout<<"If you lose, Freddy will lose health"<<endl;
    cout<<"If Freddy dies you will take damage instead but you can buy recharges that bring him back"<<endl;
    cout<<"You can charge Freddy's health but not your own, once your health is down it stays down and you lose"<<endl;
    cout<<"You can only enter rooms if you have a security badge, you can only get them from fighting enemies"<<endl; 
    cout<<"After you enter a room there will be another enemy waiting inside for you"<<endl; 
    cout<<"If you win you can move on, but if you lose there will be a consequence"<<endl;
    cout<<"You get coins everytime you move but dont move too much!"<<endl; 
    cout<<"There is an enemy called Vanny, everytime you move her anger goes up! Beware!"<<endl; 
    cout<<"We recommend you take a look at 2: Help on the menu before starting the game!"<<endl;
    cout<<"Enjoy the game!"<<endl;
     cout<<"You are entering... 😨"<<endl;

    Game game;
    game.setGameState(GAME_STATE_MENU);

    // Create our player
    int thacoin= 10;
    Player mainPlayer(100, thacoin);

    // Set our game's player object to our new player object
    game.setPlayer(mainPlayer);
    
    // Call map setup and game loop
    Map map = setupMap();
    gameLoop(game, map);
}


/////////////////////////////
// //testing Enemy class
// Enemy u3 = Enemy("Roxy",6);
// cout << u3.getEnemyBody() << endl;
// cout << u3.getEnemyLevel() << endl;
// //expected output 
// //Roxy
// //6

// ///////////////////////////////
// //testing Freddy class
//  Freddy health_1;// calling default constructor
//     double current_health= health_1.getFreddyHealth();
//     cout<< "Freddy's current health: "<< current_health<<endl;
    
//     double initial_health = 1000;
//     Freddy health_2 = Freddy(initial_health);
//     cout<<"Freddy's health after charge:"<< health_2.getFreddyHealth()<<endl;
//expected output 
// Freddy's current health: 0
// account 2 balance:1000

/////////////////////////////
//testing Item class
// Item it2= Item("Flashlight",10);
// cout << it2.getItem() << endl;
// cout << it2.getCost() << endl;
//expected output 
//Flashlight
//10

//g++ Enemy.cpp Freddy.cpp Map.cpp Item.cpp Player.cpp Game.cpp GameDriver.cpp