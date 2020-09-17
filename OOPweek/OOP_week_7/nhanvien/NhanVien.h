#pragma once
#include <iostream>
#include <string>
using namespace std;

class NhanVien
{
private:
    struct Date
    {
        int day;
        int month;
        int year;
    };
    string hoten;
    Date ngaysinh;
    float luongcanban;
public:
    
    void NhapNgaySinh();
    void XuatNgaySinh();
    virtual void Nhap();
    virtual void Xuat();
    virtual float traLuong();
    NhanVien();
    ~NhanVien();
};
