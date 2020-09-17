#include <iostream>
#include <string>
using namespace std;

typedef struct SVNode{
    string HoTen;
    string MSSV;
    float DiemToan;
    float DiemLy;
    float DiemHoa;
    struct SVNode *pNext;
    struct SVNode *pPrev;
}SVNODE;

typedef struct SVList{
    SVNode *pHead;
    SVNode *pTail;
}SVLIST;

SVNode *CreateSVNode(string,string,float,float,float);
void CreateSVList(SVLIST &);
float DiemTrungBinh(SVNode );
SVNode *NhapThongTinSV();
void NhapDanhSachSV(SVLIST &);
void addTail(SVLIST &,SVNode *);
void XuatThongTinSV(SVNode);
void XuatDanhSachSV(SVLIST);
void SuaThongTinSinhVien(SVLIST& );
bool DeleteHead(SVLIST& );
bool DeleteTail(SVLIST& );
void XoaThongTinSinhVien(SVLIST& );
void TimSinhVien(SVLIST );
void DiemTrungBinhLonHon_5(SVLIST );
void menu_context();
int main(){
    SVLIST svlist;
    int choose = 1;
	
	CreateSVList(svlist);
	while (choose != 0)
	{
		menu_context();
		cin >> choose;
        if (choose < 0 || choose > 6)
        {
            cout << "tinh nang chua co hoac khong ton tai.\n";
            cout << "xin hay thu lai: ";
            cin >> choose;
        }
        
		switch (choose)
		{
		case 1:
                {
                    NhapDanhSachSV(svlist);
                }
                break;
        case 2:
                {
                    SuaThongTinSinhVien(svlist);
                } 
                break;
        case 3:
                {
                    XoaThongTinSinhVien(svlist);
                } 
                break;
        case 4:
                {
                    TimSinhVien(svlist);
                }
                break;
        case 5:
                {
                    DiemTrungBinhLonHon_5(svlist);
                } 
                break;
        case 6:
                {
                    XuatDanhSachSV(svlist);
                }
                break;
        case 0: exit(1);
        } 
	}
    system("pause");
    return 0;
}
void menu_context()
{
	cout << "QUAN LY SINH VIEN\n";
	cout << "1. Nhap Danh Sach Sinh Vien.\n";
	cout << "2. Sua Thong Tin Sinh Vien.\n";
	cout << "3. Xoa Thong TIn Sinh Vien.\n";
	cout << "4. Tim Sinh Vien. \n";
	cout << "5. Danh Sach Sinh Vien DTB > 5.\n";
    cout << "6. Xuat Danh Sach Sinh Vien.\n";
	cout << "0. Thoat\n";
	cout << "moi nhap: ";
}
SVNode *CreateSVNode(string hoten,string mssv,float toan,float ly,float hoa){
    SVNode *p = new SVNode;
    if (p == NULL) exit(1);
    else
    {
        p->HoTen = hoten;
        p->MSSV = mssv;
        p->DiemToan = toan;
        p->DiemLy = ly;
        p->DiemHoa = hoa;
        p->pNext = NULL;
        p->pPrev = NULL;
    }
    return p;
}
void CreateSVList(SVLIST &svlist){
    svlist.pHead = NULL;
    svlist.pTail = NULL;
}
float DiemTrungBinh(SVNode SV){
    return (SV.DiemHoa + SV.DiemLy + SV.DiemToan)/3;
}
SVNode *NhapThongTinSV(){
    string hoten,mssv;
    float toan, ly, hoa;
    cin.ignore();
    cout << "nhap Ho Ten : ";
    getline(cin,hoten);
    cout << "nhap mssv : ";
    getline(cin,mssv);
    cout << "diem toan : ";
    cin >> toan;
    cout << "diem ly : ";
    cin >> ly;
    cout << "diem hoa : ";
    cin >> hoa;
    SVNode *SV = CreateSVNode(hoten,mssv,toan,ly,hoa);
    return SV;
}
void NhapDanhSachSV(SVLIST &svlist){
    int n; 
    SVNode *SV;
    string hoten,mssv;
    float toan, ly, hoa;
    cout << "nhap so luong sinh vien : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cout << "sinh vien thu #" << i+1 << " : \n";
        SV = NhapThongTinSV();
        addTail(svlist,SV);
    }
}
void addTail(SVLIST &svlist,SVNode *p)
{
    if (svlist.pHead == NULL)
    {
        svlist.pHead = p;
        svlist.pTail = svlist.pHead;
    }
    else
    {
        p->pPrev = svlist.pTail;
        svlist.pTail->pNext = p;
        svlist.pTail = p;
    }
}
void XuatThongTinSV(SVNode SV){
    cout << "ho ten sinh vien : " << SV.HoTen << "\n";
    cout << "mssv : " << SV.MSSV << "\n";
    cout << "Toan : " << SV.DiemToan << "\n";
    cout << "Ly : " << SV.DiemLy << "\n";
    cout << "Hoa : " << SV.DiemHoa << "\n";
    cout << "diem trung binh : " << DiemTrungBinh(SV) << "\n";
}
void XuatDanhSachSV(SVLIST svlist){
    SVNode *SV = svlist.pHead;
    while (SV != NULL)
    {
        XuatThongTinSV(*SV);
        SV = SV->pNext;
    }
    cout << "\n";
}
bool deletehead(SVList& svlist)
{
	SVNode *p;
    if(svlist.pHead != NULL)
    {
        p = svlist.pHead;
        svlist.pHead = svlist.pHead->pNext;
        
        if (svlist.pHead == NULL)
        {
            svlist.pTail = NULL;
        }
        else
        {
            svlist.pHead->pPrev = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
bool deletetail(SVList& svlist) 
{
	SVNode *p = svlist.pTail;
    if (svlist.pTail != NULL)
    {
        
        svlist.pTail = svlist.pTail->pPrev;
        svlist.pTail->pNext = NULL;
        delete p;
        if (svlist.pTail == NULL)
        {
            svlist.pHead = NULL;
        }
        return true;
    }
    return false;
}
void XoaThongTinSinhVien(SVList& svlist)
{
	int n;
	SVNODE* p = svlist.pHead;
	cout << "ban muon xoa sinh vien thu: ";
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		if (p != NULL)
			p = p->pNext;
	}
	if (p == NULL || n < 1)
		cout << "khong tim thay sinh vien" << endl;
	else
	{
		if (p == svlist.pHead)
			deletehead(svlist);
		else
		{
			if (p == svlist.pTail)
				deletetail(svlist);
			else
			{
				p->pPrev->pNext = p->pNext;
				p->pNext->pPrev = p->pPrev;
				delete(p);
			}
		}
	}
}
void TimSinhVien(SVList svlist)
{
	string maso;
	bool same;
	SVNODE* p;
	cout << "nhap ma so sinh vien can tim: ";
	cin >> maso;
	p = svlist.pHead;
	while (p != NULL)
	{
		if (p->MSSV == maso)
			XuatThongTinSV(*p);
		p = p->pNext;
	}
}
void DiemTrungBinhLonHon_5(SVList svlist)
{
	SVNODE* p;
	p = svlist.pHead;
    int k = 0;
	while (p != NULL)
	{
		if ((p->DiemHoa + p->DiemLy + p->DiemToan) / 3 > 5)
        {
            XuatThongTinSV(*p);
            k++;
        }	
		p = p->pNext;
	}
    if (k == 0)
    {
        cout << "khong co sinh vien co diem trung binh > 5. T.T \n";
    }
    
}
void SuaThongTinSinhVien(SVLIST& svlist)
{
	int n;
	SVNODE* p = svlist.pHead;
	cout << "ban muon sua thong tin sinh vien thu: ";
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		if (p!=NULL)
			p = p->pNext;
	}
	if (p == NULL || n < 1)
		cout << "khong tim thay sinh vien" << endl;
	else
	{
		cin.ignore();
		cout << "nhap ho ten: ";
		getline(cin, p->HoTen);
		cout << "nhap mssv: ";
		getline(cin, p->MSSV);
		cout << "nhap diem toan: ";
		cin >> p->DiemToan;
		cout << "nhap diem ly: ";
		cin >> p->DiemLy;
		cout << "nhap diem hoa: ";
		cin >> p->DiemHoa;
	}
}