#include <iostream>
#include "Buffchat.h"
#include "Post.h"
#include "User.h"
#include <fstream>


using namespace std;

int main()
{

//************** CHECKS ADDPOST

	
// make Buffchat object 
Buffchat myBuffchat5;
// call readPosts 
int rv5 = myBuffchat5.readPosts("posts.txt"); 
cout << "rv = " << rv5 << endl;

// add a new post
cout << myBuffchat5.addPost("Snow Day!!!", "spiritedMues", "10/25/22");
// check if num_posts_ was updated to reflect the new addition
cout << "num_posts_: " << myBuffchat5.getNumPosts() << endl;

//EXPECTED OUTPUT 
// rv = 4
// num_posts_: 4
// 1
// num_posts_: 5



///////********** checks printPopularPosts
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find the top 2 posts for year 20
//cout << myBuffchat.printPopularPosts(2, "20") << endl;
myBuffchat.printPopularPosts(2, "20"); 
           
//EXPECTED OUTPUT 

//No posts stored for year 20


//********** TESTING findLeastActiveUser
// make Buffchat object 
Buffchat myBuffchat420;
// call readPosts 
int rv420 = myBuffchat420.readPosts("posts.txt"); 
cout << "rv = " << rv420 << endl;
// call readLikes
int rv4200 = myBuffchat420.readLikes("users.txt"); 
cout << "rv1 = " << rv4200 << endl;

// findLeastActiveUser
User u = myBuffchat420.findLeastActiveUser();
// check if empty object was returned
cout << "Username: " << u.getUsername() << endl;
// this function prints the likes values for the user
cout << "Likes: " << endl;
u.getUsername();

//EXPECTED OUTPUT 
//Username: michelleryan
//Likes: -1,-1,-1

//*************** checks count unique likes 
// make Buffchat object 
Buffchat myBuffchat9;
// call readPosts 
int rv9 = myBuffchat9.readPosts("posts.txt"); 
cout << "rv = " << rv9 << endl;
// call readLikes
int rv99 = myBuffchat9.readLikes("users.txt"); 
cout << "rv1 = " << rv99 << endl;

// find unique likes
cout << myBuffchat9.countUniqueLikes("michelleryan");

//EXPECTED OUTPUT 
//rv = 4
// rv1 = 5
// 4  
















    //***** checks read post 
// // make Buffchat object 
// Buffchat myBuffchat;
// // call readPosts 
// int rv = myBuffchat.readPosts("posts.txt"); 
// // print values 
// cout << "rv = " << rv << endl; 
// cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 
// // print posts 
// myBuffchat.printPostsByYear("20");

//EXPECTED output 
// rv = 2 
// num_posts_ = 2
// Here is a list of posts for year 19
// Sko buffs!!
// Come get involved in robotics @ cu!

//******** checks print posts by year

// make Buffchat object 
Buffchat myBuffchat2;

// read post file 
int rv2 = myBuffchat2.readPosts("posts.txt"); 

// call printPostsByDate
myBuffchat2.printPostsByYear("21");

//EXPECTED output 
//outputs all the lines 

//********************** checks READ LIKES

// make Buffchat object 
Buffchat myBuffchat3;
// call readPosts 
int rv3 = myBuffchat3.readPosts("posts.txt"); 
cout << "rv = " << rv << endl; 
        
// call readLikes and check return
int rv33 = myBuffchat3.readLikes("users.txt"); 
cout << "rv1 = " << rv33 << endl; 

// check value of getNumUsers 
cout << "num_users_ = " << myBuffchat3.getNumUsers() << endl;

// print user’s ratings 
string name3 = "ilovechip";
cout << myBuffchat3.getLikes(name3, "michelleryan") << endl;
cout << myBuffchat3.getLikes(name3, "roboticscu") << endl;
cout << myBuffchat3.getLikes(name3, "bookworm43") << endl;
cout << myBuffchat3.getLikes(name3, "kate128") << endl;

//EXPECTED OUTPUT 
//rv = 4
//rv1 = 5 
//num_users_ = 5 
//4 
//-1 
//1 
//8 


//************ checks GETLIKES
// // make Buffchat object 
// Buffchat myBuffchat4;

// // add posts
// int rv4 = myBuffchat4.readPosts("posts.txt");
// cout << "rv = " << rv4 << endl;

// // add users
// int rv44 = myBuffchat4.readLikes("users.txt");
// cout << "rv1 = " << rv44 << endl;

//EXPECTED OUTPUT 
//rv = 50
//rv1 = 50


//**************** checks findtaguser





}