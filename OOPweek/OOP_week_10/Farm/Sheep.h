#pragma once
#include "Farm.h"

class Sheep : public Farm
{
public:
	Sheep();
	~Sheep();
	void setMilk();
	void setBreed();
	void printInfo();
};
