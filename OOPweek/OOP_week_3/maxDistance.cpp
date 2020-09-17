#include <iostream>
#include <math.h>
using namespace std;
struct Diem
{
    int iThietLap;
    double iX;
    double iY;
};
void thietLap(Diem D[],int n);
Diem setDiem(double x,double y);
double tinhKhoangCach(Diem A, Diem B);
void timKhoangCachLonNhat(Diem D[],int n,double& max,Diem &A,Diem &B);
void getDiem(Diem D);
int nhapTatCaDiem(Diem D[]);
void xuatDiem(Diem D[],int n);
void tinhKhoangCachLonNhat(Diem D[],int n);
int main()
{
    Diem D[50];
    int n = nhapTatCaDiem(D);
    xuatDiem(D,n);
    tinhKhoangCachLonNhat(D,n);
    system("pause");
    return 0;
}
Diem setDiem(double x=0,double y=0)
{
    Diem D;
    D.iX = x;
    D.iY = y;
    return D;
}
void getDiem(Diem D)
{
    cout << "toa do : ( " << D.iX << " ; " << D.iY << " ).\n";   
}
double tinhKhoangCach(Diem A, Diem B)
{
    return sqrt(pow(A.iX - B.iX,2) + pow(A.iY-B.iY,2));
}
void thietLap(Diem D[],int n)
{
    for (int i = 0; i < n; i++)
    {
        D[i].iThietLap = i;
    }
}
int nhapTatCaDiem(Diem D[])
{
    int n,x,y;
    cout << "nhap so luong diem : ";
    cin >> n;
    thietLap(D,n);
    for (int i = 0; i < n; i++)
    {
        if(D[i].iThietLap % 3 == 0)
        {
            cout << "nhap diem # " << i+1 << " : \n";
            cout << "nhap x : ";
            cin >> x;
            cout << "nhap y : ";
            cin >> y;
            D[i] = setDiem(x,y);
        }
        if(D[i].iThietLap % 3 == 1)
        {   
            cout << "nhap diem # " << i << " : \n";
            cout << "nhap x : ";
            cin >> x;
            D[i] = setDiem(x);
        }
        if(D[i].iThietLap % 3 == 2)
        {
            D[i] = setDiem();
        }
    }
    return n;
}
void xuatDiem(Diem D[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "diem #" << i <<"\n";
        getDiem(D[i]);
    }
    
}
void tinhKhoangCachLonNhat(Diem D[],int n)
{
    int a,b;
    double max = 0;
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            temp = tinhKhoangCach(D[i],D[j]);
            if (temp > max) 
            {   
                max = temp;
                a = i;
                b = j;
            }
        }
    }
    cout << "khoang cach lon nhat : " << max << "\n";
    cout << "cua 2 diem: \n";
    cout << "diem "<< a <<" : ";
    getDiem(D[a]);
    cout << "diem "<< b <<" : ";
    getDiem(D[b]);
}