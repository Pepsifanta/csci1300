#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
int num = 0;
cout << "Enter number: ";
cin >> num;
if (num < 50) 
{
   num = num + 5; 
}
if (num < 10) 
    {
   num = num - 2; 
}
if (num > 5) 
{ 
   num++; 
}
else 
{ 
   num--; 
}
cout << num << endl;
    }