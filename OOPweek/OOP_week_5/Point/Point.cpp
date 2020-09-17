#include "Point.h"

void Point::distanceFrom(Point des){
    cout << "distance from ";
    this->display();
    cout << "to ";
    des.display();
    cout << "is " << (double)sqrt(pow(this->x - des.x,2)+pow(this->y - des.y,2)) << "\n";
}
void Point::distanceFrom_O(){
    cout << "distance from Oxy is : " << (double)sqrt(pow(this->x,2)+pow(this->y,2)) << "\n";
}
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
    cout << "( " << x << "; " << y << " ).\n";
}

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::~Point()
{
}