// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 4- User Class

#include <iostream>
#include "User.h"
#include <fstream>

using namespace std; 

int main()
{

    int testLikes[] = {7,1,8,-1,10,5,5,5,-1,8};
User u3 = User("roboticscu", testLikes, 10);

cout << u3.getUsername() << endl;
cout << u3.getNumPosts() << endl;
        
// test values in likes_array at random indices
cout << u3.getLikesAt(0) << endl;
cout << u3.getLikesAt(10) << endl;
cout << u3.getLikesAt(50) << endl;
// Expected Output 
// roboticscu
// 10
// 7
// -1
// -2 

int testLikes2[] = {-1,1,-1,8,8,3,-1,5,10,2,6,-1,6,7,8,4,1,7,1,8,-1,7,8,7,7,4,4,9,10,5,5,5,-1,8,-1,2,9,8,-1,-1,2,0,7,4,10,5,8,3,0,6};
User u2 = User("bookworm43", testLikes2, 50);

cout << u2.getUsername() << endl;
cout << u2.getNumPosts() << endl;
        
// test values in likes_array at random indices
cout << u2.getLikesAt(0) << endl;
cout << u2.getLikesAt(10) << endl;
cout << u2.getLikesAt(50) << endl;
// Expected Output 
// bookworm43
// 50
// -1
// 6
// -2 


}