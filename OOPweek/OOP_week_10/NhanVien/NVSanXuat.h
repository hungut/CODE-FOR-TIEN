#pragma once
#include "NhanVien.h"

class NVSanXuat : public NhanVien
{
private:
	int SoSP;
public:
	NVSanXuat();
	~NVSanXuat();
	void nhap();
	void printInfo();
};

