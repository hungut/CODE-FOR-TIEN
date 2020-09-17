#include "book.h"
void BOOK::Nhap(){
    cin.ignore();
    cout << "input tittle : ";
    getline(cin,this->tittle);
    cout << "input pages : ";
    cin >> this->pages;
}
void BOOK::Xuat(){
    cout << "Tittle : " << this->tittle << " , Pages : " << this->pages << "\n";
}
BOOK:: BOOK()
{
}
BOOK:: ~BOOK()
{
}
