#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H
#include <iosfwd>
#include "shape.h"
#include <memory>

using namespace std;
using namespace Shapes;

namespace Shapes{

class ShapeComposite : public Shape
{

public:
    ShapeComposite(shared_ptr<Shape> a,shared_ptr<Shape> b,Shapes::ShapeOperation op):shape1{a},shape2{b},operation{op}{};

    bool isIn(int x, int y) const override;
    
private:
    shared_ptr<Shape> shape1;
    shared_ptr<Shape> shape2;
    Shapes::ShapeOperation operation;
};


}

#endif

/*
    - w oparciu o to bedzie mozna cala hierarchie figur polaczyc w jedno drzewo,
      dla ktorego bedzie mozna zapytac czy dany punkt jest w hierarchii, czy nie (metoda `isIn`).
*/