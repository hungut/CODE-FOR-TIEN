#include <iostream>
#include <string>
using namespace std;
const int N = 50;
struct QUEUE
{
    char Arr[50];
    int Front;
    int Rear;
};
void createQueue(QUEUE &Q);
bool isFullQueue(QUEUE Q);
bool isEmptyQueue(QUEUE Q);
bool enQueue(QUEUE &Q,char x);
bool deQueue(QUEUE &Q,char &x);
struct STACK
{
    char Arr[50];
    int Top;
};
void createStack(STACK &S);
bool isFullStack(STACK S);
bool isEmptyStack(STACK S);
bool Push(STACK &S,char x);
bool Pop(STACK &S,char &x);
int main()
{
    string Chuoi;
    STACK S; createStack(S);
    QUEUE Q; createQueue(Q);
    cout << "input string : ";
    getline(cin, Chuoi);
    for (int i = 0; i < Chuoi.length(); i++)
    {
        Push(S,Chuoi[i]);
        enQueue(Q,Chuoi[i]);
    }
    int count = 0;
    char a,b;
    while (Pop(S,a) && deQueue(Q,b))
    {
        if (a != b)
        {
            cout << "Not Palindrome. \n";
            break;
        }
        else
        {
            count++;
        }
    }
    if (count == Chuoi.length())
    {
        cout << "this is a Palindrome.\n";
    }
    
    system("pause");
    return 0;
}
void createQueue(QUEUE &Q)
{
    Q.Front = -1;
    Q.Rear = -1;
}
bool isEmptyQueue(QUEUE Q)
{
    if (Q.Front == -1)
    {
        return true;
    }
    return false;

}
bool isFullQueue(QUEUE Q)
{
    if (Q.Rear >= N)
    {
        return true;
    }   
    return false;

}
bool enQueue(QUEUE &Q,char x)
{
    int i,f,r;
    if (!isFullQueue(Q))
    {
        if (Q.Front == -1)
        {
            Q.Front = 0;
            Q.Rear = -1;
        }
        if (Q.Rear == N-1)
        {
            f = Q.Front;
            r = Q.Rear;
            for (i = f; i < r; i++)
            {
                Q.Arr[i-f]=Q.Arr[i];
            }
            Q.Front = 0;
            Q.Rear = r-f;            
        }
        Q.Rear++;
        Q.Arr[Q.Rear] = x;
        return true;
    }
    return false;
}
bool deQueue(QUEUE &Q,char &x)
{
    if (!isEmptyQueue(Q))
    {
        x = Q.Arr[Q.Front];
        Q.Front++;
        if (Q.Front > Q.Rear)
        {
            Q.Front = -1;
            Q.Rear = -1;
        }
        return true;       
    }
    return false;
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
bool Push(STACK &S,char x)
{
    if (!isFullStack(S))
    {
        S.Top++;
        S.Arr[S.Top] = x;
        return true;
    }
    return false;
}
bool Pop(STACK &S,char &x)
{
    if (!isEmptyStack(S))
    {
        x = S.Arr[S.Top];
        S.Top = S.Top - 1;
        return true;
    }
    return false;
}

