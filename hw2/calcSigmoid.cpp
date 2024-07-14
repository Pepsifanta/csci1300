//add libraries
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    // enter e value in variable 
    double e = 2.718281828459045;
    //prompt user for x value
double x;
cout << "Enter a value for x:"<<endl;
// put user input into variable 
cin>> x;
// do the math for the variable, which is one divided by e to the power of negative x
double sigmoid = 1/(1+pow(e,-x));
// print the needed response and add the user input x and sigmoid value in sentence
 cout << "The sigmoid for x=" << x << " is "<<sigmoid<<endl;
  
}