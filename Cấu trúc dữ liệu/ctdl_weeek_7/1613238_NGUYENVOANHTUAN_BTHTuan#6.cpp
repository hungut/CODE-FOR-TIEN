#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef struct tagTREENODE{
    int Data;
    struct tagTREENODE *pLeft;
    struct tagTREENODE *pRight;
}TREENODE;
typedef TREENODE *TREE;
void CreateTree(TREE &T){
    T = NULL;
}
TREENODE *CrateTreeNode(int x){
    TREENODE *p = new TREENODE;
    if (p == NULL) exit(1);
    else
    {
        p->Data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
    }
    return p;    
}
int insertTreeNode(TREE &T,int x){
    if (T)
    {
        if (T->Data == x) return 0;
        if (T->Data > x) return insertTreeNode(T->pLeft,x);
        else return insertTreeNode(T->pRight,x);
    }
    T = new TREENODE;
    if (T == NULL) return -1;
    T->Data = x;
    T->pLeft = T->pRight = NULL;
    return 1;
}
TREENODE *searchTeeNode(TREE Root, int x){ 
    TREENODE *p = Root;
    while (p != NULL)
        { 
            if(x == p->Data) return p;
            else if(x < p->Data) p = p->pLeft;
                    else p = p->pRight;
        }
    return NULL;
}
TREENODE *SearchTNode_RECURSION(TREE T, int x){
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
void Replace(TREE &p, TREE &T){ 
    if(T->pLeft!=NULL) Replace(p,T->pLeft);
    else
    {
        p->Data = T->Data;
        p = T;
        T = T->pRight;
    }
}
void DeleteTreeNodeX(TREE &T,int x){
    if(T!=NULL)
    {
        if(T->Data < x) DeleteTreeNodeX(T->pRight,x);
        else
        {
            if(T->Data > x) DeleteTreeNodeX(T->pLeft,x);
            else //? found x
            { 
                TREENODE *p = T;
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
void LNR(TREE Root)
{
    if (Root != NULL)
    {
        LNR(Root->pLeft);
        cout << Root->Data << " ";
        LNR(Root->pRight);
    }
}
void LRN(TREE Root)
{
    if (Root != NULL)
    {
        LRN(Root->pLeft);
        LRN(Root->pRight);
        cout << Root->Data << " ";
    }
}
void NLR(TREE Root)
{
    if (Root != NULL)
    {
        cout << Root->Data << " ";
        NLR(Root->pLeft);
        NLR(Root->pRight);
    }
}
int main()
{
    TREE T;
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
                    TREENODE *p = searchTeeNode(T,x);
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
                    TREENODE *p = searchTeeNode(T,x);
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
                        TREENODE *p = searchTeeNode(T,arr[i]);
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