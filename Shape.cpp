#include "Shape.h"
#include "Polygon.h"
#include "Line.h"
#include "Triangle.h"
#include <string>
#include <cmath>
#include <iostream>


double Shape::area()
{
    int invalidArea = -1;
    return invalidArea;
}

double Shape::circumference()
{
    int invalidCircumference = -1;
    return invalidCircumference;
}

bool Shape::isConvex()
{
    return false;
}

double Shape::distance(Shape* s)
{
    //Our position
    ObjectPosition thisObject = position();
    //Their position
    ObjectPosition otherObject = s->position();

    double xDifference = pow(thisObject.x - otherObject.x, 2);
    double yDifference = pow(thisObject.y - otherObject.y, 2);
    double distance = sqrt(xDifference + yDifference);

    return distance;
}

Shape& Shape::operator+(const Shape &s)
{
    if(this == &s)
        return *this;

    int combinedVertices = this -> pointCount + s.pointCount;

    double *totalXCoords = new double[combinedVertices];
    double *totalYCoords = new double[combinedVertices];


    for(int i = 0; i < this -> pointCount; i++)
    {
        totalXCoords[i] = this -> xCoord[i];
        totalYCoords[i] = this -> yCoord[i];
    }


    for(int j = 0; j < s.pointCount; j++)
    {
        int index = this -> pointCount + j;
        totalXCoords[index] = s.xCoord[j];
        totalYCoords[index] = s.yCoord[j];
    }

    Shape* newShape = nullptr;

    if(combinedVertices > 3)
        newShape = new Polygon(totalXCoords, totalYCoords, combinedVertices);
    else if(combinedVertices == 3)
        newShape = new Triangle(totalXCoords, totalYCoords, combinedVertices);
    else 
        newShape = new Line(totalXCoords, totalYCoords, combinedVertices);

    return *newShape;
}

std::ostream &operator<<(std::ostream &streamobj, const Shape &s)
{
    streamobj << "Shape vertices:" << std::endl;

    for(int index = 0; index < (s.pointCount); index++)
    {
        streamobj << s.xCoord[index] << "," << s.yCoord[index] << std::endl;
    }
    return streamobj;
}

Shape::~Shape()
{
    delete [] xCoord;
    xCoord = nullptr;
    delete [] yCoord;
    yCoord = nullptr;
}
