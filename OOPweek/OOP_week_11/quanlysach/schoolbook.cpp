#include "schoolbook.h"

void SCHOOLBOOK::Nhap(){
    BOOK::Nhap();
    cin.ignore();
    cout << "input publisher name : ";
    getline(cin,this->publisher);
}
void SCHOOLBOOK::Xuat(){
    cout << "School book, ";
    BOOK::Xuat();
    cout << "publisher name : " << this->publisher << "\n";
}
SCHOOLBOOK::SCHOOLBOOK()
{
}

SCHOOLBOOK::~SCHOOLBOOK()
{
}
