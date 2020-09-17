#include "NVQuanLy.h"
#include "NhanVien.h"

NVQuanLy::NVQuanLy()
{

}
NVQuanLy::~NVQuanLy()
{

}
void NVQuanLy::nhap()
{
	this->NhanVien::nhap();
	cout << "nhap he so chuc vu: ";
	cin >> this->HeSo;
	cout << "nhap tien thuong: ";
	cin >> this->Thuong;
	this->Luong = this->LuongCoBan * this->HeSo + this->Thuong;
}
void NVQuanLy::printInfo()
{
	cout << "nhan vien quan ly" << endl;
	this->NhanVien::printInfo();
	cout << "he so chuc vu: " << this->HeSo << "\ntien thuong: " << this->Thuong << endl;
}
