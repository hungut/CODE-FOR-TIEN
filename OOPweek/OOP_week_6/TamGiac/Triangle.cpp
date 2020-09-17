#include "Triangle.h"
double Triangle::getAB(){
    return this->A.Distance(B);
}
double Triangle::getBC(){
    return this->B.Distance(C);
}
double Triangle::getCA(){
    return this->C.Distance(A);
}
double Triangle::getP(){
    return this->GetPerimeter()/2;
}
void Triangle::Copy(Triangle &T){
    this->A = T.A;
    this->B = T.B;
    this->C = T.C;
}
double Triangle::GetArea(){
    double P = this->getP();
    double AB = this->getAB();
    double BC = this->getBC();
    double CA = this->getCA();
    return sqrt(P*(P - AB)*(P - BC)*(P - CA));
}
double Triangle::GetPerimeter(){
    // return this->AB + this->BC + this->CA;
    return this->getAB() + this->getBC() + this->getCA();
}
void Triangle::SetTriangle(){
    cout << "input 3 point of triangle : \n";
    cout << "A = \n";
    this->A.SetPoint();
    cout << "B = \n";
    this->B.SetPoint();
    cout << "C = \n";
    this->C.SetPoint();
}
void Triangle::Display(){
    cout << "This Triangle have :\n";
    cout << "AB = " << this->getAB() << "\n";
    cout << "BC = " << this->getBC() << "\n";
    cout << "CA = " << this->getCA() << "\n";
    cout << "Area = " << this->GetArea() << "\n";
    cout << "Perimeter = " << this->GetPerimeter() << "\n";
}
Triangle::Triangle()
{
    this->A = Point();
    this->B = Point();
    this->C = Point();
}
Triangle::Triangle(Point a,Point b,Point c)
{
    this->A = a;
    this->B = b;
    this->C = c;
}
Triangle::~Triangle()
{
}