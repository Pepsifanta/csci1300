#include "Item.h"
#include <iostream>
using namespace std;

      Item::Item()
      {
        item_="";
        cost_= 0;
      }
           
            Item::Item(string item_name, int cost)
            {
               item_ = item_name;
               cost_= cost;
        
                if(cost_ >=0)
                {
                    cost_ = cost;
        
                }
                else
                {
                    cost_ = 0;
                } 

            }

            string Item::getItem()
            {
                return item_;
            }
            void Item::setItem(string item_name)
            {
                item_ = item_name;
            }

            int Item::getCost()
            {
                return cost_;
            }
            void Item::setCost(int cost)
            {
                if(cost>=0)
                {
                cost_= cost;
           
                }
            }