#include <iostream>
#include <math.h>
using namespace std;
//declare structed datatype struct Fraction. 
struct Fraction
{
    int iNumerator;     //numerator of fraction known as Tu So.
    int iDenominator;   //denominator of fraction known as Mau So.
    float fValue;       //real value of fraction.
};
//functions declared for initializing fractions and show it on terminal.
Fraction initFraction(Fraction *f,int iNumer,int iDenomin);
void valueFraction(Fraction *f);
void showFraction(Fraction f);
void showAllFraction(Fraction f[],int n);
int inputFraction(Fraction f[]);
//functions declareed for compact function
int GCD(int x, int y);
void compactFraction(Fraction *f);
//functions declared for compare 2 fractions
void compareFraction(Fraction A,Fraction B);
//functions declared to do math on 2 specific fractions
Fraction sum2Fraction(Fraction A,Fraction B);
Fraction subtract2Fraction(Fraction A,Fraction B);
Fraction multiply2Fraction(Fraction A,Fraction B);
Fraction quotient2Fraction(Fraction A,Fraction B);

int main()
{
    Fraction F[10];
    int n = inputFraction(F);
    showAllFraction(F,n);
    compareFraction(F[0],F[1]);
    Fraction F_SUM = sum2Fraction(F[0],F[1]);
    Fraction F_SUBTRACT = subtract2Fraction(F[0],F[1]);
    Fraction F_MULTIPLIES = multiply2Fraction(F[0],F[1]);
    Fraction F_QUOTIENT = quotient2Fraction(F[0],F[1]);
    system("pause");
    return 0;
}
//? initFraction, initializing a Fraction and also compact that Fraction then set (float) value for it.
Fraction initFraction(Fraction *f,int iNumer,int iDenomin)
{
    f->iDenominator = iDenomin;
    f->iNumerator = iNumer;
    compactFraction(f);
    valueFraction(f);
    return *f;
}
//! set (float) value for a fraction.
void valueFraction(Fraction *f)
{
    f->fValue = (float)f->iNumerator/(float)f->iDenominator;
}
//! show to terminal one specific fraction.
void showFraction(Fraction f)
{
    if (f.iDenominator == 1)
    {
        cout << f.fValue << "\n";
    }
    else
    {
        cout << f.iNumerator << " / " << f.iDenominator << "\n";
    }
}
//! show all the fractions in faction arry f[].
void showAllFraction(Fraction f[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Fraction #" << i+1 << " : ";
        showFraction(f[i]);
        valueFraction(f);
        cout << "value = " << f->fValue << "\n";
    }
}
//? input fractions in fraction array f[]
//! this function will ask your to input number "n" as the quantity of fractions for the fraction array f[].
//! normally just input n as 2.
//! return n as the length of fraction array f[] and also the quantity of fractions.
int inputFraction(Fraction f[])
{
    int n;
    cout << "how many fractions you want to input : ";
    cin >> n;
    int numeratorOf_Fraction,denominatorOf_Fraction;
    for (int i = 0; i < n; i++)
    {
        cout << "fraction #" << i+1 << " :\n";
        cout << "input numerator of fraction : ";
        cin >> numeratorOf_Fraction;
        cout << "input denominator of fraction : ";
        cin >> denominatorOf_Fraction;
        f[i] = initFraction(&f[i],numeratorOf_Fraction,denominatorOf_Fraction);
    }
    return n;
}
//? greatest common disivor of x and y
int GCD(int x, int y)
{
    int t;
    while(y != 0) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}
//? compact a specific fraction
void compactFraction(Fraction *f)
{
    int fractionGCD = GCD(abs(f->iDenominator),abs(f->iNumerator));
    f->iDenominator /= fractionGCD;
    f->iNumerator   /= fractionGCD;
}
//? compare 2 specific fractions
void compareFraction(Fraction A,Fraction B)
{
    valueFraction(&A);
    valueFraction(&B);
    if (A.fValue == B.fValue)
        cout << "these 2 fractions is equal.\n";
    else
        if (A.fValue > B.fValue)
        {
            showFraction(A);
            cout << "is bigger than\n";
            showFraction(B);
        }
        else
        {
            showFraction(B);
            cout << "is bigger than\n";
            showFraction(A);
        }
}
//? return a fraction that equal to sum of 2 specific fractions
Fraction sum2Fraction(Fraction A,Fraction B)
{
    Fraction sum = initFraction(&sum,A.iNumerator*B.iDenominator + B.iNumerator*A.iDenominator,A.iDenominator*B.iDenominator);
    cout << " SUM OF ";
    showFraction(A);
    cout << " AND ";
    showFraction(B);
    cout << " = ";
    showFraction(sum);
    return sum;
}
//? return a fraction that equal to subtract of 2 specific fractions
Fraction subtract2Fraction(Fraction A,Fraction B)
{
    Fraction subt = initFraction(&subt,A.iNumerator*B.iDenominator - B.iNumerator*A.iDenominator,A.iDenominator*B.iDenominator);
    cout << " SUBTRACT OF ";
    showFraction(A);
    cout << " AND ";
    showFraction(B);
    cout << " = ";
    showFraction(subt);
    return subt;
}
//? return a fraction that equal to multiply of 2 specific fractions
Fraction multiply2Fraction(Fraction A,Fraction B)
{
    Fraction multip = initFraction(&multip,A.iNumerator*B.iNumerator,A.iDenominator*B.iDenominator);
    cout << " MULTIPLIES OF ";
    showFraction(A);
    cout << " AND ";
    showFraction(B);
    cout << " = ";
    showFraction(multip);
    return multip;
}
//? return a fraction that equal to fraction A / fraction B
Fraction quotient2Fraction(Fraction A,Fraction B)
{
    Fraction quot = initFraction(&quot,A.iNumerator*B.iDenominator,A.iDenominator*B.iNumerator);
    cout << " QUOTiENT OF ";
    showFraction(A);
    cout << " AND ";
    showFraction(B);
    cout << " = ";
    showFraction(quot);
    return quot;
}