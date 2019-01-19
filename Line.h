#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line : public Shape
{
    public:
    Line(double *xCoord, double *yCoord, int pointCount);
    std::string getType();
    ObjectPosition position();
    Line& operator=(const Line& line);
    Line(const Line &line);
   
};

#endif // !LINE_H