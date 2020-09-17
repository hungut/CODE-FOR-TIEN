#pragma once
#include "NhanVien.h"

class NVVanPhong : public NhanVien
{
private:
	int SoNLV;
	int TroCap;
public:
	NVVanPhong();
	~NVVanPhong();
	void nhap();
	void printInfo();
};