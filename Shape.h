#ifndef SHAPE_H
#define SHAPE_H
#include <string>


struct ObjectPosition
{
    double x, y;
};

class Shape
{
    protected:
    double *xCoord;
    double *yCoord;
    int pointCount;

    public:
    virtual std::string getType() = 0;
    virtual double area();
    virtual double circumference();
    virtual bool isConvex();
    virtual ObjectPosition position() = 0;
    double distance(Shape* s);
    //virtual Shape& operator=(const Shape &s) = 0;
    virtual Shape& operator+(const Shape &s);
    friend std::ostream &operator<<(std::ostream &streamobj, const Shape &s);
    double* getxCoords() {return xCoord;}
    double* getyCoords() {return yCoord;}
    int getAmountOfCoords() {return pointCount;}
    virtual ~Shape();

};

#endif // !SHAPE_H