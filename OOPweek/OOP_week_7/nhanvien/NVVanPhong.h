
#include "NhanVien.h"
class NVVanPhong : public NhanVien
{
private:
    int songaylamviec;
public:
    void Nhap();
    void Xuat();
    float traLuong();
    NVVanPhong();
    ~NVVanPhong();
};
