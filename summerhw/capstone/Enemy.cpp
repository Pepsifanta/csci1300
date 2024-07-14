#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy()
{
    enemy_name="";
    level_=0;
}


    Enemy::Enemy(string enemy_body, int level)
    {
        enemy_name = enemy_body;
        level_= level;
        angerLevel = 0;
        
         if(level_ >=0)
        {
            level_ = level;
  
        }
        else
        {
            level_ = 0;
        }
      
    }
    string Enemy::getEnemyBody()
    {
          return enemy_name;
    }
    void Enemy::setEnemyBody(string enemy_body)
    {
        enemy_name= enemy_body;
    }

    int Enemy::getEnemyLevel()
    {
        return level_;
    }
    void Enemy::setEnemyLevel(int level)
    {
        if(level>=0)
        {
            level_= level;
           
        }
        
    }

    int Enemy::getAngerLevel() {
        return angerLevel;
    }

    void Enemy::setAngerLevel(int level) {
        angerLevel = level;
    }