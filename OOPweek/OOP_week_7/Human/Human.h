#pragma once
#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    string name;
    int year;
    string address;
    string workplace;
public:
    virtual void setInfo();
    virtual void getInfo();
    string getName();
    void setName(string name);
    int getYear();
    void setYear(int year);
    string getAddress();
    void setAddress(string address);
    Human();
    ~Human();
    string getWorkplace() {
        return this->workplace;
    }
    void setWorkplace(string workplace) {
        this->workplace = workplace;
    }
};

