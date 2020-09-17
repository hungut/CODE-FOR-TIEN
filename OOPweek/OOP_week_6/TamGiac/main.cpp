#include "Triangle.h"

int main()
{   
    cout << "how many triangles to input : ";
    int n;
    cin >> n;
    Triangle T[50];

    for (int i = 0; i < n; i++)
    {
        cout << "input triangle #" << i+1 << " : \n";
        cout << "custom triangle, Y/N ?\n";
        char c;
        cin >> c;
        switch (c)
        {
        case 'Y': T[i].SetTriangle();
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        T[i].Display();
    }
    Triangle maxTriangle;
    double maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        if(maxArea < T[i].GetArea()){
            maxArea = T[i].GetArea();
            maxTriangle.Copy(T[i]);
        }
    }
    cout << "the triangle has the biggest area and perimeter : \n";
    maxTriangle.Display();
    system("pause");
    return 0;
}
