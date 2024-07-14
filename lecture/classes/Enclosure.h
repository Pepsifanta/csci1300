#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include<iostream>
#include "animal.h"
using namespace std;

class Enclosure
{
private:
    double length;
    double width;
    double square_feet;
    animal occupant;

public:
    Enclosure();
    Enclosure(double new_length, double new_width, animal new_occupant);

    double getLength();
    void setLength(double desired_length);

    double getWidth();
    void setWidth(double desired_width);
//new let user update square feet on their own
//dont make setting for square feet 
    double getSquareFeet();

    animal getOccupant();
    void setOccupant(animal new_occupant);

    void describeEnclosure();


};




#endif