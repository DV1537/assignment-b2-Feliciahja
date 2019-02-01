#include "Functions.h"
#include "Shape.h"
#include <sstream>
#include <iostream>

//A function for reading in shapeCoords line by line and storing in array.

Shape* collectShapes(std::string line)
{
    double value = 0;
    int arraySize = 4;
    int numCoords = 0;
    double *shapeCoords = new double[arraySize];
    std::istringstream iss(line);

    while (iss >> value)
    {
        //Expand array if no space left
        if(numCoords == arraySize) 
        {
            double *tempArray = new double[arraySize * 2];
            for(int i = 0; i < arraySize; i++)
            {
                tempArray[i] = shapeCoords[i];
            }
            arraySize = arraySize * 2;
            delete [] shapeCoords;
            shapeCoords = tempArray; 
            tempArray = nullptr;
        }
        shapeCoords[numCoords] = value;
        numCoords++;
    }
    //The condition will evaluate to true if the attempted file operation failed and it was not the end of the file
    if (iss.fail() && !(iss.eof()))
    {
        std::cout << "The file contained invalid input.\nThe program will terminate." << std::endl;
        exit(EXIT_FAILURE);
    }

    if(numCoords == 0 || numCoords % 2 == 1)
    {
        std::cout << "That is not a shape.." << std::endl;
        exit(EXIT_FAILURE);
    }    

    double *xCoord = new double[numCoords/2];
    double *yCoord = new double[numCoords/2];

//Storing the x and y coords in seperate arrays
    for(int count = 0; count < numCoords; count++) 
    {
        int coordIndex = (count / 2);
        if(count % 2 == 0)
            xCoord[coordIndex] = shapeCoords[count];
        else
            yCoord[coordIndex] = shapeCoords[count];
    }
    delete [] shapeCoords;
    shapeCoords = nullptr;

    Shape *shape = getShape(numCoords, xCoord, yCoord);

    return shape;
}

//Determining the shape by comparing the number of coords read in from file
Shape* getShape(int numCoords, double *xCoord, double *yCoord)
{
    Shape* s;
    int vertices = (numCoords / 2);

    if(numCoords > 6)
    {
        s = new Polygon(xCoord, yCoord, vertices);
        
    }
    else if(numCoords == 6)
    {
        s = new Triangle(xCoord, yCoord, vertices);

    }
    else if(numCoords == 4)
    {
        s = new Line(xCoord, yCoord, vertices);

    }
    else if(numCoords == 2) 
    {
        s = new Point(xCoord, yCoord, vertices);
    }
    return s;
}

void swap(double* a, double* b) 
{ 
    double t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(double arr[], int low, int high) 
{ 
    double pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void quickSort(double arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 