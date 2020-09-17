#include <iostream>
#include "Point.h"

int main(){
    Point p;
    p.init(2,4);
    p.display();
    p.move(6,9);
    p.display();
    system("pause");
    return 0;
}