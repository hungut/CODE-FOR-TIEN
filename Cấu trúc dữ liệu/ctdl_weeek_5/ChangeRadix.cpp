#include <iostream>
#include <math.h>
using namespace std;
const int N=20;
struct STACK
{
    int Arr[N];
    int Top;
};
void createStack(STACK &S);
bool isFullStack(STACK S);
bool isEmptyStack(STACK S);
bool Push(STACK &S,int x);
bool Pop(STACK &S,int &x);
int Size(STACK &S);
void menu_context();
int main()
{
    int x, sur;
    int temp;
	STACK S;
	createStack(S);
	int c = 1;
	while (c != 0)
	{
        cout << "input a decimal number (<1.000.000.000) :";
	    cin >> x;
        menu_context();
		cout << "pls select : ";
		cin >> c;
		while (c < 0 || c > 2)
		{
			cout << "pls select again: ";
			cin >> c;
		}
		switch (c)
		{
		case 1: 
				{
					int temp2 = x;
					cout << "bianry :  ";
					while (temp2 != 0)
					{
						sur = temp2 % 2;
						Push(S, sur);
						temp2 = temp2 / 2;
					}
					while (!isEmptyStack(S))
					{
                        if (Pop(S,temp))
                        {
                            cout << temp;
                        }
                    }
					createStack(S);
                    cout << "\n";
				}
			break;
		case 2:
				{
					cout << "octo : ";
					while (x != 0)
					{
						sur = x % 8;
						Push(S, sur);
						x = x / 8;
					}
					while (!isEmptyStack(S))
					{
                        if (Pop(S,temp))
                        {
                            cout << temp;
                        }
                    }
					createStack(S);
                    cout << "\n";
				}
			break;
		case 0:
			cout << "exting.........\n";
			exit(1);
		}
	}
    system("pause");
    return 0;
}
void createStack(STACK &S)
{
    S.Top = -1;
}
bool isEmptyStack(STACK S)
{
    if (S.Top == -1)
    {
        return true;
    }
    return false;

}
bool isFullStack(STACK S)
{
    if (S.Top >= N)
    {
        return true;
    }   
    return false;

}
bool Push(STACK &S,int x)
{
    if (!isFullStack(S))
    {
        S.Top++;
        S.Arr[S.Top] = x;
        return true;
    }
    return false;
}
bool Pop(STACK &S,int &x)
{
    if (!isEmptyStack(S))
    {
        x = S.Arr[S.Top];
        S.Top = S.Top - 1;
        return true;
    }
    return false;
}
int Size(STACK &S)
{
    return S.Top+1;
}
void menu_context()
{
	cout << "1. to Binary\n";
	cout << "2. to Octo\n";
	cout << "0. exit\n";
}