#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
   string s;
   int i;
   //display a message to user to enter the string
   cout<<"Enter the String in lowercase: "; 
   //storing the string into the char array 
   getline(cin, s);

   for(i=0;i<=s.length();i++) { 

      if(s[i]>=97 && s[i]<=122)
      {
		s[i]=s[i]-32;
      }
   }
   cout<<"The entered string in uppercase: "<<s << endl;
   return 0;
}