#include "Student.h"
void Student::setInfo(){
    cout << "set info for this sutdent : \n";
    Human::setInfo();
    cout << "ID : ";
    cin.ignore();
    getline(cin,this->id);
    cout << "grades : ";
    cin >> this->grades;

}
void Student::getInfo(){
    cout << "Info of Student : \n";
    Human::getInfo();
    cout << "ID : " << this->id<< "\nGrades : " << this->grades << "\n";
}
float Student::getGrades() {
	return this->grades;
}
void Student::setGrades(float grades) {
	this->grades = grades;
}

string Student::getId() {
	return this->id;
}
void Student::setId(string id) {
	this->id = id;
}
Student::Student()
{
    this->setWorkplace("School");
}

Student::~Student()
{
}
