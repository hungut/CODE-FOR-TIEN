#include "Doctor.h"

void Doctor::setInfo(){
    cout << "set info for this doctor : \n";
    Human::setInfo();
    cout << "specialty : ";
    getline(cin,this->specialty);
    cout << "year of experience : ";
    cin >> this->exp_years;
}
void Doctor::getInfo(){
    cout << "Info of Doctor : \n";
    Human::getInfo();
    cout << "specialty : " << this->specialty << "\nyear of experience : " << this->exp_years << "\n";
}

Doctor::Doctor()
{ 
    this->setWorkplace("Hospital");
}

Doctor::~Doctor()
{
}

string Doctor::getSpecialty() {
	return this->specialty;
}
void Doctor::setSpecialty(string specialty) {
	this->specialty = specialty;
}


int Doctor::getExp_years() {
	return this->exp_years;
}
void Doctor::setExp_years(int exp_years) {
	this->exp_years = exp_years;
}
