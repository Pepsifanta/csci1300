#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;
// declaring a function

//check if number or string
bool check_input(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
int main() {
          string str1 = "12/2";
   if (check_input(str1))
      cout<<str1<< " is an integer";
   else
      cout<<str1<< " is a string";
}

