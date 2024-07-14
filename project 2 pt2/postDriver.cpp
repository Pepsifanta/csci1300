// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 1 - Post class
#include <iostream>
#include "Post.h"
#include <fstream>

using namespace std; 

int main()
{
    Post my_post_1 = Post(); // default constructor
    cout << "Post author " << my_post_1.getPostAuthor() << endl;
    cout << "Post body " << my_post_1.getPostBody() << endl;
    cout << "Post date " << my_post_1.getPostDate() << endl;
    cout << "Post likes " << my_post_1.getPostLikes() << endl;

    //expected output 
    // Post author 
    // Post body 
    // Post date 
    // Post likes 0

    Post my_post_2 = Post("new post","Raegan", 10, "10/02/22"); // parameterized constructor
    cout << "Post author " << my_post_2.getPostAuthor() << endl;
    cout << "Post body " << my_post_2.getPostBody() << endl;
    cout << "Post date " << my_post_2.getPostDate() << endl;
    cout << "Post likes " << my_post_2.getPostLikes() << endl;

    //expected output 
//     Post author Raegan
//     Post body new post
//     Post date 10/02/22
//     Post likes 10


Post my_post_3= Post("Go buffs","Ian", 12, "10/02/22"); // parameterized constructor
    cout << "Post author " << my_post_3.getPostAuthor() << endl;
    cout << "Post body " << my_post_3.getPostBody() << endl;
    cout << "Post date " << my_post_3.getPostDate() << endl;
    cout << "Post likes " << my_post_3.getPostLikes() << endl;


    return 0;

    //Expected output 
// Post author Ian
// Post body Go buffs
// Post date 10/02/22
// Post likes 12
}
