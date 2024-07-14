#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    //save variables into double to have decimal answers 
  double side;
  // add prompt to user for side length in inches
   cout << "What is the side length of the base of the carton in inches?"<<endl;
   //save user input
    cin>> side;
  double height;
  //prompt to user for height in inches
   cout << "What is the height of the carton in inches?"<<endl;
   //save user input to variable
  cin>> height;
  //step one of math, find the area of base
double side2 = side*side;
// find volume with base and height
double area = side2*height;
//find amount of ounces it can hold
double ounce = area*0.55;
// setprecision makes the answer round correctly (manipulators)
// fixed manipulates it to be fixed points
 cout << "The carton has a volume of " <<fixed<<setprecision(1)<< ounce << " ounces.";
  
}
