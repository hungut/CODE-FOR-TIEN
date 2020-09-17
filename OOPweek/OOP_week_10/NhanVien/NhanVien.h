#pragma once
#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
protected:
	struct ngaythangnam
	{
		int Ngay;
		int Thang;
		int Nam;
	};
	string HoTen;
	ngaythangnam NgaySinh;
	int Luong;
	int LuongCoBan;
public:
	NhanVien();
	~NhanVien();
	virtual void nhap();
	void setNgaySinh();
	string getHoTen()
	{
		return this->HoTen;
	}
	int getLuong()
	{
		return this->Luong;
	}
	virtual void printInfo();
};

