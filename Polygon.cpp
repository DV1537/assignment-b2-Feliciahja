#include "Polygon.h"
#include <iostream>
#include <string>
#include <cmath>


Polygon::Polygon(double *xCoord, double *yCoord, int pointCount)
{
    this -> xCoord = new double[pointCount];
    this -> yCoord = new double[pointCount];
    
    for(int i = 0; i < pointCount; i++)
    {
        this -> xCoord[i] = xCoord[i];
        this -> yCoord[i] = yCoord[i];
    }
    this -> pointCount = pointCount;
}

std::string Polygon::getType()
{
    std::string type = "Polygon";
    return type;
}

double Polygon::area()
{
    double area = 0.0; //Accumulates the area
    
    if(isConvex() == true)
    {
        int j = pointCount - 1;  //The last coordinates are the former one to the first coordinates

        for (int i = 0; i < pointCount; i++)
        { 
            area += (xCoord[j] + xCoord[i]) * (yCoord[j] - yCoord[i]); 
            j = i;  
        }
        area = std::abs(area / 2.0);
    }
    else 
        area = -1.0;
   
    return area;
}

double Polygon::circumference()
{
    double circumference = 0.0; //Accumulates all the sides of the polygon 
    double distanceInX;
    double distanceInY;
    double distance;

    for(int i = 0; i < (pointCount - 1); i++)
    {
        distanceInX = pow(xCoord[i] - xCoord[i + 1], 2);
        distanceInY = pow(yCoord[i] - yCoord[i + 1], 2);
        distance = sqrt(distanceInX + distanceInY);
        circumference += distance;
    }    
    return circumference;
}

ObjectPosition Polygon::position()
{
    //Accumulates all the center coordinates of three preceeding points of the polygon
    double totalCenterX = 0.0; 
    double totalCenterY = 0.0;
    int counter = 0;

    for(int i = 0; i < (pointCount - 2); i++)
    {    
        totalCenterX += (xCoord[i] + xCoord[i+1] + xCoord[i+2]) / 3;
        totalCenterY += (yCoord[i] + yCoord[i+1] + yCoord[i+2]) / 3;
        counter++;
    }
    ObjectPosition position;
    position.x = (totalCenterX / counter);
    position.y = (totalCenterY / counter);

    return position;
}   

bool Polygon::isConvex()
{
    int size = (pointCount - 2);
    double *crossproduct = new double[size];
    double difInx1, difIny1, difInx2, difIny2;

    //Collecting the crossproducts to see if they are either all positive or all negative
    for(int i = 0; i < size; i++)
    {
        difInx1 = xCoord[i+1] - xCoord[i];
        difIny1 = yCoord[i+1] - yCoord[i];
        difInx2 = xCoord[i+2] - xCoord[i+1];
        difIny2 = yCoord[i+2] - yCoord[i+1];
        crossproduct[i] = (difInx1 * difIny2 - difIny1 * difInx2);
    }

    bool postiveFound = false;
    bool negativeFound = false;

    //For convex polygon all cross products must have the same sign, + or -.
    for(int i = 0; i < size; i++)
    {
        if(crossproduct[i] > 0)
            postiveFound = true;
        else
            negativeFound = true;
    }

    delete [] crossproduct;
    crossproduct = nullptr;

    if(postiveFound && negativeFound)
        return false;
    else 
        return true;

}

Polygon& Polygon::operator=(const Polygon &polygon)
{
    if(this == &polygon) 
	{	
        return *this;
	}
    if(pointCount > 0)
    {
        delete [] xCoord;
        delete [] yCoord;
    }
    pointCount = polygon.pointCount;
    xCoord = new double[pointCount];
    yCoord = new double[pointCount];

    for(int index = 0; index < pointCount; index++)
    {
        xCoord[index] = polygon.xCoord[index];
        yCoord[index] = polygon.yCoord[index];
    }
    return *this;
}

Polygon& Polygon::operator+(const ObjectPosition &position)
{
    pointCount += 1;
    
    double *tempX = new double[pointCount];
    
    for(int i = 0; i < (pointCount - 1); i++)
    {
        tempX[i] = xCoord[i];
    }
    tempX[pointCount - 1] = position.x;
    delete [] xCoord;
    xCoord = tempX; 
    tempX = nullptr;

    double *tempY = new double[pointCount];
    
    for(int i = 0; i < (pointCount - 1); i++)
    {
        tempY[i] = yCoord[i];
    }
    tempY[pointCount - 1] = position.y;
    delete [] yCoord;
    yCoord = tempY; 
    tempY = nullptr;

    return *this;
}








