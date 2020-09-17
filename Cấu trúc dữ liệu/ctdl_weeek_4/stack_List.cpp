#include <iostream>
using namespace std;

typedef struct tagNode
{
    int Data;
    struct tagNode *pNext;
}Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
}STACK;

Node *createNode(int x);
void createStack(STACK &s);
void makeStack(STACK &s);
bool isEmpty(STACK &s);
void Push(STACK &s,Node *p);
bool Pop(STACK &s,int &x);
int Top(STACK S);
void printStack(STACK s);
void menuContext();

int main()
{
    STACK s;
    createStack(s);
    Node *p;
    int temp = 0;
    int c = 1;
    while (c != 0)
    {
        menuContext();
        cin >> c;
        while ((c < 0) || (c > 5))
        {
            cout << "selection not found or update yet, pls choose again.\n";
            cout << "selection = ";
            cin >> c;
        }
        switch (c)
        {
        case 1:
                {
                    cout << "Prepare to make a new Stack.\n";
                    makeStack(s);
                }
            break;
        case 2:
                {
                    if (!isEmpty(s))
                    {
                        temp = Top(s);
                        cout << "the TOP is : " << temp << ".\n";
                    }
                    else
                    {
                        cout << "stack is empty.\n";
                    }   
                }
            break;
        case 4:
                {
                    cout << "Push a Node to TOP : ";
                    cin >> temp;
                    p = createNode(temp);
                    Push(s,p);
                    printStack(s);
                }
            break;
        case 3:
                {
                    if (Pop(s,temp))
                    {
                        cout << "Node " << temp << " has been pop from top"; 
                    }
                    else
                    {
                        cout << "Pop is failed.\n";
                    }
                    
                }
                break;
        case 5: 
                {
                    if (!isEmpty(s))
                    {
                        cout << "Stack : ";
                        printStack(s);
                    }
                    else
                    {
                        cout << "stack is empty.\n";
                    }
                }
            break;
        case 0: exit(1);
        }
    }
    system("pause");
    return 0;
}

Node *createNode(int x)
{
    Node *p;
    p = new Node;
    if (p == NULL) exit(1);
    p->Data = x;
    p->pNext = NULL;
    return p;
}
void printStack(STACK s)
{
    int x = 0;
    while (Pop(s,x))
    {
        cout << x << " ";
    }
    cout << "\n";
}
void makeStack(STACK &s)
{
    createStack(s);
    Node *p;
    int n;
    cout << "how many node u want to push to stack : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "input node #" << i+1 << " :";
        int temp;
        cin >> temp;
        p = createNode(temp);
        Push(s,p);
    }
}
void createStack(STACK &s)
{
    s.pHead = NULL;
    s.pTail = NULL;
}
bool isEmpty(STACK &s) 
{ 
    return s.pHead == NULL; 
}
void Push(STACK &s,Node *p)
{
    if (isEmpty(s))
    {
        s.pHead = p;
        s.pTail = p;
    }
    else
    {
       p->pNext = s.pHead;
       s.pHead = p;
    }
}
bool Pop(STACK &s,int &x)
{
    Node *p;
    if(!isEmpty(s))
    {
        p = s.pHead;
        x = p->Data;
        s.pHead = s.pHead->pNext;
        if (s.pHead == NULL)
        {
            s.pTail = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
int Top(STACK S)
{
    return S.pHead->Data;
}
void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. make a stack.\n";
    cout << "2. show the TOP.\n";
    cout << "3. POP the TOP.\n";
    cout << "4. PUSH a node to TOP.\n";
    cout << "5. is stack empty now?.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}