#pragma once
#include "Shape.h"

class Trapezoid : public Shape
{
	int iTop;
	int iBottom;
	int iHeight;
public:
	Trapezoid();
	~Trapezoid();
	void nhap();
	void printInfo();
};

