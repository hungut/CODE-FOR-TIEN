#pragma once
#include "Farm.h"

class Cow : public Farm
{
public:
	Cow();
	~Cow();
	void setMilk();
	void setBreed();
	void printInfo();
};

