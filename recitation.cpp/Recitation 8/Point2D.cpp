#include <iostream>
#include <cmath>
//pulling animal.h to put in file
#include "Point2D.h"

using namespace std;

Point2D::Point2D()
{
    x = 0;
    y = 0;
    label = "";
}

Point2D::Point2D(double p, double q, string l)
{
    x = p;
    y = q;
    label = l;
}

void Point2D::modify(Point2D point)
{
    point.setX(1000);
    point.setY(1000);
}
void Point2D::print()
{
    if (label.length() > 0)//print label if it exists
    {
        cout<<label<<":";
    }
    cout<< "("<<x<<","<<y<<")"<<endl;
}


double Point2D::getx() 
{
    return x;
}
double Point2D::gety() 
{
    return y;
}
string Point2D::getLabel()
{
    return label;
}

void Point2D::setX(double p)
{
    x=p;
}
void Point2D::setY(double q)
{
    y=q;
}
void Point2D::setLabel(string s)
{
    label=s;
}

double Point2D::distance(Point2D q)
{
    double first = pow(x - q.getx(), 2);
    double second = pow(y - q.gety(), 2);

    return sqrt(first + second);
}


