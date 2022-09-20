#ifndef CIRCLE_H
#define CIRCLE_H
#include <iosfwd>
#include "shape.h"
using namespace std;
using namespace Shapes;

namespace Shapes{

class Circle : public Shape
{
public:
    Circle(int xCenter,int yCenter,int radius):a{xCenter,yCenter},r(radius){};

    bool isIn(int x, int y) const override;

    int x() const {return a.x_;};
    int y()const {return a.y_;};
    int getRadius() const {return r;};

private:
    Point a;
    int r;
};


}

#endif