// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 6 - Problem 4b- Computing Score
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <iomanip>

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

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize)
{

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
while (getline(fin, line))
{

int x= split(line,'~', temp_arr,4);
////////
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
  if (i>=arrSize)
  {

    return i;
  }
//arrsize<i
temp_arr[0]="";
temp_arr[1]="";
temp_arr[2]="";
temp_arr[3]="";
}
return i;
}
/**
 * Algorithm: Calculated the overall score for the restaurants
 * 1. accepts all the variables 
 * 2. for loop to use readrestaurantsdata  
 * 3. calculates the scores using the formula
 * Parameters: restaurants (string), ratings (int), num_restaurants(int)
 * Returns: a void, over all score
 */
void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants)
{
  //make the nessesary variables for the function 
string filen;
int arr_s;
double score;
//for loop to go through the number of restaurants and then stop
for(int i = 0; i < num_restaurants; i++)
{
//use past function readrestaurant to find all the restaurants and their ratings
readRestaurantData(filen, restaurants, ratings, arr_s);
//make the int go through the formula below 
score = (6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 * (5 - ratings[i][2]));
//cout score to user
cout<<restaurants[i]<<" overall score: "<<fixed<<setprecision(1)<<score<<endl;
}

}

int main ()
{
 // test 1 for calcOverallScore
    // expected output: "Wendy's overall score: 60.9"
    calcOverallScore(Wendys~6~3~2, 1);

// test 2 for calcOverallScore
    // expected output: "Chick-fil-a overall score: 78.2"
    calcOverallScore(Chick-fil-a~9~5~5);

// test 3 for calcOverallScore
    // expected output: ""
    calcOverallScore(McDonalds~2~2~2~2);

// test 4 for calcOverallScore
    // expected output: "Snarfburger overall score: 87.0"
    calcOverallScore(Snarfburger~10~4~3);

}
