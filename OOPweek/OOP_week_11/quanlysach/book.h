#pragma once
#include <iostream>
#include <string>
using namespace std;
class BOOK
{
    protected:
        string tittle;
        int pages;
    public:
        virtual void Nhap();
        virtual void Xuat();
        BOOK();
        ~BOOK();
};
