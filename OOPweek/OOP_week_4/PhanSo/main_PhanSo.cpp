#include "PhanSo.h"

int main()
{
    PhanSo A,B,Tong,Hieu,Tich,Thuong;
    cout << "nhap phan so thu nhat : \n";
    A.NhapPhanSo();
    cout << "nhap phan so thu hai : \n";
    B.NhapPhanSo();
    cout << "Tong cua hai phan so : \n";
    Tong = A.Cong(B);
    Tong.XuatPhanSo();
    cout << "Hieu cua hai phan so : \n";
    Hieu = A.Tru(B);
    Hieu.XuatPhanSo();
    cout << "Tich cua hai phan so : \n";
    Tich = A.Nhan(B);
    Tich.XuatPhanSo();
    cout << "Thuong cua hai phan so : \n";
    Thuong = A.Chia(B);
    Thuong.XuatPhanSo();
    system("pause");
    return 0;
}