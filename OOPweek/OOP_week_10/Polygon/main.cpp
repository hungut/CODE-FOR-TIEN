#include "Parallelogram.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Square.h"
#include "Trapezoid.h"
#include <iostream>

using namespace std;

void menu();

void main()
{
	Shape* s[50];
	int n = 0;
	int choose = -1;
	while (choose != 0)
	{
		cout << "1. nhap hinh" << endl;
		cout << "2. xuat hinh" << endl;
		cout << "0. thoat" << endl;
		cout << "nhap lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int choose2;
			menu();
			cin >> choose2;
			switch (choose2)
			{
			case 1:	s[n] = new Trapezoid(); break;
			case 2:	s[n] = new Parallelogram(); break;
			case 3:	s[n] = new Rectangle(); break;
			case 4:	s[n] = new Square(); break;
			}
			s[n]->nhap();
			n++;
		}; break;
		case 2:
		{
			for (int i = 0; i < n; i++)
			{
				s[i]->printInfo();
			}
		}; break;
		}
	}
}
void menu()
{
	cout << "1. hinh thang" << endl;
	cout << "2. hinh binh hanh" << endl;
	cout << "3. hinh chu nhat" << endl;
	cout << "4. hinh vuong" << endl;
	cout << "nhap lua chon: ";
}