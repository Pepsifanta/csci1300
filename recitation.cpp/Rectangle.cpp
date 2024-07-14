#include "Rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Rectangle::Rectangle()
{
    width = 1;
    height = 1;

}

Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
}

int Rectangle::area()
{
    return width*height;
}