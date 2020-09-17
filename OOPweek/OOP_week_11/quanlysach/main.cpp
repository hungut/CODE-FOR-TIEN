#include "magazine.h"
#include "novel.h"
#include "schoolbook.h"

void inputBooks(BOOK *B[],int &n);

void showBooks(BOOK *B[]);

int main()
{
    BOOK *B[50];
    int n;
    inputBooks(B,n);
    showBooks(B);
    return 0;
}
void inputBooks(BOOK *B[],int &n){
    cout << "how many books to input : ";
    cin >> n;
    int c = 1;
    for (int i = 0; i < n;i++){
    cout << "select kind of books : \n";
    cout << "1. Magazine.\n";
    cout << "2. Novel.\n";
    cout << "3. School book.\n";
    cout << "select : ";
    cin >> c;
        switch (c)
        {
            case 1:
                {
                    B[i] = new MAGAZINE;
                    B[i]->Nhap();     
                }
                break;
            case 2: 
                {
                    B[i] = new NOVEL;
                    B[i]->Nhap();
                }
                break;
            case 3:
                {
                    B[i] = new SCHOOLBOOK;
                    B[i]->Nhap();
                }
                break;
        }
    }
}
void showBooks(BOOK *B[]){
    int i = 0;
    while (B[i++])
    {
        B[i-1]->Xuat();
    }
}