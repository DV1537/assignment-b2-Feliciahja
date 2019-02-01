#include "Shape.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Line.h"
#include "Point.h"

Shape* getShape(int numCoords, double *xCoord, double *yCoord);

Shape* collectShapes(std::string line);

void swap(double* a, double* b);

int partition (double arr[], int low, int high);

void quickSort(double arr[], int low, int high);
