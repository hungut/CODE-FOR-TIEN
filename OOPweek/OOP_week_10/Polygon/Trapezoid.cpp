#include "Trapezoid.h"
#include <iostream>

using namespace std;

Trapezoid::Trapezoid()
{
	this->iBottom = this->iHeight = this->iHeight = 0;
}
Trapezoid::~Trapezoid()
{

}
void Trapezoid::nhap()
{
	cout << "nhap do dai day lon: ";
	cin >> this->iBottom;
	cout << "nhap do dai day be: ";
	cin >> this->iTop;
	cout << "nhap chieu cao: ";
	cin >> this->iHeight;
	this->idientich = (this->iBottom + this->iHeight) * this->iHeight / 2;
}
void Trapezoid::printInfo()
{
	cout << "hinh thang" << endl;
	cout << "day lon: " << this->iBottom << endl;
	cout << "day be: " << this->iTop << endl;
	cout << "chieu cao: " << this->iHeight << endl;
	cout << "dien tich: " << this->idientich << endl;
}