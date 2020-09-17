#include "Square.h"
#include <iostream>

using namespace std;

Square::Square()
{
	this->iLenght = 0;
}
Square::~Square()
{

}
void Square::nhap()
{
	cout << "nhap canh: ";
	cin >> this->iLenght;
	this->idientich = this->iLenght * this->iLenght;
}
void Square::printInfo()
{
	cout << "hinh vuong" << endl;
	cout << "canh: " << this->iLenght << endl;
	cout << "dien tich: " << this->idientich << endl;
}