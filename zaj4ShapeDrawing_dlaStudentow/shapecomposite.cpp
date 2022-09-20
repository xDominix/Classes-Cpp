#include <iostream>
#include <string>
#include "shapecomposite.h"
using namespace std;

bool ShapeComposite::isIn(int x, int y) const
{   
    switch (operation)
    {
    case Shapes::ShapeOperation::INTERSECTION:
        if(shape1->isIn(x,y) && shape2->isIn(x,y)) return true;
        break;
    case Shapes::ShapeOperation::SUM:
        if(shape1->isIn(x,y) || shape2->isIn(x,y)) return true;
        break;
    case Shapes::ShapeOperation::DIFFERENCE:
        if(shape1->isIn(x,y) && !shape2->isIn(x,y)) return true;
        if(!shape1->isIn(x,y) && shape2->isIn(x,y)) return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}