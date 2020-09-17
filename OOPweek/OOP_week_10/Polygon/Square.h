#pragma once
#include "Shape.h"

class Square : public Shape
{
	int iLenght;
public:
	Square();
	~Square();
	void nhap();
	void printInfo();
};

