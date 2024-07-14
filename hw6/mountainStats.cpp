// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 6 - Problem 2- Comparing Mountains
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;
//use previous function split string
int split(string input_string, char separator, string arr[], int arr_size)
{
  string temp_arr;
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
        temp_arr = temp_arr+ input_string [i];

    }
    
    //if the array is equal to the separator 
    if (input_string[i] == separator )
    {
      arr[count]=temp_arr;
      temp_arr= "";
      //count goes up
        count ++;
    }
  }
//if the amount of peices we split up is bigger and cant fit into the array retunr -1
  if (count>= arr_size)
  {
    return -1;
  }
  arr[count]=temp_arr; 
  return count+1;


}
/**
 * Algorithm: Finds the tallest mountain in a file
 * 1. accepts filename, which goes through function
 * 2. goes through loop to open file correctly and split function to find the int  
 * 3. calculates the scores by comparing the int
 * Parameters: filename (string)
 * Returns: a void, min, max
 */
//void function with no return value 
void printMountainStats(string filename)
{
//make variables for function 
ifstream fin; 
//file i need to open
//int best= 0;
int arr_s= 6;
//counter variable for how many lines there are for the output  
int counter= 0;
//min varibale 
int max= -2;
int min= 1000000;
string max_name;
string min_name;
string arr[2]; 
//open file and if cant open stop function
fin.open(filename);
if (!fin.is_open())
{
    cout<< "Could not open file."<<endl;
    return;
}
//if the line is empty skip it and continue reading things after it
string line;
while (getline(fin, line))
{
  if (line.empty())
  {
    continue;
  }
  //counter is how many lines there are 
  counter +=1;
    //best= 1;
      //make everything after | a int and read the max value 
       split(line, '|', arr, 4); 
       //changes string to array 
         int arr1= stoi(arr[1]);
//if statement to find the max mountain 
  if (arr1>max)
  {
    max= arr1;
    max_name =arr[0];
  }
  //if statement to find the minimum
  if (arr1<min)
  {
    min= arr1;
    min_name=arr[0] ;
  }
}
//cout to user
cout<<"Number of lines read: "<<counter<<"."<<endl;
cout<<"Tallest mountain: "<<max_name<< " at "<<max<<" feet."<<endl;
cout<<"Shortest Mountain: "<<min_name<<" at "<<min<<" feet."<<endl;

}

int main ()
{
// test 1 for printMountainStats
  // expected output: "Number of lines read: 3."
  //Tallest mountain: Pikes Peak at 14114 feet.
  //Shortest mountain: Vermilion Peak at 13894 feet."
    printMountainStats("mountain_data.txt");

// test 2 for printMountainStats
  // expected output: "Could not open file."
    printMountainStats("does-not-exist.txt");

// test 3 for calcOverallScore
    // expected output: "Number of lines read: 3."
    //Tallest mountain: Pikes Peak at 14114 feet.
    //Shortest mountain: Vermilion Peak at 13894 feet.
    calcOverallScore("mountatin_data1.txt");

}