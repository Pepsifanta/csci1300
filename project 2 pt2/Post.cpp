// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 1 - Post class
#include <iostream>
#include "Post.h"

using namespace std;

Post::Post()
{
    body_ = "";
    post_author_ ="" ;
    num_likes_ =0 ;
    date_= "";
}


    Post::Post(string post_body, string author, int likes, string post_date)
    {
        body_ = post_body;
        post_author_=author;
        // num_likes_= likes;
        date_= post_date;
         if(num_likes_ >=0)
        {
            num_likes_ = likes;
  
        }
        else
        {
            num_likes_ = 0;
        }
      
    }
    string Post::getPostBody()
    {
          return body_;
    }
    void Post::setPostBody(string post_body)
    {
        body_=post_body;
    }

    string Post::getPostAuthor()
    {
        return post_author_;
    }
    void Post::setPostAuthor(string author)
    {
        post_author_= author;
    }

    int Post::getPostLikes()
    {
        return num_likes_;
    }
    void Post::setPostLikes(int likes)
    {
        if(likes>=0)
        {
            num_likes_= likes;
           
        }
        
    }

    string Post::getPostDate()
    {
        return date_;
    }
    void Post::setPostDate(string post_date)
    {
        date_= post_date;
    }


