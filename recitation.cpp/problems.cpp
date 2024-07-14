#include <iostream>

using namespace std;

int main()
{
for(int i = 0; i <= 4; i++) // outer loop
{
    for(int j = 0; j <= 4; j++) // inner loop
    {
        if(j%2 == 0)
        {
            cout << "$";
        }
        else
        {
            cout << "*";
        }
    }
    cout << endl;
}
}