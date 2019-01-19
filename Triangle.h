#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    public: 
    Triangle(double *xCoord, double *yCoord, int pointCount);
    std::string getType();
    double area();
    double circumference();
    ObjectPosition position();
    bool isConvex();
    Triangle& operator=(const Triangle& triangle);
};

#endif // !TRIANGLE_H