// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 1
#include <iostream>
#include <cassert>

using namespace std;

int main ()
{
//make new variable for the array 
int num5 [10] = { 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
//for loop that goes through the array and prints everything inside it
for (int i = 0; i < 10; i++)
{
   //output to user
   cout << num5[i] << endl;
}
//string variable for city array
string city [5] = { "Boulder", "NYC", "LA", "Chicago", "Houston" };
//loop through array to print each part
for (int i = 0; i < 5; i++)
{
   //output the cities in array 
   cout << city[i] << endl;
}
   
// int array for the first 100 numbers dividable by 6
int int6 [100]={};
//loop through the array
for (int i=0; i < 100; i++)
{
   //everything in the array is just 1 up and multiplying every number up to 100 by 6
   int6[i] = (i+1) * 6;
   //output the numbers 
   cout<< int6[i]<< endl;
}
//string variavle array for the alphabet 
//52 letters uppercase and lowercase
string alpha [52] = {};
//loop through
for (int i = 0; i < 52; i++)
{
   //if the numbers are even 
   if(i%2== 0)
   {
     //output the lowercase letters
   alpha[i]=char(i/2+65); 
   }
   else
   {
      //output the uppercase letters 
   //goes up too much bc of last loop so divide by 2 but can't divide odd number so add 1 to be even
   alpha[i]=char((i+1)/2+96);
   }
   //print out
   cout<< alpha[i]<<endl;
}


}