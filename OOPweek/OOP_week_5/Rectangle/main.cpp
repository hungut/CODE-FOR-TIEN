#include "Rectangle.h"
int main()
{
    Rectangle Rect1(3,4);
    Rectangle Rect2(Rect1);
    Rectangle Rect;
    Rect1.ShowRectangle();
    Rect2.ShowRectangle();
    Rect.ShowRectangle();
    system("pause");
    return 0;
}
