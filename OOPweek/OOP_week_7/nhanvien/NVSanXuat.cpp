#include "NVSanXuat.h"
void NVSanXuat::Xuat(){
    cout << "nhan vien san xuat.\n";
    NhanVien::Xuat();
    cout << "so san pham : " << this->sosanpham << ".\n";
    cout << "luong : " << this->traLuong() << ".\n";
}
void NVSanXuat::Nhap(){
    NhanVien::Nhap();
    cout << "nhap so san pham : ";
    cin >> this->sosanpham;
}
float NVSanXuat::traLuong(){
    return NhanVien::traLuong()*this->sosanpham*5;
}
NVSanXuat::NVSanXuat()
{
}

NVSanXuat::~NVSanXuat()
{
}
