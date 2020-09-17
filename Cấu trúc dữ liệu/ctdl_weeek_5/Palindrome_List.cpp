#include <iostream>
#include <string>
using namespace std;
typedef struct tagNode
{
    char Data;
    struct tagNode *pNext;
}Node;
Node *createNode(char x);
struct STACK
{
    Node *pTop;
    Node *pBot;
};
void createStack(STACK &s);
bool isEmptyStack(STACK &s);
void Push(STACK &s,char x);
bool Pop(STACK &s,char &x);
struct QUEUE
{
    Node *pFront;
    Node *pRear;
};
void createQueue(QUEUE &Q);
void enQueue(QUEUE &Q,char x);
bool deQueue(QUEUE &Q,char &x);
bool isEmptyQueue(QUEUE &Q);
int main()
{
    string Chuoi;
    STACK S; 
    createStack(S);
    QUEUE Q; 
    createQueue(Q);
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
Node *createNode(char x)
{
    Node *p;
    p = new Node;
    if (p == NULL) exit(1);
    p->Data = x;
    p->pNext = NULL;
    return p;
}
void createStack(STACK &s)
{
    s.pTop = NULL;
    s.pBot = NULL;
}
bool isEmptyStack(STACK &s) 
{ 
    return s.pTop == NULL; 
}
void Push(STACK &s,char x)
{
    Node *p = createNode(x);
    if (isEmptyStack(s))
    {
        s.pTop = p;
        s.pBot = p;
    }
    else
    {
       p->pNext = s.pTop;
       s.pTop = p;
    }
}
bool Pop(STACK &s,char &x)
{
    Node *p;
    if(!isEmptyStack(s))
    {
        p = s.pTop;
        x = p->Data;
        s.pTop = s.pTop->pNext;
        if (s.pTop == NULL)
        {
            s.pBot = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
void createQueue(QUEUE &Q)
{
    Q.pFront = NULL;
    Q.pRear = NULL;
}
void enQueue(QUEUE &Q,char x)
{
    Node *p = createNode(x);
    if (isEmptyQueue(Q))
    {
        Q.pFront = p;
        Q.pRear = Q.pFront;
    }
    else
    {
        Q.pRear->pNext = p;
        Q.pRear = p;
    }
}
bool deQueue(QUEUE &Q,char &x)
{
    Node *p;
    if(!isEmptyQueue(Q))
    {
        p = Q.pFront;
        x = p->Data;
        Q.pFront = Q.pFront->pNext;
        if (Q.pFront == NULL)
        {
            Q.pRear = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
bool isEmptyQueue(QUEUE &Q) 
{ 
    return Q.pFront == NULL; 
}