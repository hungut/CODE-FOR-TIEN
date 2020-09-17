#include "magazine.h"

void MAGAZINE::Nhap(){
    BOOK::Nhap();
    cout << "input publish date : ";
    cin >> this->publishDate;
}
void MAGAZINE::Xuat(){
    cout << "Magazine, ";
    BOOK::Xuat();
    cout << "Publish date : " << this->publishDate << "\n";
}
MAGAZINE::MAGAZINE(){}
MAGAZINE::~MAGAZINE(){}