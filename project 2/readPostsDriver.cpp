// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Project 2 part 1 - Problem 2 - readPosts
#include <iostream>
#include "Post.h"
#include <fstream>

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

int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size)

{

ifstream fin; 


fin.open(file_name);
if (num_posts_stored == posts_arr_size)
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
 
  string arr[posts_arr_size]; 
  int n = split(line, ',', arr, 4);
  if (line.empty())
  {
    continue;
  }


  if((n>4)||(n<4))
  {
continue;
  }

  

    Post p;
    p.setPostBody(arr[0]);
    p.setPostAuthor(arr[1]);
    p.setPostLikes(stoi(arr[2]));
    p.setPostDate(arr[3]);

    posts[num_posts_stored]=p;

      num_posts_stored +=1;
 if (num_posts_stored == posts_arr_size)
  {
    return num_posts_stored;
  }

  
}
return num_posts_stored;

}

int main()
{
// return -2 if the arr is already full

Post posts[0] = Post("new post","user1", 10, "10/02/22");
Post posts[1] = Post("Hello!","user2", 9, "10/04/22");
Post posts[2] = Post("Hey!","user3", 9, "10/04/22");

int num_posts_stored = 3;

num_posts_stored = readPosts("posts_20.txt", posts, num_posts_stored, 3);
cout << "Function returned value: " << num_posts_stored << endl;

}

