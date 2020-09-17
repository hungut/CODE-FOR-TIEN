#include <iostream>
using namespace std; 
const int N = 50;
struct STACK
{
    int Arr[50];
    int Top;
};
void createStack(STACK &S);
bool isFull(STACK S);
bool isEmpty(STACK S);
bool Push(STACK &S,int x);
bool Pop(STACK &S,int &x);
int Top(STACK &S);
int Size(STACK &S);
void makeStack(STACK &S);
void printStack(STACK S);
void menuContext();
int main()
{
    STACK S;
    createStack(S);
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
                    makeStack(S);
                }
            break;
        case 2:
                {
                    if (!isEmpty(S))
                    {
                        temp = Top(S);
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
                    Push(S,temp);
                    printStack(S);
                }
            break;
        case 3:
                {
                    if (Pop(S,temp))
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
                    if (!isEmpty(S))
                    {
                        cout << "Stack : ";
                        printStack(S);
                    }
                    else
                    {
                        cout << "stack is empty.\n";
                    }
                }
            break;
        case 6: 
                {
                    if (!isFull(S))
                    {
                        cout << "Stack is not full yet.\n";
                    }
                    else
                    {
                        cout << "stack is full.\n";
                    }
                }
            break;
        case 7:
                {
                    if (!isEmpty(S))
                    {
                        cout << "size : " << Size(S) << "\n";
                    }
                    
                }
            break;
        case 0: exit(1);
        }
    }
    system("pause");
    return 0;
}
void createStack(STACK &S)
{
    S.Top = -1;
}
void makeStack(STACK &S)
{
    createStack(S);
    int n;
    cout << "how many node u want to push to stack : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "input node #" << i+1 << " :";
        int temp;
        cin >> temp;
        Push(S,temp);
    }
}
void printStack(STACK S)
{
    int x = 0;
    while (Pop(S,x))
    {
        cout << x << " ";
    }
    cout << "\n";
}
bool isEmpty(STACK S)
{
    if (S.Top == -1)
    {
        return true;
    }
    return false;

}
bool isFull(STACK S)
{
    if (S.Top >= N)
    {
        return true;
    }   
    return false;

}
bool Push(STACK &S,int x)
{
    if (!isFull(S))
    {
        S.Top++;
        S.Arr[S.Top] = x;
        return true;
    }
    return false;
}
bool Pop(STACK &S,int &x)
{
    if (!isEmpty(S))
    {
        x = S.Arr[S.Top];
        S.Top = S.Top - 1;
        return true;
    }
    return false;
}
int Top(STACK &S)
{
    return S.Arr[S.Top];
}
int Size(STACK &S)
{
    return S.Top+1;
}
void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. make a stack.\n";
    cout << "2. show the TOP.\n";
    cout << "3. POP the TOP.\n";
    cout << "4. PUSH a node to TOP.\n";
    cout << "5. is stack empty now?.\n";
    cout << "6. is stack full now?.\n";
    cout << "7. size of stack now.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}