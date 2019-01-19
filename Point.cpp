#include "Point.h"
#include <iostream>
#include <string>


Point::Point(double *xCoord, double *yCoord, int pointCount)
{
    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
    this -> pointCount = pointCount;
}

std::string Point::getType()
{
    std::string type = "Point";
    return type;
}

ObjectPosition Point::position()
{
    ObjectPosition position;
    position.x = xCoord[0];
    position.y = yCoord[0];

    return position;
}

Point& Point::operator=(const Point& point)
{
    if(this == &point) 
	{	
        return *this;
	}
	
	if(pointCount > 0)
    {
        delete [] xCoord;
        delete [] yCoord;
    }
    xCoord = new double[pointCount];
    yCoord = new double[pointCount];
    
    for(int index = 0; index < pointCount; index++)
    {
        xCoord[index] = point.xCoord[index];
        yCoord[index] = point.yCoord[index];
    }
    return *this;
}
