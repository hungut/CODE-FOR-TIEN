#include "book.h"

class NOVEL : public BOOK
{
private:
    string author;
public:
    void Nhap();
    void Xuat();
    NOVEL();
    ~NOVEL();
};
