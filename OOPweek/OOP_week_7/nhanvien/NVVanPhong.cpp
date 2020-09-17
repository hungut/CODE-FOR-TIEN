#include "NVVanPhong.h"
void NVVanPhong::Xuat(){
    cout << "nhan vien van phong.\n";
    NhanVien::Xuat();
    cout << "so ngay lam viec : " << this->songaylamviec << ".\n";
    cout << "luong : " << this->traLuong() << ".\n";
}
void NVVanPhong::Nhap(){
    NhanVien::Nhap();
    cout << "nhap so ngay lam viec : ";
    cin >> this->songaylamviec;
}
float NVVanPhong::traLuong(){
    return NhanVien::traLuong()*this->songaylamviec*10;
}
NVVanPhong::NVVanPhong()
{
}
NVVanPhong::~NVVanPhong()
{
}
