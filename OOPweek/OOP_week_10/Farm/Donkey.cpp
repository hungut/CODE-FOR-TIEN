#include "Donkey.h"
#include <iostream>

using namespace std;

Donkey::Donkey()
{
	this->Farm::Farm();
	this->sSound = "Hi ho";
}
Donkey::~Donkey()
{

}
void Donkey::setBreed()
{
	this->iBreed = this->getBreed() + (rand() % 3);
}
void Donkey::setMilk()
{
	this->fMilk = this->getMilk() + (rand() % 10);
}
void Donkey::printInfo()
{
	cout << "Donkey" << endl;
	this->Farm::printInfo();
}