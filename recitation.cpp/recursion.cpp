#include <iostream> 
#include <ctime>
using namespace std; 

string reverse(string text)
{
    int size = text.size();
    if (size == 1)
    {
        return text;
    }
    else 
    {
        return reverse(text.substr(1)) + text[0];
    }
}


int main ()
{
    string text;
    cout<<"Enter input string"<<endl;
    cin>> text;
    string reversed = reverse(text);
    cout<< reversed <<endl; 
}