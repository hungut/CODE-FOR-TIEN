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
int IsPriority(char p);
string InFix_To_PostFix(string exp);
int CheckBracket(char *b);
int main()
{
    system("pause");
    return 0;
}
string InFix_To_PostFix(string exp)
{
    STACK S;
    string PostFix = "";
    return PostFix;
}
int IsPriority(char p)
{
    if (p == '+' || p == '-')
    {
        return 1;
    }
    if (p == '*' || p == '/')
    {
        return 2;
    }
    if (p == '^')
    {
        return 3;
    }
    return 0;
}
//! ***********************************************************************************************
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