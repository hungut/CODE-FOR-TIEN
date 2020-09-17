#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    double dx;
    double dy;
public:
    Point();
    Point(double x,double y);
    Point(Point &P);
    ~Point();
    void SetPoint();
    void Display();
    double Distance(Point &P);
    void Copy(Point &P);
};
