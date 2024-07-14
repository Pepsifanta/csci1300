#include <iostream>
#include <cmath>
#include <cassert>
#include <assert.h>


using namespace std;

void swap(int myArray[], int startIndex, int endIndex)
{
int temp= myArray[startIndex];
myArray[startIndex]=myArray[endIndex];
myArray[endIndex]= temp;
}


void reverseArray(int myArr[], int length)
{
    int start= 0;
    int end = length - 1;

    while (start < end)
    {
        swap(myArr, start, end);
        start++;
        end--; 

    }
}

int main()
{
    int test [5]= { 10 , 20 , 30 , 40 , 50 };
    int answer_test[5]= { 50 , 40 , 30 , 20 , 10 };
    reverseArray(test,5);
    for (int i=0;i< 5; i++)
    {
        cout<<test[i]<< "";
        assert(test[i]==answer_test[i]);
    }
    cout<<endl;
    return 0;
}