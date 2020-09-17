#include "PhanSo.h"

void PhanSo::NhapPhanSo(){
    cout << "nhap tu so: ";
    cin >> this->iTuSo;
    cout << "nhap mau so: ";
    cin >> this->iMauSo;
}
void PhanSo::XuatPhanSo(){
    cout << this->iTuSo << " / " << this->iMauSo << "\n";
}
int GCD(int x, int y)
{
    int t;
    while(y != 0) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
void PhanSo::RutGon(){
    int tempGCD = GCD(this->iMauSo,this->iTuSo);
    this->iTuSo /= tempGCD;
    this->iMauSo /= tempGCD;
}
PhanSo PhanSo::Cong(PhanSo Z){
    PhanSo Res;
    Res.iTuSo = this->iTuSo*Z.iMauSo + Z.iTuSo*this->iMauSo;
    Res.iMauSo = this->iMauSo*Z.iMauSo;
    Res.RutGon();
    return Res;
}
PhanSo PhanSo::Tru(PhanSo Z){
    PhanSo Res;
    Res.iTuSo = this->iTuSo*Z.iMauSo - Z.iTuSo*this->iMauSo;
    Res.iMauSo = this->iMauSo*Z.iMauSo;
    Res.RutGon();
    return Res;
}
PhanSo PhanSo::Nhan(PhanSo Z){
    PhanSo Res;
    Res.iTuSo = this->iTuSo*Z.iTuSo;
    Res.iMauSo = this->iMauSo*Z.iMauSo;
    Res.RutGon();
    return Res;
}
PhanSo PhanSo::Chia(PhanSo Z){
    PhanSo Res;
    Res.iTuSo = this->iTuSo*Z.iMauSo;
    Res.iMauSo = this->iMauSo*Z.iTuSo;
    Res.RutGon();
    return Res;
}
int PhanSo::getTuSo() {
	return this->iTuSo;
}
void PhanSo::setTuSo(int iTuSo) {
	this->iTuSo = iTuSo;
}


int PhanSo::getMauSo() {
	return this->iMauSo;
}
void PhanSo::setMauSo(int iMauSo) {
    this->iMauSo = iMauSo;
}

PhanSo::PhanSo()
{
}

PhanSo::~PhanSo()
{
}
