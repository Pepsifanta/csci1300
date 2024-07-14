#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace std;

int main() 
{
   int height;
   int width; 
   char alphabet = 'a';
    cout << "Enter the height:" << endl;
     cin >> height;
    
   if (height <= 0)  
      { 
        cout << "Invalid input." << endl;
    
    return 0;
      }

    for (int i =0; i<height; i++)
    {
        alphabet++;
        cout <<char(alphabet)<<endl;

        for (int j=0; i<((2*j)+1);j++ )
        {
     cout<< char (alphabet++)<<endl; 
        }
    }
    return 0;
}