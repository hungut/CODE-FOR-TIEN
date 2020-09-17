#include "book.h"

class SCHOOLBOOK : public BOOK
{
private:
    string publisher;
public:
    void Nhap();
    void Xuat();
    SCHOOLBOOK();
    ~SCHOOLBOOK();
};

