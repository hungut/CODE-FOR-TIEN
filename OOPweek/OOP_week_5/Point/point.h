#include <iostream>
#include <math.h>
using namespace std;
class Point
{
private:
    int x,y;
public:
    void distanceFrom(Point des);
    void distanceFrom_O();
    void init(int ox,int oy);
    void move(int dx,int dy);
    void display();
    Point(int ox,int oy = 69)
    {
        this->x = ox;
        this->y = oy;
    }
    Point();
    ~Point();
};


