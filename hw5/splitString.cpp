// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 4
#include <iostream> 
#include <string>
#include <iomanip>
#include <cassert>

using namespace std;

// input_string string: The text string containing data separated by a delimiter
// separator char: The delimiter marking the location where the string should be split up
// arr string array: The array that will be used to store the input text string's individual string pieces
// arr_size int: The number of elements that can be stored in the array
// Return Value: int: The number of pieces the input text string was split into

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


int main()
{

string input_string = "ABCDEFG";
char separator = ' ';
int arr_size = 3;
string arr[arr_size];
assert(split(input_string, separator, arr, arr_size)==1);

string input_string2 = "RST,UVW,XYZ";
char separator2 = ',';
int arr_size2 = 3;
string arr2[arr_size2];
assert(split(input_string2, separator2, arr2, arr_size2)==3);

string input_string3 = "Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest";
char separator3 = ',';
int arr_size3 = 5;
string arr3[arr_size3];
assert(split(input_string3, separator3, arr3, arr_size3)==-1);

string input_string4 = "ABCD EFG";
char separator4 = ' ';
int arr_size4 = 2;
string arr4[arr_size4];
assert(split(input_string4, separator4, arr4, arr_size4)==2);

}