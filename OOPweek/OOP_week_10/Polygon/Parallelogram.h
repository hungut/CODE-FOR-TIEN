#pragma once
#include "Shape.h"

class Parallelogram : public Shape
{
	int iBottom;
	int iHeight;
public:
	Parallelogram();
	~Parallelogram();
	void nhap();
	void printInfo();
};
