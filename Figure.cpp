#include "Figure.h"
#include <iostream>
#include <sstream>

Figure::Figure()
{
    figure = nullptr;
    numShapes = 0;
}
    
Figure::Figure(Shape** shapes, int numShapes)
{
    this -> figure = new Shape*[numShapes];
    
    for(int i = 0; i < numShapes; i++)
    {
        figure[i] = shapes[i];
    }
    this -> numShapes = numShapes;
}

void Figure::addShape(Shape *s)
{
    numShapes += 1;

    Shape **temparray = new Shape*[numShapes];

    for(int i = 0; i < (numShapes - 1); i++)
    {
        temparray[i] = figure[i];
    }
    temparray[numShapes - 1] = s;
    delete [] figure;
    figure = temparray;
}

Line Figure::getBoundingBox()
{
    double topLeftX = 0, topLeftY = 0, bottomRightX = 0, bottomRightY = 0;

    for(int i = 0; i < numShapes; i++)
    {
        double *tempX = figure[i] -> getxCoords();
        double *tempY = figure[i] -> getyCoords();
        int amountOfCoords = figure[i] -> getAmountOfCoords();

        if(i == 0)
        {
            topLeftX = tempX[0];
            topLeftY = tempY[0];
            bottomRightX = tempX[0];
            bottomRightY = tempY[0];
        }

        for(int j = 0; j < amountOfCoords; j++)
        {
            if(tempX[j] < topLeftX)
            {
                topLeftX = tempX[j];
            }
            else if(tempX[j] > bottomRightX)
            {
                bottomRightX = tempX[j];
            }
            if(tempY[j] > topLeftY)
            {
                topLeftY = tempY[j];
            }
            else if(tempY[j] < bottomRightY)
            {
                bottomRightY = tempY[j];
            }
        }
    }
    double xCoord[2];
    double yCoord[2];
    xCoord[0] = topLeftX; 
    xCoord[1] = bottomRightX;
    yCoord[0] = topLeftY;
    yCoord[1] = bottomRightY;
    
    Line line(xCoord, yCoord, 2);

    return line;
}

Figure::~Figure()
{
    for(int i = 0; i < numShapes; i++)
    {
        if(figure[i])
        {
            figure[i] = nullptr;
        }

        delete [] figure;
    }
}