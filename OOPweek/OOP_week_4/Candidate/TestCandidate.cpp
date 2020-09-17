#include "TestCandidate.h"
void TestCandidate::NhapThongTinThiSinh(TestCandidate TC[],int &n){
    cout << "nhap so luong Thi Sinh : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TC[i].NhapThongTin();
    }
}
bool TestCandidate::KiemTraTongDiem_LonHon_15(){
    if (this->iTongDiem() > 15)
    {
        return true;
    }
    return false;
}
void TestCandidate::XuatKQKiemTra(TestCandidate TC[],int n){
    cout << "thi sinh co diem > 15 : \n";
    for (int i = 0; i < n; i++)
    {
        if (TC[i].KiemTraTongDiem_LonHon_15())
        {
            TC[i].XuatThongTin();
        }
    }
}
