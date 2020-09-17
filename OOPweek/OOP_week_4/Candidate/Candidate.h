#include <iostream>
#include <string>
using namespace std;
class Candidate
{
private:
    int iMaso;
    string sHoten;
    int iToan;
    int iVan;
    int iAnh;
public:
    int iTongDiem();
    void NhapThongTin();
    void XuatThongTin();
    int getIMaso() ;
    void setIMaso(int iMaso) ;
    string getSHoten() ;
    void setSHoten(string sHoten) ;
    int getIToan() ;
    void setIToan(int iToan) ;
    int getIVan() ;
    void setIVan(int iVan) ;
    int getIAnh() ;
    void setIAnh(int iAnh) ;
    Candidate();
    ~Candidate();
};

