// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 6 - getLikes
#include <iostream>
#include "Post.h"
#include "User.h"
#include <fstream>

using namespace std;
//make function 
int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    int sus = -1;
    int susser =-1 ;
    //if there are no users stored in user array 
    if (num_posts_stored == 0 || num_users_stored == 0)
    {
    //return -2
        return -2;
    }
   for(int i = 0; i < num_posts_stored;i++)
   {
        if(posts[i].getPostAuthor()== post_author)
        {

            sus = i;
            for(int j = 0; j < num_users_stored; j++)
            {
                if(users[j].getUsername()== username)
                {
                    susser = j; 
                    return users[susser].getLikesAt(sus);
                }
            }

        }

    //break;

   }
 
if((sus==-1)||(susser==-1))
{
    return -3;
}
}

    // bool foundPostAuthor = false;

    // User who;
    // //searches through user array
    // bool foundUser = false;
    // for (int i = 0; i < num_users_stored; i++) {
    //     User SUSpect = users[i];
    //     //if the users username matches username arr we found post author 
    //     string name = SUSpect.getUsername();
    //     if (name == username) {
    //         foundUser = true;
    //         who = SUSpect;
    //         break;
    //     }
    // }

    // if (!foundUser)
    //     return -3;

    // for (int i = 0; i < num_posts_stored; i++)
    // {
    //     Post p = posts[i];
    //     string author = p.getPostAuthor();
    //     if (author == post_author) {
    //         // found first post by specific author in array
    //         foundPostAuthor = true;
            
    //         // go through whos likes
    //         int nLikes = who.getLikesAt(i);
    //         return nLikes;
    //     } 
    // }
    

int main()
{
//username and post_author exist, non zero likes
Post posts[3]; 
User users1[1];
string post_author = "susanfrances";
int num_posts_stored2 = 7;
string username = "chipthebuffalo";
int num_users_stored2 = 5;

cout << getLikes(post_author, posts, num_posts_stored2, username, users1, num_users_stored2)<<endl;

}


/// dede nina 