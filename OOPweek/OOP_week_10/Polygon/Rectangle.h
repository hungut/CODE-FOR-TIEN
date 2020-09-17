#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	int iHeight;
	int iLenght;
public:
	Rectangle();
	~Rectangle();
	void nhap();
	void printInfo();
};

