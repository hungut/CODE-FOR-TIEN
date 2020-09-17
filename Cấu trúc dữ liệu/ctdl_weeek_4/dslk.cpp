#include <iostream>
using namespace std;

typedef struct tagNode
{
    int Data;
    struct tagNode *pNext;
}Node;
// struct Node
// {
//     int Dat;
//     Node *pNext;
// };
typedef struct tagList
{
    Node *pHead;
    Node *pTail;
}LIST;
// struct LIST
// {
//     Node *pHead;
//     Node *pTail;
// };

Node *createNode(int x);
void createList(LIST &list);
void addHead(LIST &list,Node *p);
void addTail(LIST &list,Node *p);
void insertAfterQ(LIST &list,Node *q,Node *p);
void printList(LIST list);
void makeList(LIST &list);
Node *searchNode(LIST list,int x);
void removeList(LIST &list);
bool removeHead(LIST &list, int &x);
void menuContext();
void swapNode(Node &A,Node &B);
void selectionSort(LIST &list);
bool removeTail(LIST &list, int &x);
bool removeX(LIST &list,int x);
bool removeAfterQ(LIST &list,Node *q,int x);
void quickSort(LIST &lsit);


int main()
{
    LIST list;
    Node *p,*q;
    int c = 1;
    int temp = 0;
    createList(list);
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
                    cout << "Prepare to make a new list.\n";
                    makeList(list);
                }
            break;
        case 2:
                {
                    cout << "add a node at head : ";
                    cin >> temp;
                    p = createNode(temp);
                    addHead(list,p);
                    printList(list);
                }
            break;
        case 3:
                {
                    cout << "add a node at tail : ";
                    cin >> temp;
                    p = createNode(temp);
                    addTail(list,p);
                    printList(list);
                }
            break;
        case 4:
                {
                    cout << "choose a node : ";
                    cin >> temp;
                    q = searchNode(list,temp);
                    if (q != NULL)
                    {
                        cout << "add a node after node [" << q->Data << "] : ";
                        cin >> temp;
                        p = createNode(temp);
                        insertAfterQ(list,q,p);
                        printList(list);
                    }
                    else
                    {
                        cout << "node not exist. \n";
                    }
                }
                break;
        case 5: 
                {
                    cout << "list : ";
                    printList(list);
                }
            break;
        case 6:
                {
                    if (removeHead(list,temp))
                    {
                        cout << "head [" << temp << "] removed.\n";
                    }
                    else
                    {
                        cout << "list is NULL.\n";
                    }
                }
            break;
        case 7: 
                {
                    if (removeTail(list,temp))
                    {
                        cout << "tail [" << temp << "] removed.\n";
                    }
                    else
                    {
                        cout << "list is NULL.\n";
                    }
                }
            break;
        case 8:
                {
                    cout << "choose a numbber : ";
                    cin >> temp;
                    if (removeX(list,temp))
                    {
                        cout << temp << " has been remove.\n";
                    }
                    else
                    {
                        cout << temp << " not in the list.\n";
                    }
                }
            break;
        case 9: removeList(list);
            break;
        case 10: selectionSort(list);
            break;
        case 11:
                {
                    cout << "input x : ";
                    int x;
                    cin >> x;
                    p = searchNode(list,x);
                    if(p != NULL)
                    {
                        cout << "x is available.\n";
                    }
                    else
                    {
                        cout << "x is not found.\n";
                    }
                    
                }
            break;
        case 666: 
                {
                    cout << "using quick sort method on this list...... \n";
                    quickSort(list);
                    cout << "sorting is done...... \n";
                }
            break;
        case 0: break;
        }
    }
    delete p,q;
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
void makeList(LIST &list)
{
    createList(list);
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
        addTail(list,p);
    }
}
void createList(LIST &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}
void addHead(LIST &list,Node *p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
        list.pTail = list.pHead;
    }
    else
    {
        p->pNext = list.pHead;
        list.pHead = p; 
    }
}
void addTail(LIST &list,Node *p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
        list.pTail = list.pHead;
    }
    else
    {
        list.pTail->pNext = p;
        list.pTail = p;
    }
}
void insertAfterQ(LIST &list,Node *q,Node *p)
{
    if(q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if(list.pTail == q)
        {
            list.pTail = p;
        }
    }
    else
    {
        addHead(list,p);
    } 
}
void printList(LIST list)
{
    Node *p;
    p = list.pHead;
    while (p != NULL)
    {
        cout << p->Data
 << " ";
        p = p->pNext;
    }
    cout << "\n";
}
Node *searchNode(LIST list,int x)
{
    Node *p;
    p = list.pHead;
    while(p != NULL && p->Data != x)
    {
        p = p->pNext;
    }
    return p;
}
void removeList(LIST &list)
{
    Node *p;
    while (list.pHead != NULL)
    {
        p = list.pHead;
        list.pHead = p->pNext;
        delete p;
    }
}
bool removeHead(LIST &list, int &x)
{
    Node *p;
    if(list.pHead != NULL)
    {
        p = list.pHead;
        x = p->Data;
        list.pHead = list.pHead->pNext;
        delete p;
        if (list.pHead == NULL)
        {
            list.pTail = NULL;
        }
        return true;
    }
    return false;
}
bool removeTail(LIST &list, int &x)
{
    Node *p = list.pHead;
    while (p->pNext != list.pTail)
    {
        p = p->pNext;
    }
    if (list.pTail != NULL)
    {
        x = list.pTail->Data;
        list.pTail = p;
        list.pTail->pNext = NULL;
        return true;
    }
    return false;
}
bool removeAfterQ(LIST &list,Node *q)
{
    Node *p;
    if (q != NULL)
    {
        p = q->pNext;
        if(p != NULL)
        {
            if (p == list.pTail)
            {
                list.pTail = q;
            }
            q->pNext = p->pNext;
            delete p;
            return true;
        }
    }
    return false;    
}
bool removeX(LIST &list,int x)
{
    Node *p = list.pHead;
    Node *q = NULL;
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
        removeAfterQ(list,q);
    }
    else
    {
        removeHead(list,x);
    }
    return true;
}
void selectionSort(LIST &list)
{
    cout << "using selection sort method on this list...... \n";
    Node *p;
    p = list.pHead;
    while (p != NULL)
    {
        Node *min = p;
        Node *q = p->pNext;
        while(q != NULL)
        {
            if (min->Data > q->Data) 
                min = q; 
            q = q->pNext; 
        }
        swapNode(*min,*p);
             
        p = p->pNext;
    }
    cout << "sorting is done...... \n";
}
void swapNode(Node &A,Node &B)
{
    int x = A.Data;
    A.Data = B.Data;
    B.Data = x; 
}

void quickSort(LIST &list)
{
    Node *p,*Hold;
    LIST L1,L2;
    if (list.pHead == list.pTail)
    {
        return;
    }
    createList(L1);
    createList(L2);
    Hold =  list.pHead;
    list.pHead = Hold->pNext;
    while (list.pHead != NULL) //! divine list into L1 and L2
    {
        p = list.pHead;
        list.pHead = p->pNext;
        p->pNext = NULL;
        if (p->Data <= Hold->Data)
        {
            addHead(L1,p);
        }
        else
        {
            addHead(L2,p);
        }
    }
        quickSort(L1);
        quickSort(L2);
        if (L1.pHead != NULL)
        {
            list.pHead = L1.pHead;
            L1.pTail->pNext = Hold;
        }
        else
        {
            list.pHead = Hold;
        }
        Hold->pNext = L2.pHead;
        if (L2.pHead != NULL)
        {
            list.pTail = L2.pTail;
        }
        else
        {
            list.pTail = Hold;
        }                           
}

void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. create a list.\n";
    cout << "2. add at the head of the list.\n";
    cout << "3. add at the tail of the list.\n";
    cout << "4. add at a specific node of the list.\n";
    cout << "5. show full list.\n";
    cout << "6. remove head of the list.\n";
    cout << "7. remove tail of the list.\n";
    cout << "8. remove X from the list.\n";
    cout << "9. remove full list.\n";
    cout << "10. use Select Sort on this list.\n";
    cout << "11. search for X on this list.\n";
    cout << "666. use Quick Sort on this list.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}