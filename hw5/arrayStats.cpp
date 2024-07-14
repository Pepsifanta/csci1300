// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 2
#include <iostream>
#include <cassert>
#include <iomanip> 

using namespace std;
// need thsi function for assert testing
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
//Algorithm: Checks imputs and finds the min in the array 
// 1.goes through array in loop
//2.find the one that is less then the otherones 
//3.returns minumun
//function for finding the minumin
double min(double arr[], int arr_size) 
{

//make variable for min val
   double min_val = 1000;
   // loop through the array 
   for(int i=0; i<arr_size; i++)
   {
    //if the array is less then the min val
      if(arr[i]<min_val) 
      {
        //min val will equal that array
         min_val= arr[i];
      }
   }
 //return the min
   return min_val;

}   
//Algorithm: Checks imputs and finds the sum of the array
//1.goes through array in loop
//2.adds every array together through a loop
//3.returns sum

//function for sum 
double sum(double arr[], int arr_size) 
{
//variable for the sum
double sum = 0;
//for loop through the array
  for (int i = 0; i < arr_size; i++) 
  {
    //add everything in the array together 
    sum += arr[i];
  }
  //return the sum
  return sum;

}
//Algorithm: Checks imputs and finds the average of the array
//1.goes through array in loop
//2.adds every array together through a loop
//3.returns sum and then divides the sum by the size
//4. return the quotient and that is the average

//function for the average of the array
double average(double arr[], int arr_size) 
{
double sum = 0;
    // Find sum of all array elements
    for(int i = 0; i < arr_size; i++) 
    {
        sum += arr[i];
    }
 //average is all the numbers added together divided by how many there are 
    double ave = sum/arr_size;

    return ave;
}



int main ()
{
double arr[] = {1.24, 5.68, 3.456};
int arr_size = 3;
assert(doublesEqual(min(arr, arr_size), 1.240));
assert(doublesEqual(sum(arr, arr_size), 10.376));
assert(doublesEqual(average(arr, arr_size), 3.459));

double arr1[] = {0};
int arr_size1 = 1;
assert(doublesEqual(min(arr1, arr_size1), 0.000));
assert(doublesEqual(sum(arr1, arr_size1), 0.000));
assert(doublesEqual(average(arr1, arr_size1), 0.000));

double arr2[] = {1.4, 9.8, 2.6};
int arr_size2 = 3;
assert(doublesEqual(min(arr2, arr_size2), 1.400));
assert(doublesEqual(sum(arr2, arr_size2), 13.800));
assert(doublesEqual(average(arr2, arr_size2), 4.600));

double arr3[] = {0,1,2,3,4,5,6,7,8,9};
int arr_size3 = 10;
assert(doublesEqual(min(arr3, arr_size3), 0.000));
assert(doublesEqual(sum(arr3, arr_size3), 45.000));
assert(doublesEqual(average(arr3, arr_size3), 4.500));
}