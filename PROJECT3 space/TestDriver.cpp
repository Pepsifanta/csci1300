#include <iostream>
#include "Enemy.h"
#include "Item.h"
#include "Player.h"
#include "Freddy.h"
#include <fstream>

using namespace std; 

int main()
{

///////////
//testing Enemy class
Enemy u3 = Enemy("Roxy",6);

cout << u3.getEnemyBody() << endl;
cout << u3.getEnemyLevel() << endl;
//expected output 
//Roxy
//6


///////////
//testing Freddy class
Enemy u3 = Enemy("Roxy",6);

cout << u3.getEnemyBody() << endl;
cout << u3.getEnemyLevel() << endl;
//expected output 
//Roxy
//6


}