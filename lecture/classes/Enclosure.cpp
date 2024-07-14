#include <iostream>
#include "Enclosure.h"

using namespace std;

Enclosure::Enclosure();
{
    length = 10;
    width = =10;
    square_feet = length * width;
}
Enclosure::Enclosure(double new_length, double new_width, animal new_occupant);
{
    if(length >=0)
    {
    length = new_length;
  
    }
    else
    {
     length = 10;
    }
    if(width>=0)
    {
         width = new_width;
    }
    else 
    {
        width = 10;
    }
    square_feet = length * width;

    occupant = new_occupant; 
}

double Enclosure::getLength();
{
    return length;
}
void Enclosure::setLength(double desired_length);
{
    if(desired_length>=0)
    {
length = desired_length
square_feet= length*width;
    }
}

double Enclosure::getWidth();
{
    return width;
}
void Enclosure::setWidth(double desired_width);

{
    if(desired_width>=0)
    {
        width = desired_width
        square_feet = length*width
    }
}
double Enclosure::getSquareFeet();
{
    return square_feet
}

animal Enclosure::getOccupant();
{
    return occupant;
}
void Enclosure::setOccupant(animal new_occupant);
{
    occupant= new_occupant;
}

void Enclosure::describeEnclosure();
{
    cout<<"This enclosure is"<<square_feet<<" sq. ft."<<endl;
    cout<<"this enclosure houses a"<<occupant.getSpecies()<<endl;
}