#include <iostream>
#include <string>
#include "circle.h"
#include <math.h>

bool Circle::isIn(int x, int y) const 
{
    Point b;
    b.x_=x;
    b.y_=y;

    if(sqrt((b.x_-a.x_)*(b.x_-a.x_)+(b.y_-a.y_)*(b.y_-a.y_))<=r)
    {
        return true;
    }
    return false;
}