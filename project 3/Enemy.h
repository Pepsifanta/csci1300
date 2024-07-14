#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;
//****************** what is in the post.cpp
class Enemy  
{
        private:
            string enemy_name;
            int level_;
            int angerLevel;
        
        public: 
        //Default: constructor
            Enemy();
            //Parameterized: constructor
            Enemy(string enemy_body, int level);

            string getEnemyBody();
            void setEnemyBody(string enemy_body);

            int getEnemyLevel();
            void setEnemyLevel(int level);

            int getAngerLevel();
            void setAngerLevel(int level);
};
//tell compiler to read it 
#endif