#include <iostream>
#include <string>
#include "rectangle.h"

bool Rectangle::isIn(int x, int y) const
{
    if(x>=this->from.x_ && x<=this->to.x_ && y>=this->from.y_ && y<=this->to.y_)
    {
        return true;
    }
    return false;
}