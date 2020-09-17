#include "Farm.h"
#include <iostream>

using namespace std;

const string status[2] = { "hungry", "full" };

Farm::Farm()
{
	this->iBreed = 0;
	this->fMilk = 0;
	this->sStatus = status[rand() % 2];
}
Farm::~Farm()
{

}
void Farm::setFull()
{
	this->sStatus = "full";
}
void Farm::setMilk()
{
	this->fMilk = 0;
}
void Farm::setBreed()
{
	this->iBreed = 0;
}
void Farm::printInfo()
{
	cout << "status: " << this->getStatus() << endl;
	cout << "sound: " << this->getSound() << endl;
	cout << "milk: " << this->getMilk() << endl;
	cout << "breed: " << this->getBreed() << endl;
}