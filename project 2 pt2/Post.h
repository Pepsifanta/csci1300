//talking to compiler
// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 1 - Post class
#ifndef POST_H
#define POST_H

#include <iostream>
using namespace std;
//****************** what is in the post.cpp
class Post 
{
        private:
            string body_;
            string post_author_;
            int num_likes_;
            string date_;
        public: 
        //Default: constructor
            Post();
            //Parameterized: constructor
            Post( string post_body, string author, int likes, string post_date);

            string getPostBody();
            void setPostBody(string post_body);

            string getPostAuthor();
            void setPostAuthor(string author);

            int getPostLikes();
            void setPostLikes(int likes);

            string getPostDate();
            void setPostDate(string post_date);

};
//tell compiler to read it 
#endif