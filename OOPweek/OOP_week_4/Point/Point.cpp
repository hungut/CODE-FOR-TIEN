#include <iostream>
#include "Point.h"
using namespace std;

void Point::init(int ox,int oy){
    cout << "init this Point.\n";
    x = ox; y = oy;
}
void Point::move(int dx,int dy){
    cout << "moved Point to " << dx << "; " << dy << "\n";
    x += dx;
    y += dy;
}
void Point::display(){
    cout << "Point at => ( " << x << "; " << y << " ).\n";
}
Point::Point()
{
}

Point::~Point()
{
}