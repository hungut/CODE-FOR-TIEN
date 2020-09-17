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
}QUEUE;

Node *createNode(int x);
void createQueue(QUEUE &Q);
void makeQueue(QUEUE &Q);
void enQueue(QUEUE &Q,Node *p);
bool deQueue(QUEUE &Q,int &x);
bool isEmpty(QUEUE &Q);
void printQueue(QUEUE Q);
int Front(QUEUE Q);
void menuContext();

int main()
{
    QUEUE Q;
    createQueue(Q);
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
                    cout << "Prepare to make a new Queue.\n";
                    makeQueue(Q);
                }
            break;
        case 2:
                {
                    if (!isEmpty(Q))
                    {
                        temp = Front(Q);
                        cout << "the Front is : " << temp << ".\n";
                    }
                    else
                    {
                        cout << "Queue is empty.\n";
                    }   
                }
            break;
        case 4:
                {
                    cout << "enQueue a Node to Front : ";
                    cin >> temp;
                    p = createNode(temp);
                    enQueue(Q,p);
                    printQueue(Q);
                }
            break;
        case 3:
                {
                    if (deQueue(Q,temp))
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
                    if (!isEmpty(Q))
                    {
                        cout << "Queue : ";
                        printQueue(Q);
                    }
                    else
                    {
                        cout << "Queue is empty.\n";
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
void printQueue(QUEUE Q)
{
    int x = 0;
    while (deQueue(Q,x))
    {
        cout << x << " ";
    }
    cout << "\n";
}
void makeQueue(QUEUE &Q)
{
    createQueue(Q);
    Node *p;
    int n;
    cout << "input n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "input node #" << i+1 << " :";
        int temp;
        cin >> temp;
        p = createNode(temp);
        enQueue(Q,p);
    }
}
void createQueue(QUEUE &Q)
{
    Q.pHead = NULL;
    Q.pTail = NULL;
}
void enQueue(QUEUE &Q,Node *p)
{
    if (isEmpty(Q))
    {
        Q.pHead = p;
        Q.pTail = Q.pHead;
    }
    else
    {
        Q.pTail->pNext = p;
        Q.pTail = p;
    }
}
bool deQueue(QUEUE &Q,int &x)
{
    Node *p;
    if(!isEmpty(Q))
    {
        p = Q.pHead;
        x = p->Data;
        Q.pHead = Q.pHead->pNext;
        if (Q.pHead == NULL)
        {
            Q.pTail = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
bool isEmpty(QUEUE &Q) 
{ 
    return Q.pHead == NULL; 
}
int Front(QUEUE Q)
{
    return Q.pHead->Data;
}
void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. make a queue.\n";
    cout << "2. show the FRONT.\n";
    cout << "3. DeQueue.\n";
    cout << "4. EnQueue a node in the Queue.\n";
    cout << "5. is Queue empty now?.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}