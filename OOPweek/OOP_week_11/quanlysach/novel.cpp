#include "novel.h"

void NOVEL::Nhap(){
    BOOK::Nhap();
    cin.ignore();
    cout << "input author name : ";
    getline(cin,this->author);
}
void NOVEL::Xuat(){
    cout << "Novel, ";
    BOOK::Xuat();
    cout << "author name : " << this->author << "\n";
}
NOVEL::NOVEL()
{
}

NOVEL::~NOVEL()
{
}
