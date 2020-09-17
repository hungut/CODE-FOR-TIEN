
#include "NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
    int sosanpham;
public:
    void Nhap();
    void Xuat();
    float traLuong();
    NVSanXuat();
    ~NVSanXuat();
};

