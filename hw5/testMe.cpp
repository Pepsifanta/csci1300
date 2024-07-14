// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 6

#include <iostream> 
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;
//Algorithm: goes through array and makes all 0 into 5
//1.goes through array in loop
//2.change every 0 it finds to 5
//3.returns how many they changed
int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    			arr[i] = 5;
			count++;
		}
	}
	return count;
}
int main()
{
// make vaiables for what the function needs to run
    int arr []= {1, 2, 3, 0, 5, 0};
    int arr_s = 6;
	//run through function and repeat 10 times
    assert(zeroesToFives(arr, arr_s) == 2);
   //////
    int arr1 []= {};
    int arr_s1 = 7;
    assert(zeroesToFives(arr1, arr_s1) == 5);

    int arr2 []= {2, 2, 2, 2, 2, 2};
    int arr_s2 = 6;
    assert(zeroesToFives(arr2, arr_s2) == 0);
    return 0;

	int arr3 []= {2, 2, 2, 0, 2, 0, 2, 2};
    int arr_s3 = 2;
    assert(zeroesToFives(arr3, arr_s3) == 2); 

	int arr4 []= {2, 2};
    int arr_s4 = 100;
    assert(zeroesToFives(arr4, arr_s4) == 0);

	int arr5 []= {0,0,0,0,0,0,0,0,0,0,0,0,0};
    int arr_s5 = 2;
    assert(zeroesToFives(arr5, arr_s5) == 10); 
	
	int arr6 []= {0,0};
    int arr_s6 = 0;
    assert(zeroesToFives(arr6, arr_s6) == 10); 

	int arr7 []= {5,5,5,5,5,5,5,5,5};
    int arr_s7 = 0;
    assert(zeroesToFives(arr7, arr_s7) == 10); 

	int arr8 []= {1,2,3,4,5,6,7,8,9,0};
    int arr_s8 = 0;
    assert(zeroesToFives(arr8, arr_s8) == 1); 

	int arr9 []= {5};
    int arr_s9 = 0;
    assert(zeroesToFives(arr9, arr_s9) == 10); 

	int arr10 []= {5,0,0,0,0,0,0,0,0};
    int arr_s10 = 9;
    assert(zeroesToFives(arr10, arr_s10) == 8); 
}

