#include <iostream>
#include "swimmingPool.h"
using namespace std;
//Declaration of Class


int main()
{
double l,b,h,r,result;
cout << "Length of pool" <<endl;
cin>>l;
cout << "Width of pool" <<endl;
cin>>b;
cout << "Height of pool" <<endl;
cin>>h;
cout <<"Rate at which water is filling the pool" <<endl;
cin>>r;




swimmingPool pool(l,b,h,r);
result=pool.calculateAmount();
cout<<"Amount of water needed to fill the tank is: "<<result<<" gallons";





return 0;
}
