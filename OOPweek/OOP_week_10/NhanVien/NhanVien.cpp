#include "NhanVien.h"

NhanVien::NhanVien()
{
	this->NgaySinh.Ngay = 0;
	this->NgaySinh.Thang = 0;
	this->NgaySinh.Nam = 0;
	this->HoTen = "";
	this->Luong = 0;
	this->LuongCoBan = 0;
}
NhanVien::~NhanVien()
{

}
void NhanVien::nhap()
{
	cout << "nhap ho ten: ";
	cin.ignore();
	getline(cin, this->HoTen);
	this->setNgaySinh();
}
void NhanVien::setNgaySinh()
{
	cout << "-nhap ngay sinh-" << endl;
	cout << "ngay: ";
	cin >> this->NgaySinh.Ngay;
	if (this->NgaySinh.Ngay < 1 || this->NgaySinh.Ngay > 31)
	{
		cout << "nhap lai" << endl;
		this->setNgaySinh();
	}
	cout << "thang: ";
	cin >> this->NgaySinh.Thang;
	if (this->NgaySinh.Thang > 12 || this->NgaySinh.Thang < 1)
	{
		cout << "nhap lai" << endl;
		this->setNgaySinh();
	}
	cout << "nam: ";
	cin >> this->NgaySinh.Nam;
	if (this->NgaySinh.Nam < 1)
	{
		cout << "nhap lai" << endl;
		this->setNgaySinh();
	}
}
void setLuong()
{

}
void NhanVien::printInfo()
{
	cout << "ten: " << this->getHoTen() << "\nngay sinh: " << this->NgaySinh.Ngay << "/" << this->NgaySinh.Thang << "/" << this->NgaySinh.Nam << endl;
	cout << "luong: " << this->getLuong() << endl;
}