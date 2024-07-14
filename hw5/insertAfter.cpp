// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 3a
#include <iostream> 
#include <cassert>

using namespace std;


// Parameters (Your function should accept these parameters IN THIS ORDER):
// input_strings string: The array containing strings
// num_elements int: The number of elements that are currently stored in the array
// arr_size int: The number of elements that can be stored in the array
// index int: The location to insert a new string. Note that the new string should be inserted after this location.
// string_to_insert string: The new string to be inserted into the array
bool insertAfter(string input_strings [], int num_elements, int arr_size, int index, string string_to_insert)
{
    //start as false
bool valid = false;
//if how many are in array rn is less then the size of how many can fit in the array
if ( num_elements < arr_size )
{
    //if the index is bigger or equal to the array size it will return false
    if(index>=arr_size)
    {
        return false;
    }
//if the user input index is bigger or equal how many is in the array
    if (index>=num_elements)
    { 
        //put the string to be inserted into the index area of the array
    input_strings[index]= string_to_insert;
    return true;
    }
    //this for is like an else becuase if the if doesn't happen the for loop will start
    //starts at last object in the array (num_elements-1)
    //i is less then index and goes backwards i--
    for(int i= num_elements-1; i>=index+1; i--) 
    {
        //making i+1 = to the string in i to move it back one to make space
       input_strings[i+1]= input_strings[i];
    }
    //the input strings index plus one is where string_to_insert will be inserted 
    input_strings[index+1]=string_to_insert;
    return true;
}
return false; 
}

int main()
{
    int arr_size= 5; 
    string input_strings [arr_size] = {"pikachu", "meowth", "snorlax"};
    int num_elements=3;
    int index=2; 
    string string_to_insert = "clefairy";
    assert(insertAfter(input_strings, num_elements, arr_size, index, string_to_insert) == 1); 

    int arr_size2= 5; 
    string input_strings2 [arr_size2] = {"caterpie", "eevee"};
    int num_elements2=2;
    int index2=0; 
    string string_to_insert2 = "bulbasaur";
    assert(insertAfter(input_strings2, num_elements2, arr_size2, index2, string_to_insert2) == 1); 

    int arr_size3= 2; 
    string input_strings3 [arr_size3] = {"pichu", "ponyta"};
    int num_elements3=2;
    int index3=1; 
    string string_to_insert3 = "charizard";
    assert(insertAfter(input_strings3, num_elements3, arr_size3, index3, string_to_insert3) == 0); 

    int arr_size4= 7; 
    string input_strings4 [arr_size4] = {"venusaur", "charizard", "tentacool", "oddish", "paras", "abra", "vileplume"};
    int num_elements4=7;
    int index4=7; 
    string string_to_insert4 = "caterpie";
    assert(insertAfter(input_strings4, num_elements4, arr_size4, index4, string_to_insert4) == 0); 





//////////////////////
//     //how many it can fit [0,1,2,3,4]
// int size = 5;
// //string input
// string input_strings[size] = {"pikachu", "meowth", "snorlax"};
// //how many are in the array rn
// int num_elements = 3;
// //start at index 2 [0, 1, 2] because theres 3
// int index = 2;
// string string_to_insert = "clefairy";
// // result contains the value returned by insertAfter
// bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
// // print result
// cout << "Function returned value: "<< result << endl;
// // print array contents
// for(int i = 0; i < size; i++)
// {
//     cout << input_strings[i] << endl;
// }
}