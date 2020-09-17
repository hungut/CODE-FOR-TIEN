#include <iostream>
#include "time.h"
using namespace std;

class Time
{
private:
    double Hour;
    double Min;
    double Sec;
public:
    void TakeTimeFromCurrent();
    void InSec();
    void InputTime();
    void ShowTime();
    void WhatTimeIsIt();
    double getHour();
    void setHour(double Hour);
    double getMin();
    void setMin(double Min);
    double getSec();
    void setSec(double Sec);
    Time(double h,double m, double s);
    Time();
    ~Time();
};


