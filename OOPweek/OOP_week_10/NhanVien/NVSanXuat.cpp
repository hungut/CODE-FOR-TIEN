#include "NVSanXuat.h"

NVSanXuat::NVSanXuat()
{

}
NVSanXuat::~NVSanXuat()
{

}
void NVSanXuat::nhap()
{
	this->NhanVien::nhap();
	cout << "nhap so san pham: ";
	cin >> this->SoSP;
	this->Luong = this->LuongCoBan + this->SoSP * 2000;
}
void NVSanXuat::printInfo()
{
	cout << "nhan vien san xuat" << endl;
	this->NhanVien::printInfo();
	cout << "so san pham: " << this->SoSP << endl;
}