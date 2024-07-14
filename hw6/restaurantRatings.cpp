// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 6 - Problem 4a- Restaurants Ratings
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

/**
 * Algorithm: Reads restaurant and their ratings/scores 
 * 1. accepts filename, which goes through function
 * 2. goes through function and split function to find the ~ (separators) 
 * 3. find the three diffrent ratings and makes then ints to read
 * Parameters: filename (string), restaurants (string), ratings (int), arraysize (int)
 * Returns: a int, the restuarants and their ratings 
 */

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize)
{
//variables for the function
ifstream fin;
// int counter= 0;
string temp_arr[4]; 

fin.open(filename);
if (!fin.is_open())
{

    // cout<< "Could not open file."<<endl;
   
    return -1;
  
}

string line= "";
int i=0;
//while loop to read each line
while (getline(fin, line))
{
//split function to find the ratings 
int x= split(line,'~', temp_arr,4);
////////
//if the split is greater then 4 return -1
if (x>4)
{
  return -1;
}
if(x==4)
  {

restaurants[i]=temp_arr[0];
//gets the first rating of all the resturants 
ratings[i][0]=stoi(temp_arr[1]);
//gets the second rating of all the restuarants 
ratings[i][1]=stoi(temp_arr[2]);
//gets the third rating for all the restuarants 
ratings[i][2]=stoi(temp_arr[3]);
i++;

  }
  //have to set the boundaries 
  if (i>=arrSize)
  {

    return i;
  }
//arrsize<i
//reset all the tempparary arrays 
temp_arr[0]="";
temp_arr[1]="";
temp_arr[2]="";
temp_arr[3]="";
}
return i;
}

int main()
{
//int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize)
string restaurants[10];
int ratings[10][3]; 
int arrsize=10; 
cout<<readRestaurantData("restaurant_samples.txt", restaurants, ratings, arrsize )<<endl;
}