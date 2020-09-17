#include "book.h"

class MAGAZINE : public BOOK
{
private:
    int publishDate;
public:
    void Nhap();
    void Xuat();
    MAGAZINE();
    ~MAGAZINE();
};