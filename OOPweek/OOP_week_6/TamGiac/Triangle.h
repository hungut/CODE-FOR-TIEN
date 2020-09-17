#include "Point.h"

class Triangle
{
private:
    Point A,B,C;
public:
    double getAB();
    double getBC();
    double getCA();
    double getP();
    void SetTriangle();
    void Display();
    Triangle();
    Triangle(Point a,Point b,Point c);
    double GetArea();
    double GetPerimeter();
    void Copy(Triangle &T);
    ~Triangle();
};

