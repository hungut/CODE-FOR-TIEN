#pragma once
#include <string>

using namespace std;

class Farm
{
protected:
	int iBreed;
	float fMilk;
	string sSound;
	string sStatus;
public:
	Farm();
	~Farm();
	string getStatus()
	{
		return this->sStatus;
	}
	string getSound()
	{
		return this->sSound;
	}
	void setFull();
	virtual void setMilk();
	float getMilk()
	{
		return this->fMilk;
	}
	int getBreed()
	{
		return this->iBreed;
	}
	virtual void setBreed();
	virtual void printInfo();
};

