#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct SINHVIEN 
{
	string HoTen;
	int DiemToan;
	int DiemVan;
	float DiemTrungBinh = ((float)DiemToan + (float)DiemVan)/2;
};

void nhapThongTin(SINHVIEN &SV)
{
	cout << "Nhap ho ten sinh vien : ";
	getline(cin, SV.HoTen);
	cout << "Nhap diem toan : ";
	cin >> SV.DiemToan;
	cout << "Nhap diem van : ";
	cin >>SV.DiemVan;
}

void xuatThongTin(SINHVIEN SV)
{
	cout << "ho ten : " << SV.HoTen << "\t diem trung binh : "  << SV.DiemTrungBinh << "\n";
	cout << "diem toan : " << SV.DiemToan << "\t diem van : " << SV.DiemVan << "\n";
}
int main()
{
	SINHVIEN SV;
	nhapThongTin(SV);
	xuatThongTin(SV);

	system("pause");
	return 0;
}