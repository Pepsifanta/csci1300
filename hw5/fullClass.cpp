// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 5 - Problem 5
#include <iostream> 
#include <cassert>

using namespace std;

// Name: fullClass()
// Algorithm:Parameters (Your function should accept these parameters IN THIS ORDER):
// classroom bool: The two-dimensional array of 4 columns classroom seating.
// rows int: The number of rows in the array
// waitlist int: The current number of students on the waitlist

// Only put the function in the answer box.
// Header files: iostream, iomanip, cmath, cstdlib have been included
// If you put int main(){ ... }, it will say error: redefinition of 'int main()'

//make function for the classroom
int fullClass(bool classroom[][4], int rows, int waitlist)
{

for (int i = 0; i < rows; i++) 
{   // for each row
  for (int j = 0; j < 4; j++)
  { // for each column
    if ((classroom[i][j] == 0) && (waitlist !=0))
    {
      //everytime there is an open seat the waitlist goes down by one 
        waitlist= waitlist -1;
        //0 becomes 1 which means its full
        classroom[i][j]= 1;
    }
    cout << classroom[i][j];
  }
  cout << endl;
}
return waitlist; 
// cout<< "Remaining Students: "<< waitlist << endl;
}

//   for(int i= num_elements-1; i>=index+1; i--) 
//     {
//         //making i+1 = to the string in i to move it back one to make space
//        input_strings[i+1]= input_strings[i];
//     }
//     //the input strings index plus one is where string_to_insert will be inserted 
//     input_strings[index+1]=string_to_insert;
//     return true;

int main()
{

bool classroom[4][4] = {{0, 1, 1, 1},
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 1}};
int row= 4;
int waitlist =6;
assert(fullClass(classroom, row, waitlist)==0); 

bool classroom2[3][4] = {{0, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 0}};
int row2 = 3;
int waitlist2 =9;
assert(fullClass(classroom2, row2, waitlist2)==1); 

bool classroom3[1][4] = {{1, 1, 1, 1}};
int row3 = 1;
int waitlist3 =6;
assert(fullClass(classroom3, row3, waitlist3)==6); 

bool classroom4[2][4] = {{0, 1, 1, 1},
			                   {0, 0, 0, 0}};
int row4 = 3;
int waitlist4 =0;
assert(fullClass(classroom4, row4, waitlist4)==0); 
}