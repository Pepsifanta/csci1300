//talking to compiler
// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 2 - Problem 1- Buffchat Class
#ifndef BUFFCHAT_H
#define BUFFCHAT_H
#include <fstream>
#include <iostream>
#include "Post.h"
#include "User.h"
using namespace std;
//****************** what is in the post.cpp
class Buffchat
{
        private:
            static const int posts_size_= 50;
            static const int users_size_= 50;
            Post posts_[50];
            User users_[50];
            int num_posts_ = 0;
            int num_users_ = 0;
            
        public: 
        //Default: constructor
            Buffchat();

            //Parameterized: constructor ARE THERE NONE????
            Buffchat(int, int);

            int getPostSize();

            int getUserSize();

            int getNumPosts();

            int getNumUsers();

            int readPosts(string file_name);
            void printPostsByYear(string year);
            int readLikes(string file_name);
            int getLikes(string post_author, string username);
            void findTagUser(string username_tag);
            bool addPost(string post_body, string post_author, string date);
            void printPopularPosts(int count, string year);
            User findLeastActiveUser();
            int countUniqueLikes(string post_author);

            

};
//tell compiler to read it 
#endif