// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 6 - Problem 3-  Reading Twitter Posts
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

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

/**
 * Algorithm: Reads the number of posts in a file
 * 1. accepts filename, which goes through function
 * 2. goes through function and split function to find the commas  
 * 3. adds a counter everytime it goes through everything so it reads a post 
 * Parameters: filename (string)
 * Returns: a int, how many posts (counter)
 */
int readPosts(string filename)
{
//make variables for function 
ifstream fin; 
//file i need to open
//int best= 0;
//int arr_s= 6;
//counter variable for how many lines there are for the output  
int counter= 0;
//min varibale 

string arr[3]; 

fin.open(filename);
if (!fin.is_open())
{
    // cout<< "Could not open file."<<endl;
    return -1;
}

string line= "";
//while loop to get to each line  
while (getline(fin, line))
{
  //split function to find all the posts and their components 
  split(line, ',', arr, 3);
  if (line.empty())
  {
    continue;
  }
  //this deals with missing fields and if the split is less then or greater then 3 ignore it bc its not a full comment 
  if((split(line, ',', arr, 3)>3)||(split(line, ',', arr, 3)<3))
  {
continue;
  }
  //if the split is 3 counter adds 1
  if(split(line, ',', arr, 3))
  {
      counter +=1;
  }

  //counter is how many lines there are 
    //best= 1;
    
       //split(line, '|', arr, 4); 

         //int arr1= stoi(arr[1]);
}
return counter;

}

int main()
{
assert(readPosts("posts.txt")==7);
}