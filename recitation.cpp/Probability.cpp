#include <iostream> 
#include <ctime>
using namespace std; 

void computeProbability(double sideLength)
{
    double max_r = sideLength / 2.0;

    double radius = (float(rand())/float(RAND_MAX)) * max_r;

    double square_area = sideLength * sideLength; 
    double circle_area = 3.14 * radius * radius;

    double prob = circle_area / square_area; 

    cout<<"The probability of the dart hitting the circle is:"<< prob<<endl; 

}

int main()
{

double sideLength;

cout<< "Enter the side length (a positive integer) for the square."<<endl; 
cin>>sideLength;

srand((unsigned int)time(0));

if(sideLength<=0)
{
    cout<<"Invalid input."<<endl;
}
else
{
    computeProbability(sideLength);
}
return 0;

}