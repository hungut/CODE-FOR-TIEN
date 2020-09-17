#include "Point.h"

int main(){
    Point p1(6,9);
    Point p2(7);
    Point p3;
    p1.display();
    p1.distanceFrom_O();
    p2.display();
    p2.distanceFrom_O();
    p3.display();
    p3.distanceFrom_O();
    p1.distanceFrom(p2);
    system("pause");
    return 0;
}