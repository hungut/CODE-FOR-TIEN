#include <iostream>
#include <cstdlib>
#include <ctime>
#define LH -1   //left tree is higher
#define EH 0    //equal
#define RH 1    //Right tree is hgiher

using namespace std;
typedef struct tagAVLNODE{
    char balFactor;
    int Data;
    struct tagAVLNODE *pLeft;
    struct tagAVLNODE *pRight;
}AVLNODE;
typedef AVLNODE *AVLTREE;
void CreateTree(AVLTREE &T){
    T = NULL;
}
AVLNODE *CrateTreeNode(int x){
    AVLNODE *p = new AVLNODE;
    if (p == NULL) exit(1);
    else
    {
        p->Data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;    
}
int insertTreeNode(AVLTREE &T,int x){
    if (T)
    {
        if (T->Data == x) return 0;
        if (T->Data > x) return insertTreeNode(T->pLeft,x);
        else return insertTreeNode(T->pRight,x);
    }
    T = new AVLNODE;
    if (T == NULL) return -1;
    T->Data = x;
    T->pLeft = T->pRight = NULL;
    return 1;
}
AVLNODE *searchTeeNode(AVLTREE Root, int x){ 
    AVLNODE *p = Root;
    while (p != NULL)
        { 
            if(x == p->Data) return p;
            else if(x < p->Data) p = p->pLeft;
                    else p = p->pRight;
        }
    return NULL;
}
AVLNODE *SearchTNode_RECURSION(AVLTREE T, int x){
    if(T!=NULL)
    {
        if(T->Data == x) return T;
        else
        if( x > T->Data)
        return SearchTNode_RECURSION(T->pRight,x);
    else
    return SearchTNode_RECURSION(T->pLeft,x);
    }
    return NULL;
}
void Replace(AVLTREE &p, AVLTREE &T){ 
    if(T->pLeft!=NULL) Replace(p,T->pLeft);
    else
    {
        p->Data = T->Data;
        p = T;
        T = T->pRight;
    }
}
void DeleteTreeNodeX(AVLTREE &T,int x){
    if(T!=NULL)
    {
        if(T->Data < x) DeleteTreeNodeX(T->pRight,x);
        else
        {
            if(T->Data > x) DeleteTreeNodeX(T->pLeft,x);
            else //? found x
            { 
                AVLNODE *p = T;
                if (T->pLeft==NULL) T = T->pRight;
                else
                { if(T->pRight==NULL) T=T->pLeft;
                else Replace(p, T->pRight);//! found tree on right side
            }
            delete p;
            }
        }
    }
    else cout << "x is not found, can't remove\n";
}
void LNR(AVLTREE Root)
{
    if (Root != NULL)
    {
        LNR(Root->pLeft);
        cout << Root->Data << " ";
        LNR(Root->pRight);
    }
}
void LRN(AVLTREE Root)
{
    if (Root != NULL)
    {
        LRN(Root->pLeft);
        LRN(Root->pRight);
        cout << Root->Data << " ";
    }
}
void NLR(AVLTREE Root)
{
    if (Root != NULL)
    {
        cout << Root->Data << " ";
        NLR(Root->pLeft);
        NLR(Root->pRight);
    }
}
void LL(AVLTREE &T){
    AVLNODE *T1 = T->pLeft;
    T->pLeft = T1->pRight;
    T1->pRight = T;
    switch (T->balFactor)
    {
    case LH:{T->balFactor = EH; T1->balFactor = EH;}
        break;
    
    case EH:{T->balFactor = LH; T1->balFactor = RH;}
        break;
    }
    T = T1;
}
void RR(AVLTREE &T){
    AVLNODE *T1 = T->pRight;
    T->pRight = T1->pLeft;
    T1->pLeft = T;
    switch (T->balFactor)
    {
    case RH:{T->balFactor = EH; T1->balFactor = EH;}
        break;
    
    case EH:{T->balFactor = RH; T1->balFactor = LH;}
        break;
    }
    T = T1;
}
void LR(AVLTREE &T){
    AVLNODE *T1 = T->pLeft;
    AVLNODE *T2 = T1->pRight;
    T->pLeft = T2->pRight;
    T2->pRight = T;;
    T1->pRight = T2->pLeft;
    T2->pLeft = T1;
    switch (T2->balFactor)
    {
    case LH:{T->balFactor = RH;T1->balFactor = EH;}
        break;
    
    case EH:{T->balFactor = EH;T1->balFactor = EH;}
        break;
    case RH:{T->balFactor = EH;T1->balFactor = LH;}
        break;
    }
    T2->balFactor = EH;
    T = T2;
}
void RL(AVLTREE &T){
    AVLNODE *T1 = T->pRight;
    AVLNODE *T2 = T1->pLeft;
    T->pRight = T2->pLeft;
    T2->pLeft = T;;
    T1->pLeft = T2->pRight;
    T2->pRight = T1;
    switch (T2->balFactor)
    {
    case LH:{T->balFactor = EH;T1->balFactor = RH;}
        break;
    
    case EH:{T->balFactor = EH;T1->balFactor = EH;}
        break;
    case RH:{T->balFactor = LH;T1->balFactor = EH;}
        break;
    }
    T2->balFactor = EH;
    T = T2;
}

int main()
{
    AVLTREE T;
    CreateTree(T);
    srand(time(NULL));
    cout << "how many leaf on tree : ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        insertTreeNode(T,arr[i]);
    }
    cout << "arr : ";
    for (int i = 0; i < n; i++)
    {
        cout << "["<< i << "]: " << arr[i] << ",";
    }
    cout << "\n";
    int c= 1;
    cout << "select mode : \n";
    cout << "1. search node.\n";
    cout << "2. delete node.\n";
    cout << "3. check tree.\n";
    cout << "4. LNR tree.\n";
    cout << "5. LRN tree.\n";
    cout << "6. NLR tree.\n";
    cout << "0.exit \n";
    while (c != 0)
    { 
        cout << "select : ";
        cin >> c;
        switch (c)
        {
        case 1:
                {
                    int x;
                    cout << "input x to search: ";
                    cin >> x; 
                    AVLNODE *p = searchTeeNode(T,x);
                    if (p != NULL)
                    {
                        cout << "found " << p->Data << "\n";
                    }
                    else
                    {
                        cout << "not found " << x << "\n";
                    }
                }
            break;
        case 2: 
                {
                    int x;
                    cout << "input x to delete: ";
                    cin >> x;
                    AVLNODE *p = searchTeeNode(T,x);
                    if (p != NULL)
                    {
                        DeleteTreeNodeX(T,x);
                        cout << "deleted " << x << "\n";
                        
                    }
                    else
                    {
                        cout << "not found " << x << "to delete.\n";
                    }
                }
            break;
        case 3:
                {
                    cout << "check full tree : \n";
                    for (int i = 0; i < n; i++)
                    {
                        AVLNODE *p = searchTeeNode(T,arr[i]);
                        if (p != NULL)
                        {
                        cout << "found " << p->Data << "\n";
                        }
                        else
                        {
                            cout << "not found " << arr[i] << "\n";
                        }
                    }
                }
            break;
        case 4:
                {
                    LNR(T);
                    cout << "\n";
                }
            break;
        case 5:
                {
                    LRN(T);
                    cout << "\n";
                }
            break;
        case 6:
                {
                    NLR(T);
                    cout << "\n";
                }
            break;
        case 0: exit(1);
        }
    }
    
    system("pause");
    return 0;
}