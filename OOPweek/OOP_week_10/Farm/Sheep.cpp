#include "Sheep.h"
#include <iostream>

using namespace std;

Sheep::Sheep()
{
	this->Farm::Farm();
	this->sSound = "Beeee";
}
Sheep::~Sheep()
{

}
void Sheep::setBreed()
{
	this->iBreed = this->getBreed() + (rand() % 3);
}
void Sheep::setMilk()
{
	this->fMilk = this->getMilk() + (rand() % 5);
}
void Sheep::printInfo()
{
	cout << "Sheep" << endl;
	this->Farm::printInfo();
}