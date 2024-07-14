//add the needed libraries for code to run
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    // prompt user for variable of how many days in the future they want to predict
int days;
cout << "How many days in the future would you like a prediction for?"<<endl;
//save user input into variable days
cin>> days;
//add inches at each resort currently into variables
int brek = 25;
int vail = 28;
int copper = 40;
//math for how many inches after how many days 
//for snow fall multiply days into future by how many inches of snow fall per day
int bfall = days*10;
//for melt multiply days into future by how many inches of snow melts per day
int bmelt = days*5;
//to predict add how much is already at resort by amount of snow fall inches subtracted by snow melt inches
int binch = brek + (bfall-bmelt);
//repeat for two other resorts
int vfall = days*14;
int vmelt = days*2;
int vinch = vail + (vfall-vmelt);
int cfall = days*5;
int cmelt = days*3;
int cinch = copper + (cfall-cmelt);
//write sentence output and inches in the future for each of the resorts 
 cout << "Breckenridge will have " <<fixed<<setprecision(1)<< binch << " inches, Vail will have "<<fixed<<setprecision(1)<< vinch <<" inches, and Copper Mountain will have " <<fixed<<setprecision(1)<<cinch<< " inches." <<endl;

}