#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
	this->iHeight = this->iLenght = 0;
}
Rectangle::~Rectangle()
{

}
void Rectangle::nhap()
{
	cout << "nhap chieu cao: ";
	cin >> this->iHeight;
	cout << "nhap chieu dai: ";
	cin >> this->iLenght;
	this->idientich = this->iLenght * this->iHeight;
}
void Rectangle::printInfo()
{
	cout << "hinh chu nhat" << endl;
	cout << "chieu dai: " << this->iLenght << endl;
	cout << "chieu cao: " << this->iHeight << endl;
	cout << "dien tich: " << this->idientich << endl;
}