#include "NhanVien.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"
#include "NVQuanLy.h"
#include <iostream>

using namespace std;

void xuatNV(NhanVien* nv[], int n);
void tongLuong(NhanVien* nv[], int n);
void menu();
void timkiem(NhanVien* nv[], int n);

void main()
{
	int n = 0, choose = -1;
	NhanVien *nv[50];
	while (choose != 0)
	{
		menu();
		cin >> choose;
		cout << endl;
		switch (choose)
		{
		case 1:
		{
			int choose2;
		nhaplai:
			cout << "loai nhan vien:" << endl;
			cout << "1. nhan vien van phong" << endl;
			cout << "2. nhan vien san xuat" << endl;
			cout << "3. nhan vien quan ly" << endl;
			cout << "lua chon: ";
			cin >> choose2;
			switch (choose2)
			{
			case 1: nv[n] = new NVVanPhong(); break;
			case 2: nv[n] = new NVSanXuat(); break;
			case 3: nv[n] = new NVQuanLy(); break;
			default:
			{
				cout << "chon lai" << endl;
				goto nhaplai;
			}
			}
			nv[n]->nhap();
			n++;
		}; break;
		case 2:
		{
			xuatNV(nv, n);
		}; break;
		case 3:
		{
			tongLuong(nv, n);
		}; break;
		case 4:
		{
			timkiem(nv, n);
		}; break;
		}
		cout << endl;
	}
}
void xuatNV(NhanVien* nv[], int n)
{
	int i;
	cout << "danh sach nhan vien: " << endl;
	for (i = 0; i < n; i++)
	{
		cout << endl;
		nv[i]->printInfo();
	}
}
void tongLuong(NhanVien* nv[], int n)
{
	long Luongcty = 0;
	for (int i = 0; i < n; i++)
	{
		Luongcty = Luongcty + nv[i]->getLuong();
	}
	cout << "tong luong cua ca cong ty: " << Luongcty << endl;
}
void menu()
{
	cout << "- CONG TY ABC -" << endl;
	cout << "1. them nhan vien" << endl;
	cout << "2. xuat danh sach nhan vien" << endl;
	cout << "3. xuat tong luong cua ca cong ty" << endl;
	cout << "4. tim nhan vien" << endl;
	cout << "0. thoat" << endl;
	cout << "nhap lua chon: ";
}
void timkiem(NhanVien* nv[], int n)
{
	string ten;
	cout << "nhap ho ten nhan vien can tim: ";
	cin.ignore();
	getline(cin, ten);
	for (int i = 0; i < n; i++)
	{
		if (nv[i]->getHoTen() == ten)
		{
			cout << endl;
			nv[i]->printInfo();
		}
	}
}