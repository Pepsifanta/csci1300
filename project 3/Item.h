#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;
//****************** what is in the post.cpp
class Item  
{
        private:
            string item_;
            int cost_;
        
        public: 
        //Default: constructor
            Item();
            //Parameterized: constructor
            Item(string item_name, int cost);

            string getItem();
            void setItem(string item_name);

            int getCost();
            void setCost(int cost);

};
//tell compiler to read it 
#endif