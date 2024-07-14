#include <iostream>

using namespace std;

int main(){
  string name;
  //promt and ask the user for their name
  cout << "Please enter your name below:"<<endl;
  //use cin to store mystr, use << to take out
  //use getline to get entire line
  getline (cin, name);
  //print and output statement 
  cout << "Hello, " << name << "!\n";
}