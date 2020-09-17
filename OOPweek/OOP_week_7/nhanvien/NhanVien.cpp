#include "NhanVien.h"
void NhanVien::Xuat(){
    cout << "ho ten : " << this->hoten << ".\n";
    cout << "ngay sinh : "; this->XuatNgaySinh();
    cout << "luong co ban : " << this->luongcanban << ".\n";

}
void NhanVien::Nhap(){
    cin.ignore();
    cout << "nhap ho ten : ";
    getline(cin,this->hoten);
    cout << "nhap ngay sinh : \n";
    NhapNgaySinh();
    cout << "nhap luong co ban : ";
    cin >> this->luongcanban;
}
float NhanVien::traLuong(){
    return this->luongcanban;
}
NhanVien::NhanVien()
{
}

NhanVien::~NhanVien()
{
}

void NhanVien::NhapNgaySinh(){
    cout << "ngay : ";
    cin >> this->ngaysinh.day;
    cout << "thang : ";
    cin >> this->ngaysinh.month;
    cout << "nam : ";
    cin >> this->ngaysinh.year;

}
void NhanVien::XuatNgaySinh(){
    cout << this->ngaysinh.day << "/" << this->ngaysinh.month << "/" << this->ngaysinh.year << ".\n";
}