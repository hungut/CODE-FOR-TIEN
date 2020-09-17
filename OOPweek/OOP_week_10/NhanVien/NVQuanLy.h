#pragma once
#include "NhanVien.h"

class NVQuanLy : public NhanVien
{
	int HeSo;
	int Thuong;
public:
	NVQuanLy();
	~NVQuanLy();
	void nhap();
	void printInfo();
};

