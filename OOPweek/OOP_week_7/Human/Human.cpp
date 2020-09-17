#include "Human.h"

void Human::setInfo(){
    cout << "pls input these following info : \n";
    cout << "name : ";
    getline(cin,this->name);
    cout << "year of birth : ";
    cin >> this->year;
    cout << "address : ";
    cin.ignore();
    getline(cin,this->address);
}

void Human::getInfo(){
    
    cout << "name : " << this->name << "\nyear of birth : " << this->year << "\naddress : " << this->address << "\n";
    cout << "workplace : " << this->workplace << "\n";
}

Human::Human()
{
}

Human::~Human()
{
}

string Human::getName() {
	return this->name;
}
void Human::setName(string name) {
	this->name = name;
}


int Human::getYear() {
	return this->year;
}
void Human::setYear(int year) {
	this->year = year;
}


string Human::getAddress() {
	return this->address;
}
void Human::setAddress(string address) {
	this->address = address;
}
string Human::getWorkplace() {
	return this->workplace;
}
void Human::setWorkplace(string workplace) {
	this->workplace = workplace;
}