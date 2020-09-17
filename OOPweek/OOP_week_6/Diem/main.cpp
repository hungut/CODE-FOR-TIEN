#include "Point.h"

int main()
{
    //? nhap so luong diem
    cout << "how many points to input : ";
    int n;
    cin >> n;
    Point P[n];
    //? nhap cac diem
    for (int i = 0; i < n; i++)
    {
        cout << "input point #" << i+1 << " : \n";
        cout << "custom point, Y/N ?\n";
        char c;
        cin >> c;
        switch (c)
        {
        case 'Y': P[i].SetPoint();
            break;
        default:
            break;
        }
    }
    //? xuat cac diem
    for (int i = 0; i < n; i++)
    {
        cout << "point #" << i+1 << " : ";
        P[i].Display();
    }
    //! khoang cach lon nhat va nho nhat
    double maxdist = 0,mindist = 99999,tempmax,tempmin;
    Point max1,max2,min1,min2;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            tempmax = tempmin = P[i].Distance(P[j]);
            if (tempmax > maxdist)
            {
                maxdist = tempmax;
                max1.Copy(P[i]);
                max2.Copy(P[j]);
            }
            if (tempmin < mindist)
            {
                mindist = tempmin;
                min1.Copy(P[i]);
                min2.Copy(P[j]);
            }
            
        }
    }
    cout << "max = " << maxdist << ", of\n";
    max1.Display();
    max2.Display();
    cout << "min = " << mindist << ", of\n";
    min1.Display();
    min2.Display();
    system("pause");
    return 0;
}
