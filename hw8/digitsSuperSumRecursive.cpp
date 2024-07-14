// CSCI 1300 Fall 2022
// Author: NICOLE REN
// Recitation: 1300-304 – Nikhith Sannidhi
// Homework 8: digitsSuperSum Recursive 
#include <iostream> 
#include <ctime>
#include <cassert>
using namespace std; 
 
/**
 * Algorithm: digitsSuperSum Recursive
 * 1. Calls function to check itself over and over again until it meets requirements 
 * 2. first if checks if the number is one digit 
 * 3. returns number when its checked byitself to make sure it is one digit  
 * Parameters: integer
 * Returns/ outputs: the super sum integer 
 */

//name function 
int digitsSuperSumRecursive(int n)
{

//function will output if the integer is less then 10(one digit)
    if(n<10)
    {
        return n;
    }
    else 
    {
        //using the function to check itself 
        int sum1 = (n % 10 + digitsSuperSumRecursive(n / 10));
        //returns the function, function returns single digit(super sum)
        return digitsSuperSumRecursive(sum1);
    }

}

////////testing, other way to do it
//     else if (sum1> 10)
//     {
//         int sum2 = (n % 10 + digitsSuperSumRecursive(n / 10));
//          if(sum2<10)
//         {
//         return sum2;
//         }
//         if (sum2> 10)
//         {
//             int sum3 = (n % 10 + digitsSuperSumRecursive(n / 10));
//             if(sum3<10)
//             {
//             return sum3;
//             }
//             else if (sum3> 10)
//             {
//             int sum3 = (n % 10 + digitsSuperSumRecursive(n / 10));
//             }
//         }
//     }
// }
   

int main()
{
    // test 1 for digitsSuperSumRecursive
    assert(digitsSuperSumRecursive(4567) == 4);

    // test 2 for digitsSuperSumRecursive
    assert(digitsSuperSumRecursive(9) == 9);

    // test 3 for digitsSuperSumRecursive
    assert(digitsSuperSumRecursive(22) == 4);

    // test 4 for digitsSuperSumRecursive
    assert(digitsSuperSumRecursive(3002022) == 9);


}