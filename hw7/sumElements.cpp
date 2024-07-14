// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 7- Problem 1: Sum vector elements
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/**
 * Algorithm: sum of elements 
 * 1. Takes in a integer of vectors and checks for the validity 
 * 2. correct returns for the validity 
 * 3. adds the integers together   
 * Parameters: int vector, start and end int to see which part of vector to add  
 * Returns/ outputs: the sum or -1 or -2 depending on the bounds and correctness. 
 */

//make integer function for sum elements 
int sumElements(vector<int> v, int start_index, int end_index)
{

    //if the start index is more then the end index it is not possible 
    if(start_index>end_index)
    {
        return -1;
    }
    //make it so its in range otherwise return -2
    else if (start_index>v.size()||end_index>=v.size())
    {
        return -2;
    }

    else {

        //integer for the sum
         int sum = 0;

//for loop through the array starting at the start index ending at the end index
        for(int i = start_index; i <=end_index; i++)
    {

      //sum the integers together 
         sum+= v.at(i);
        
    }
//return the added values 
        return sum; 

    

    }

} 

int main()
{
    //test 1
vector<int> vect1{10, 20, 30, 40, 50};
int start_index = 1, end_index = 3;
cout << sumElements(vect1, start_index, end_index) << endl;
//expected output: 90

//test 2
vector<int> vect2{1, 2, 3, 4, 5, 6, 7, 8, 9};
int start_index2 = 5, end_index2 = 3;
cout << sumElements(vect2, start_index2, end_index2) << endl;
//expected output: -1

//test 3
vector<int> vect3{2, 4, 6, 8, 10, 12, 14, 16, 18};
int start_index3 = 3, end_index3 = 15;
cout << sumElements(vect3, start_index3, end_index3) << endl;
//expected output: -2

}