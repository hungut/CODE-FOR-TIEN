#include "MyTime.h"
void Time::TakeTimeFromCurrent(){
    cout << "take time from computer......\n";
    time_t CurTime;
    struct tm *info;
    time(&CurTime);
    info = gmtime(&CurTime);
    this->Hour = (double)((info->tm_hour+7)%24);
    this->Min = (double)info->tm_min;
    this->Sec = (double)info->tm_sec;
    this->ShowTime();
}
void Time::InSec(){
    cout << "the time you input in is : ";
    cout << this->Hour*60*60 + this->Min*60 + this->Sec << " second.\n";
}
void Time::ShowTime(){
    cout << "the time you input in is : ";
    cout << this->Hour << ":" << this->Min << ":" << this->Sec << "\n";
}
void Time::InputTime(){
    cout << "input hour :";
    cin >> this->Hour;
    cout << "input min : ";
    cin >> this->Min;
    cout << "input sec : ";
    cin >> this->Sec;
}
void Time::WhatTimeIsIt(){
    time_t CurTime;
    struct tm *info;
    time(&CurTime);
    info = gmtime(&CurTime);
    printf("it is %2d:%02d:%02d now\n", (info->tm_hour+7)%24,info->tm_min,info->tm_sec);
}
Time::Time(double h,double m, double s){
    this->Hour = h;
    this->Min = m;
    this->Sec = s;
}
double Time::getHour() {
    return this->Hour;
}
void Time::setHour(double Hour) {
    this->Hour = Hour;
}
double Time::getMin() {
    return this->Min;
}
void Time::setMin(double Min) {
    this->Min = Min;
}
double Time::getSec() {
    return this->Sec;
}
void Time::setSec(double Sec) {
    this->Sec = Sec;
}
Time::Time()
{
    this->Hour = 0;
    this->Min = 0;
    this->Sec = 0;
}

Time::~Time()
{
}