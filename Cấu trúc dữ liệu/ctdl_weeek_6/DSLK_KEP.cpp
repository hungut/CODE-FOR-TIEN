#include <iostream>
using namespace std;

typedef struct tagNode
{
    int Data;
    struct tagNode *pNext;
    struct tagNode *pPrev;
}DNode;

typedef struct tagList
{
    DNode *pHead;
    DNode *pTail;
}DLIST;

DNode *createNode(int x);
void createList(DLIST &dlist);
void addHead(DLIST &dlist,DNode *p);
void addTail(DLIST &dlist,DNode *p);
void insertAfterQ(DLIST &dlist,DNode *q,DNode *p);
void insertBeforeQ(DLIST &dlist,DNode *q,DNode *p);
void printList(DLIST dlist);
void makeList(DLIST &dlist);
DNode *searchNode(DLIST dlist,int x);
void removeList(DLIST &dlist);
bool removeHead(DLIST &dlist, int &x);
void menuContext();
bool removeTail(DLIST &dlist, int &x);
bool removeX(DLIST &dlist,int x);
bool removeAfterQ(DLIST &dlist,DNode *q,int x);
bool removeBeforerQ(DLIST &dlist,DNode *q);

int main()
{
    DLIST dlist;
    DNode *p,*q;
    int c = 1;
    int temp = 0;
    createList(dlist);
    while (c != 0)
    {
        menuContext();
        cin >> c;
        while ((c < 0) || (c > 11) && c!= 666)
        {
            cout << "selection not found or update yet, pls choose again.\n";
            cout << "selection = ";
            cin >> c;
        }
        switch (c)
        {
        case 1:
                {
                    cout << "Prepare to make a new dlist.\n";
                    makeList(dlist);
                }
            break;
        case 2:
                {
                    cout << "add a node at head : ";
                    cin >> temp;
                    p = createNode(temp);
                    addHead(dlist,p);
                    printList(dlist);
                }
            break;
        case 3:
                {
                    cout << "add a node at tail : ";
                    cin >> temp;
                    p = createNode(temp);
                    addTail(dlist,p);
                    printList(dlist);
                }
            break;
        case 4:
                {
                    cout << "choose a node : ";
                    cin >> temp;
                    q = searchNode(dlist,temp);
                    if (q != NULL)
                    {
                        cout << "add a node after node [" << q->Data << "] : ";
                        cin >> temp;
                        p = createNode(temp);
                        insertAfterQ(dlist,q,p);
                        printList(dlist);
                    }
                    else
                    {
                        cout << "node not exist. \n";
                    }
                }
                break;
        case 5: 
                {
                    cout << "dlist : ";
                    printList(dlist);
                }
            break;
        case 6:
                {
                    if (removeHead(dlist,temp))
                    {
                        cout << "head [" << temp << "] removed.\n";
                    }
                    else
                    {
                        cout << "dlist is NULL.\n";
                    }
                }
            break;
        case 7: 
                {
                    if (removeTail(dlist,temp))
                    {
                        cout << "tail [" << temp << "] removed.\n";
                    }
                    else
                    {
                        cout << "dlist is NULL.\n";
                    }
                }
            break;
        case 8:
                {
                    cout << "choose a numbber : ";
                    cin >> temp;
                    if (removeX(dlist,temp))
                    {
                        cout << temp << " has been remove.\n";
                    }
                    else
                    {
                        cout << temp << " not in the dlist.\n";
                    }
                }
            break;
        case 9: removeList(dlist);
            break;
        // case 10: selectionSort(dlist);
        //     break;
        // case 11:
        //         {
        //             cout << "input x : ";
        //             int x;
        //             cin >> x;
        //             p = searchNode(dlist,x);
        //             if(p != NULL)
        //             {
        //                 cout << "x is available.\n";
        //             }
        //             else
        //             {
        //                 cout << "x is not found.\n";
        //             }
                    
        //         }
        //     break;
        // case 666: 
        //         {
        //             cout << "using quick sort method on this dlist...... \n";
        //             quickSort(dlist);
        //             cout << "sorting is done...... \n";
        //         }
        //     break;
        case 0: break;
        }
    }
    delete p,q;
    system("pause");
    return 0;
}
DNode *createNode(int x)
{
    DNode *p;
    p = new DNode;
    if (p == NULL) exit(1);
    p->Data = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}
void makeList(DLIST &dlist)
{
    createList(dlist);
    DNode *p;
    int n;
    cout << "input n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "input node #" << i+1 << " :";
        int temp;
        cin >> temp;
        p = createNode(temp);
        addTail(dlist,p);
    }
}
void createList(DLIST &dlist)
{
    dlist.pHead = NULL;
    dlist.pTail = NULL;
}
void addHead(DLIST &dlist,DNode *p)
{
    if (dlist.pHead == NULL)
    {
        dlist.pHead = p;
        dlist.pTail = dlist.pHead;
    }
    else
    {
        p->pNext = dlist.pHead;
        dlist.pHead->pPrev = p; 
        dlist.pHead = p;
    }
}
void addTail(DLIST &dlist,DNode *p)
{
    if (dlist.pHead == NULL)
    {
        dlist.pHead = p;
        dlist.pTail = dlist.pHead;
    }
    else
    {
        p->pPrev = dlist.pTail;
        dlist.pTail->pNext = p;
        dlist.pTail = p;
    }
}
void insertAfterQ(DLIST &dlist,DNode *q,DNode *p)
{
    DNode *r = q->pNext;
    if(q != NULL)
    {
        p->pNext = r;
        p->pPrev = q;
        q->pNext = p;
        if(r != NULL)
        {
            r->pPrev = p;
        }
        if (q == dlist.pTail)
        {
            dlist.pTail = p;
        }
        
    }
    else
    {
        addHead(dlist,p);
    } 
}
void insertBeforeQ(DLIST &dlist,DNode *q,DNode *p)
{
    DNode *r = q->pPrev;
    if(q != NULL)
    {
        p->pNext = r;
        q->pPrev = p;
        p->pPrev = r;
        if(r != NULL)
        {
            r->pPrev = p;
        }
        if (q == dlist.pTail)
        {
            dlist.pHead = p;
        }
        
    }
    else
    {
        addTail(dlist,p);
    } 
}
void printList(DLIST dlist)
{
    DNode *p;
    p = dlist.pHead;
    while (p != NULL)
    {
        cout << p->Data << " ";
        p = p->pNext;
    }
    cout << "\n";
}
DNode *searchNode(DLIST dlist,int x)
{
    DNode *p;
    p = dlist.pHead;
    while(p != NULL && p->Data != x)
    {
        p = p->pNext;
    }
    return p;
}
void removeList(DLIST &dlist)
{
    DNode *p;
    while (dlist.pHead != NULL)
    {
        p = dlist.pHead;
        dlist.pHead = p->pNext;
        delete p;
    }
}
bool removeHead(DLIST &dlist, int &x)
{
    DNode *p;
    if(dlist.pHead != NULL)
    {
        p = dlist.pHead;
        dlist.pHead = dlist.pHead->pNext;
        x = p->Data;
        
        if (dlist.pHead == NULL)
        {
            dlist.pTail = NULL;
        }
        else
        {
            dlist.pHead->pPrev = NULL;
        }
        delete p;
        return true;
    }
    return false;
}
bool removeTail(DLIST &dlist, int &x)
{
    DNode *p = dlist.pTail;
    if (dlist.pTail != NULL)
    {
        x = dlist.pTail->Data;
        dlist.pTail = dlist.pTail->pPrev;
        dlist.pTail->pNext = NULL;
        delete p;
        if (dlist.pTail == NULL)
        {
            dlist.pHead = NULL;
        }
        return true;
    }
    return false;
}
bool removeAfterQ(DLIST &dlist,DNode *q)
{
    DNode *p;
    if (q != NULL)
    {
        p = q->pNext;
        if(p != NULL)
        {
            q->pNext = p->pNext;
            if (p == dlist.pTail)
            {
                dlist.pTail = q;
            }
            else
            {
                p->pNext->pPrev = q;
            }
            
            delete p;
            return true;
        }
    }
    return false;    
}
bool removeBeforerQ(DLIST &dlist,DNode *q)
{
    DNode *p;
    if (q != NULL)
    {
        p = q->pPrev;
        if(p != NULL)
        {
            q->pPrev = p->pPrev;
            if (p == dlist.pHead)
            {
                dlist.pHead = q;
            }
            else
            {
                p->pPrev->pNext = q;
            }
            
            delete p;
            return true;
        }
    }
    return false;    
}
bool removeX(DLIST &dlist,int x)
{
    DNode *p = dlist.pHead;
    DNode *q = NULL;
    while (p != NULL && p->Data != x)
    {
        q = p;
        p = p->pNext;
    }
    
    if(p == NULL)
    {
        return false;
    }
    if (q != NULL)
    {
        removeAfterQ(dlist,q);
    }
    else
    {
        removeHead(dlist,x);
    }
    return true;
}


void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. create a dlist.\n";
    cout << "2. add at the head of the dlist.\n";
    cout << "3. add at the tail of the dlist.\n";
    cout << "4. add at a specific node of the dlist.\n";
    cout << "5. show full dlist.\n";
    cout << "6. remove head of the dlist.\n";
    cout << "7. remove tail of the dlist.\n";
    cout << "8. remove X from the dlist.\n";
    // cout << "9. remove full dlist.\n";
    // cout << "10. use Select Sort on this dlist.\n";
    // cout << "11. search for X on this dlist.\n";
    // cout << "666. use Quick Sort on this dlist.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}