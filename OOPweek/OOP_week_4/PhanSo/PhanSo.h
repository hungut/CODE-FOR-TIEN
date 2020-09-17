#include <iostream>
using namespace std;
class PhanSo
{
private:
    int iTuSo;
    int iMauSo;

public:
    void NhapPhanSo();
    void XuatPhanSo();
    PhanSo Cong(PhanSo);
    PhanSo Tru(PhanSo);
    PhanSo Nhan(PhanSo);
    PhanSo Chia(PhanSo);

    // int fractionGCD = GCD(abs(f->iDenominator),abs(f->iNumerator));
    // f->iDenominator /= fractionGCD;
    // f->iNumerator   /= fractionGCD;

    void RutGon();
    void setMauSo(int iMauSo);
    int getMauSo();
    void setTuSo(int iTuSo);
    int getTuSo();
    PhanSo();
    ~PhanSo();
};

