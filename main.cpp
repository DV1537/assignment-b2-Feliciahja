#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Functions.h"
#include "Figure.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>


int main(int argc, const char * argv[])
{
    int arraySize = 4;
    Shape** shapes = new Shape*[arraySize];
    int numShapes = 0;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    //Testing for file open errors before processing it
    if(myReadFile)
    {
        std::string line;
        std::getline(myReadFile, line);

        while(!(line.empty()))
        {
            if(numShapes == arraySize)
            {
                Shape** tempArray = new Shape*[arraySize * 2];
                for(int i = 0; i < arraySize; i++)
                {
                    tempArray[i] = shapes[i];
                }
                arraySize = arraySize * 2;
                delete [] shapes;
                shapes = tempArray; 
                tempArray = nullptr;
            }
            shapes[numShapes] = collectShapes(line);
            line.clear();
            std::getline(myReadFile, line);
            numShapes++;
        }
        myReadFile.close(); 
    }
    else
    {
        std::cout << "Error opening the file.\n"; 
        exit(EXIT_FAILURE);
    }

    Figure figure(shapes, numShapes);

    Shape **closestShapes = figure.getClosest(shapes[0], 3);

    for(int i = 0; i < 3; i++)
    {
        std::cout << *closestShapes[i];
    }


    std::getchar();

    return 0;

}



