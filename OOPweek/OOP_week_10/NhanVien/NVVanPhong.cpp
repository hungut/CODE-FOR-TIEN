#include "NVVanPhong.h"
#include "NhanVien.h"

NVVanPhong::NVVanPhong()
{

}
NVVanPhong::~NVVanPhong()
{

}
void NVVanPhong::nhap()
{
	this->NhanVien::nhap();
	cout << "nhap so ngay lam viec: ";
	cin >> this->SoNLV;
	cout << "nhap tro cap: ";
	cin >> this->TroCap;
	this->Luong = this->LuongCoBan + this->SoNLV * 200000 + this->TroCap;
}
void NVVanPhong::printInfo()
{
	cout << "nhan vien van phong" << endl;
	this->NhanVien::printInfo();
	cout << "so ngay lam viec: " << this->SoNLV << "\ntro cap: " << this->TroCap << endl;
}