#pragma once
#include "Farm.h"

class Donkey : public Farm
{
public:
	Donkey();
	~Donkey();
	void setMilk();
	void setBreed();
	void printInfo();
};

