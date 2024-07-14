// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 4- User Class

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;
//****************** what is in the post.cpp
class User
{
        private:
            string username_;
            int num_posts_;
            static const int size_= 50;
            int likes_[size_];
        public: 
        //Default: constructor
            User();
            //Parameterized: constructor
            User( string usernameParam, int likesParam[], int numPostParam);

            string getUsername();
            void setUsername(string username);

            int getLikesAt(int post_id);
            bool setLikesAt(int post_id, int num_likes);

            int getNumPosts();
            void setNumPosts(int posts);

            int getSize(); 

};
//tell compiler to read it 
#endif