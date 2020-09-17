#include <iostream>
using namespace std;
struct Date
{
    int Day;
    int Month;
    int Year;
};
void initDate(Date& D);
Date indicateNextDate(Date D);
Date testDay30(Date D);
Date testDay31(Date D);
void showDate(Date D);
int main()
{
    Date D;
    initDate(D);
    showDate(D);
    cout << "the next day is  \n";
    D = indicateNextDate(D);
    showDate(D);
    system("pause");
    return 0;
}
void initDate(Date& D)
{
    cout << "day : ";
	cin >> D.Day;
	cout << "month : ";
	cin >> D.Month;
    cout << "year : ";
	cin >> D.Year;
}
Date testDay31(Date D)
{
    if (D.Day == 31)
        {
            D.Day = 1;
            D.Month++;
        }
        else
        {
            D.Day ++;
        }
    return D;
}
Date testDay30(Date D)
{
    if (D.Day == 30)
        {
            D.Day = 1;
            D.Month++;
        }
        else
        {
            D.Day ++;
        }
    return D;
}
Date indicateNextDate(Date D)
{   
    switch (D.Month)
    {
        case 1: D = testDay31(D);
            break;
        case 3: D = testDay31(D);
            break;
        case 5: D = testDay31(D);
            break;
        case 7: D = testDay31(D);
            break;
        case 8: D = testDay31(D);
            break;
        case 10: D = testDay31(D);
            break;
        case 12: D = testDay31(D);
            break;
        case 4: D = testDay30(D);
            break;
        case 6: D = testDay30(D);
            break;
        case 9: D = testDay30(D);
            break;
        case 11: D = testDay30(D);
            break;
    }
    if (D.Month == 2 && D.Day == 29)
    {
        D.Day = 1;
        D.Month++;
    }   
    if ((D.Year % 4 == 0 ) && D.Month == 2 && D.Day == 28)
    {
        D.Day = 1;
        D.Month++;
    }
    return D;
}
void showDate(Date D)
{
    cout << D.Day << " / " << D.Month << " / " << D.Year << "\n";
}