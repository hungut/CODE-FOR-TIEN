#include "Point.h"
void Point::Copy(Point &P){
    this->dx = P.dx;
    this->dy = P.dy;
}
double Point::Distance(Point &P){
    return sqrt(pow(this->dx - P.dx,2) + pow(this->dy - P.dy,2));
}
void Point::Display(){
    cout << "x = " << this->dx << ", y = " << this->dy << ".\n" ;
}

void Point::SetPoint(){
    cout << "input x : ";
    cin >> this->dx;
    cout << "input y : ";
    cin >> this->dy;
}
Point::Point()
{
    this->dx = 0;
    this->dy = 0;
}
Point::Point(Point &P){
    this->dx = P.dx;
    this->dy = P.dy;
}
Point::Point(double x,double y){
    this->dx = x;
    this->dy = y;
}
Point::~Point()
{
}

