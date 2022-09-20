#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iosfwd>
#include "shape.h"
using namespace std;
using namespace Shapes;

namespace Shapes{

class Rectangle : public Shape
{
public:
    Rectangle(int xFrom,int yFrom,int xTo,int yTo):from{xFrom,yFrom},to{xTo,yTo}{};
    
    bool isIn(int x, int y) const override;

    int x() const {return from.x_;};
    int y() const {return from.y_;};
    int xTo() const {return to.x_;};
    int yTo() const {return to.y_;};

private:
    Point from;
    Point to;
};


}
#endif //RECTANGLE_H