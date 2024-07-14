// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 7- findTagUser
#include <iostream>
#include "User.h"
#include "Post.h"
#include <fstream>

using namespace std;
//make function 
void findTagUser(string username_tag, User users[], int num_users_stored)
{
    // if there are no users output
    if (num_users_stored <= 0) {
        cout << "No users are stored in the database" << endl;
        return;
    }
//make variables 
    string matches[num_users_stored] = {};
    int nMatches = 0;
// for loop to get usernames 
    for (int i = 0; i < num_users_stored; i++) {
        User u = users[i];
        string name = u.getUsername();
        
        int foundWhere = name.find(username_tag);
        //finds the tag in the username FINDS WORD IN STRING 
        //reads till end of line then stops 
        if (foundWhere != string::npos) {
            matches[nMatches] = name;
            //counter goes up if matches 
            nMatches++;
        }
    }
//if there are no matches 
    if (nMatches == 0) 
    {
        cout << "No matching user found" << endl;
        return;
    }
    //if there are matches 
    else {
        cout << "Here are all the usernames that contain " << username_tag << endl;
        for (int i = 0; i<nMatches; i++) {
            cout << matches[i] << endl;
        }
    }
}

int main()
{
    // creating 5 users
    User user_array[5];
    int likes1[3] = {4, 5, 0};
    user_array[0] = User("foliwn22", likes1, 3);
    user_array[1] = User("joh23k", likes1, 3);
    user_array[2] = User("harry02", likes1, 3);
    user_array[3] = User("luwkml1", likes1, 3);
    user_array[4] = User("fwollow3", likes1, 3);
    findTagUser("ol", user_array, 5);

//should output:
//Here are all the usernames that contain ol
//foliwn22
//fwollow3

}