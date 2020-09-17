#include "NVVanPhong.h"
#include "NVSanXuat.h"

int main()
{
    
    int n,c = 1;
    
    NhanVien **NV = new NhanVien*[100];
    while (c != 0)
    {
        if (c < 0 && c > 3)
        {
            cout << "tinh nang chua duoc cap nhat hoac khong ton tai, yeu cau nhap tinh nang khac: ";
            cin >> c;
        }
        cout << "chuong trinh quan ly nhan vien : \n";
        cout << "1. nhap danh sach nhan vien.\n";
        cout << "2. xuat danh sach nhan vien.\n";
        cout << "3. nhan vien co luong cao nhat va thap nhat.\n";
        cout << "0. thoat.\n";
        cout << "chon : ";
        cin >> c;
        switch (c)
        {
        case 1: 
                {
                    cout << "so luong nhan vien : ";
                    cin >> n;
                    for (int i = 0; i < n; i++)
                    {
                        int chon;
                        cout << "chon loai nhan vien : \n"<<"1.Van Phong.\n" << "2.San Xuat.\n";
                        cin >> chon;
                        if (chon == 1)
                        {

                            NV[i] = new NVVanPhong;
                            NV[i]->Nhap();
                        }
                        if (chon == 2)
                        {
                            NV[i] = new NVSanXuat;
                            NV[i]->Nhap();
                        }
                    }
                    
                }
            break;
        case 2: 
            {
                cout << "xuat danh sach nhan vien: \n";
                for (int i = 0; i < n; i++)
                {
                    NV[i]->Xuat();
                }
                
            }
            break;
        case 3:
            {
                float max = 0, min = 3.40282e+038;
                NhanVien **NVtemp = new NhanVien*[2];
                for (int i = 0; i < n; i++)
                {
                    if (max < NV[i]->traLuong())
                    {
                        max = NV[i]->traLuong();
                        NVtemp[0] = NV[i];
                    }
                    if (min > NV[i]->traLuong())
                    {
                        min  = NV[i]->traLuong();
                        NVtemp[1] = NV[i];
                    }
                }
                cout << "nhan vien co luong cao nhat la: \n";
                NVtemp[0]->Xuat();
                cout << "nhan vien co luong thap nhat la: \n";
                NVtemp[1]->Xuat();
            }
            break;
        
        case 0:exit(1);
        }
    }
    system("pause");
    return 0;
}
