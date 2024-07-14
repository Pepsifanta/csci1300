#include <iostream>
#include <string>
using namespace std;
int main()
{
   string some_string1 = "his";
   string some_string2 = "cycle";
   if (some_string1 < some_string2)
   {
      cout << some_string2;
   }
   else
   {
      cout << some_string1;
   }
   return 0;
}