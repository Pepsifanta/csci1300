// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 3 - readPosts
#include <iostream>
#include "Post.h"
#include <fstream>

using namespace std;

//function 
void printPostsByYear(Post post[], string year, int num_posts_stored)
{
//if there is no posts in the input 
    if(num_posts_stored<=0)
    {
        cout<<"No posts are stored"<<endl;
        return;
    }
//variables to check if there are posts for the given year
    bool foundForYear = false;
    int startIndex = 0;
//new string for list of all posts in one gievn year
    string postBodies[num_posts_stored] = {};
//for loop to go through array 
    for(int i = 0; i < num_posts_stored; i++)
    {
        //temparay varaibel that holds the date 
        string temp = post[i].getPostDate();
//if esle to check the year and if it matches 
        if(temp.substr(6,2)==year)
        {
            //to find out where the post in a certain year start 
            if (!foundForYear) {
                startIndex = i;
            }
            //when it turns true that means you found a post for that year 
            foundForYear = true;
            //update the array of post bodies 
            postBodies[i] = post[i].getPostBody();
        }

    }
//if you found posts for that year print the lists of posts 
    if (foundForYear) {
         cout<< "Here is a list of posts for year "<<year<<endl;
         //loops through post bodies array 
         for (int i = startIndex; i < num_posts_stored; i++) {
            //new variable for the bodies
            string body = postBodies[i];
            //to check if the post isn't blank
            if (body.length() <= 0) {
                continue;
            }
            //
            cout << body << endl;
         }
    } else {
        //if there are no matches output 
        cout << "No posts stored for year " << year << endl;
    }
}

int main()
{
 // two posts that are posted in year 22.
Post p_1 = Post("new post1","Lisa1", 10, "10/02/22");
Post p_2 = Post("new post2","Lisa2", 11, "10/02/22");
Post p_3 = Post("new post3","Lisa3", 8, "10/02/19");
        
Post list_of_posts[] = {p_1, p_2, p_3};
int number_of_posts = 3;
string year = "22";
printPostsByYear(list_of_posts, year, number_of_posts);

//expected output 
// Post author Raegan
// Post body new post
// Post date 10/02/22
// Post likes 10

	
// no posts stored with numberOfPosts 0
Post list_Posts2[] = {};
int number_Posts2 = 0;
string year2 = "20";
printPostsByYear(list_Posts2, year2, number_Posts2);
//expected output 
//No posts are stored

// no posts released in year 21
Post p1 = Post("new post1","Lisa1", 10, "10/02/22");
Post p2 = Post("new post2","Lisa2", 10, "10/02/22");
Post p3 = Post("new post3","Lisa3", 10, "10/02/22");
Post list_Posts3[] = {p1, p2, p3};
int number_Posts3 = 3;
string year3 = "21";
printPostsByYear(list_Posts3, year3, number_Posts3);

//expected output
//No posts stored for year 21

}