#include <iostream>
using namespace std;
class Rectangle
{
private:
    int width;
    int length;
public:
    Rectangle(int l,int w);
    Rectangle(const Rectangle &rect);
    Rectangle();
    ~Rectangle();
    int getWidth();
    void setWidth(int width);
    int getLength(); 
    void setLength(int length); 
    void ShowRectangle();
    int getArea();
};


