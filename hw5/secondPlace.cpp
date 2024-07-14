// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 3b
#include <iostream> 
#include <cassert>

using namespace std;

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

// input_strings string: The array containing strings
// string_to_insert string: the string to insert
// string_to_find string: the string to find (target string)
// num_elements int: The number of elements that are currently stored in the array
// arr_size int: The number of elements that can be stored in the array
// count int: The number of the target strings present in the array
int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count)
{
    //if # of ele stored in array plus # of target strings present and is less then the size of array
if (num_elements+count> arr_size)
{
    //return num_ele
    return num_elements;
}
// for loop through array otherwise
    for(int i = 0; i < num_elements; i++)
    {
        //if a part of the input array is the pokemon we are trying to find
        if(input_strings[i] == string_to_find)
        {
            //use previous function to insert 
            insertAfter(input_strings, num_elements, arr_size, i, string_to_insert);
            num_elements ++; 
        }
    }
    //return how much is in the array after function 
return num_elements;
}

int main ()
{

    int size= 5;
    int count= 1; 
    string input_strings [size] = {"clefairy", "meowth", "snorlax"};
    int num_elements=3;
    string string_to_insert = "charizard";
    string string_to_find = "meowth";
    assert(secondPlace(input_strings, string_to_insert, string_to_find, num_elements, size, count) == 4); 

    int size2= 18;
    int count2= 3; 
    string input_strings2 [size2] = {"clefairy", "meowth", "snorlax", "pikachu", "clefairy", "pichu", "eevee", "clefairy", "raichu", "ponyta"};
    int num_elements2=10;
    string string_to_insert2 = "pichu";
    string string_to_find2 = "clefairy";
    assert(secondPlace(input_strings2, string_to_insert2, string_to_find2, num_elements2, size2, count2) == 13); 

    int size3= 10;
    int count3= 2; 
    string input_strings3 [10] = {"clefairy", "meowth", "pichu", "meowth", "charizard", "raichu", "ponyta"};
    int num_elements3=7;
    string string_to_insert3 = "pikachu";
    string string_to_find3 = "meowth";
    assert(secondPlace(input_strings3, string_to_insert3, string_to_find3, num_elements3, size3, count3) == 9); 

    int size4= 5;
    int count4= 3; 
    string input_strings4 [10] = {"caterpie", "meowth", "pichu", "caterpie", "caterpie"};
    int num_elements4=5;
    string string_to_insert4 = "gyarados";
    string string_to_find4 = "caterpie";
    assert(secondPlace(input_strings4, string_to_insert4, string_to_find4, num_elements4, size4, count4) == 5); 

//     //how many it can fit [0,1,2,3,4]
// int size = 5;
// //string input
// string input_strings[size] = {"clefairy", "meowth", "snorlax"};
// //how many are in the array rn
// int num_elements = 3;
// //The number of the target strings present in the array
// int count = 1;
// string string_to_insert = "charizard";
// string string_to_find = "meowth";
// // updating num_elements with the updated value returned by secondPlace
// num_elements = secondPlace(input_strings, string_to_insert, string_to_find, num_elements, size, count);
// // print num_elements
// cout << "Function returned value: " << num_elements << endl;
// // print array contents
// for(int i = 0; i < size; i++)
// {
//     cout << input_strings[i] << endl;
// }
}