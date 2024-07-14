#include <iostream>
using namespace std;

int main(){

  double Tc, Th, n;  

  cout<<"Enter cold reservir temparature (in F)" << endl;
  cin >> Tc;

cout<<"Enter cold reservir temparature (in F)" << endl;
cin >> Th;

Tc = (Tc-32)*5.0/9.0 + 273.15;
Th = (Tc-32)*5.0/9.0 + 273.15;
n = 1 - (Tc/Th);
cout<<"carnot efficiency: "<<n<<endl;


    return 0;
}