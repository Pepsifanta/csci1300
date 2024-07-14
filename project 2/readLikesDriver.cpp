// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 1 - Problem 5
#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include "Post.h"
#include "User.h"

using namespace std;
 
int split(string input_string, char separator, string arr[], int arr_size)
{
  //counter that starts at 0
    int count =0;
    //new variable for input_string length
    int length= input_string.length();
// if the length is equal to zero it will return 0
    if (length==0)
    {
        return 0;
    }
    int num_sep=0;
for (int i = 0; i < input_string.length(); i++)
{
  if(input_string[i]==separator)
  {
  num_sep++;
  }
}
if (num_sep>=arr_size)
{
  return -1;
}
// for loop to go through the input_string
  for(int i=0; i < length; i++)
  {
    // if else statement that if part of the input string is not equal to the separator
    if (input_string[i] != separator )
    {
      //the part of the array becomes the array plus the inputstring that does not equal the separator
        arr[count] = arr[count]+ input_string [i];

    }
    //if the array is equal to the separator 
    if (input_string[i] == separator )
    {
      //count goes up
        count ++;
    }
  }
//if the amount of peices we split up is bigger and cant fit into the array retunr -1
  if (count>= arr_size)
  {
    
    return -1;
  }
  return count+1;


}


int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)


{
User temp;

ifstream fin; 


fin.open(file_name);
if (num_users_stored == users_arr_size)
  {
    return -2;
  }
else if (!fin.is_open())
{
   
    return -1;
}

string line= "";
 
while (getline(fin, line))
{
 
  string arr[51]; 
  int n = split(line, ',', arr, max_posts+1);
  users[num_users_stored].setNumPosts(max_posts+1);
  if (line.empty())
  {
    continue;
  }
    if(n>max_posts+1)
  {
    continue;
  }

    users[num_users_stored].setUsername(arr[0]);
     users[num_users_stored].setNumPosts(max_posts);

    //for (int i = 1; i<max_posts+1; i++)
    for (int i = 1; i<n; i++)
    {
       int likes= stoi(arr[i]); 
     users[num_users_stored].setLikesAt(i-1, likes);
    }

    //users[num_users_stored] = temp;
    num_users_stored +=1;
 if (num_users_stored == users_arr_size)
  {
    return num_users_stored;
  }
        
  
}
return num_users_stored;

}


int main()
{
    User users[3]; 
    int likes1[3] = {1, 3, 0};
    User u1 = User("Cola", likes1, 3);
    users[0] = u1; // insert first object at index 0
    int num_users_stored = 1;
    int users_arr_size = 3;
    int max_posts = 3;
    cout<<readLikes("users_test2.txt", users,num_users_stored, users_arr_size, max_posts)<<endl;;
//expected output 
//3

// check if we can call the function
User users2[10];

int max_posts2 = 50;
int num_users_stored2= 0;
int users_arr_size2 = 10;

readLikes("users.txt", users2, num_users_stored2, users_arr_size2, max_posts2);
cout << "checking if we can call the function" << endl;

//expected output 
//checking if we can call the function

// Reading unknown file
User users3[10];

int max_posts3 = 50;
int num_users_stored3 = 0;
int users_arr_size3 = 10;

cout << readLikes("file_not_found.txt", users3, num_users_stored3, users_arr_size3, max_posts3) << endl;
//expected output 
//-1

}