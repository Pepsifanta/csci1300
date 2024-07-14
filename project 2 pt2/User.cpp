// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 4- User Class

#include "User.h"

using namespace std;

User::User()
{
            username_=""; 
            num_posts_ =0;
            for (int i = 0; i<size_; i++)
                likes_[i] = -1;
}
            //Parameterized: constructor
            User::User( string usernameParam, int likesParam[], int numPostParam)
            {
                username_= usernameParam;
                num_posts_ = numPostParam;
                
                int endOfArray = 0;
                for (int i = 0; i<numPostParam; i++) {
                    likes_[i] = likesParam[i];
                }
                for (int i = numPostParam; i < size_; i++)
                    likes_[i] = -1;
            }

            string User::getUsername()
            {
                return username_;
            }
            void User::setUsername(string username)
            {
                username_ = username;
            }

            int User::getLikesAt(int post_id)
            {
                
                if (post_id >= size_ || post_id < 0) {
                    return -2;
                }
                
                return likes_[post_id];
            }
            bool User::setLikesAt(int post_id, int num_likes)
            {

                if (post_id < 0 || post_id >= num_posts_) {
                    return false;
                }

                if (num_likes < -1 || num_likes > 10) {
                    return false;
                }
                
                likes_[post_id] = num_likes;
                return true;
            }

            int User::getNumPosts()
            {
                return num_posts_;
            }
            void User::setNumPosts(int posts)
            {
                if (posts >= 0 && posts <= size_) {
                    num_posts_ = posts;
                }
            }

            int User::getSize()
            {
                return size_;
            }