#include "Cow.h"
#include <iostream>

using namespace std;

Cow::Cow()
{
	this->Farm::Farm();
	this->sSound = "Mooo";
}
Cow::~Cow()
{

}
void Cow::setBreed()
{
	this->iBreed = this->getBreed() + (rand() % 3);
}
void Cow::setMilk()
{
	this->fMilk = this->getMilk() + (rand() % 20);
}
void Cow::printInfo()
{
	cout << "Cow" << endl;
	this->Farm::printInfo();
}