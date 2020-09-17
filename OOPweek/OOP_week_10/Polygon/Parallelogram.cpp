#include "Parallelogram.h"
#include <iostream>

using namespace std;

Parallelogram::Parallelogram()
{
	this->iBottom = this->iHeight = 0;
}
Parallelogram::~Parallelogram()
{

}
void Parallelogram::nhap()
{
	cout << "nhap do dai day: ";
	cin >> this->iBottom;
	cout << "nhap chieu cao: ";
	cin >> this->iHeight;
	this->idientich = this->iBottom * this->iHeight;
}
void Parallelogram::printInfo()
{
	cout << "hinh binh hanh" << endl;
	cout << "day: " << this->iBottom << "\nchieu cao: " << this->iHeight << endl;
	cout << "dien tich: " << this->idientich << endl;
}