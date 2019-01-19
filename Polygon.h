#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"

class Polygon : public Shape
{
    public:
    Polygon(double *xCoord, double *yCoord, int pointCount);
    std::string getType();
    double area();
    double circumference();
    ObjectPosition position();
    bool isConvex();
    Polygon& operator=(const Polygon& polygon);
    Polygon& operator+(const ObjectPosition &position);
};

#endif // !POLYGON_H