#include <iostream>
using namespace std; 
const int N = 50;
struct QUEUE
{
    int Arr[50];
    int Front;
    int Rear;
};
void createQueue(QUEUE &Q);
bool isFull(QUEUE Q);
bool isEmpty(QUEUE Q);
bool enQueue(QUEUE &Q,int x);
bool deQueue(QUEUE &Q,int &x);
int Front(QUEUE &Q);
int Size(QUEUE &Q);
void makeQueue(QUEUE &Q);
void printQueue(QUEUE Q);
void menuContext();
int main()
{
    QUEUE Q;
    createQueue(Q);
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
                        cout << "queue is empty.\n";
                    }   
                }
            break;
        case 4:
                {
                    cout << "enQueue a Node to Rear : ";
                    cin >> temp;
                    enQueue(Q,temp);
                    printQueue(Q);
                }
            break;
        case 3:
                {
                    if (deQueue(Q,temp))
                    {
                        cout << "Node " << temp << " has been pop from front"; 
                    }
                    else
                    {
                        cout << "deQueue is failed.\n";
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
                        cout << "queue is empty.\n";
                    }
                }
            break;
        case 6: 
                {
                    if (!isFull(Q))
                    {
                        cout << "Queue is not full yet.\n";
                    }
                    else
                    {
                        cout << "queue is full.\n";
                    }
                }
            break;
        case 7:
                {
                    if (!isEmpty(Q))
                    {
                        cout << "size : " << Size(Q) << "\n";
                    }
                    
                }
            break;
        case 0: exit(1);
        }
    }
    system("pause");
    return 0;
}
void createQueue(QUEUE &Q)
{
    Q.Front = -1;
    Q.Rear = -1;
}
void makeQueue(QUEUE &Q)
{
    createQueue(Q);
    int n;
    cout << "how many node u want to push to queue : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "input node #" << i+1 << " :";
        int temp;
        cin >> temp;
        enQueue(Q,temp);
    }
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
bool isEmpty(QUEUE Q)
{
    if (Q.Front == -1)
    {
        return true;
    }
    return false;

}
bool isFull(QUEUE Q)
{
    if (Q.Rear >= N)
    {
        return true;
    }   
    return false;

}
bool enQueue(QUEUE &Q,int x)
{
    int i,f,r;
    if (!isFull(Q))
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
bool deQueue(QUEUE &Q,int &x)
{
    if (!isEmpty(Q))
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
int Front(QUEUE &Q)
{
    return Q.Arr[Q.Front];
}
int Rear(QUEUE &Q)
{
    return Q.Arr[Q.Rear];
}
int Size(QUEUE &Q)
{
    return Q.Rear+1;
}
void menuContext()
{
    cout << "choose one of these selection:\n";
    cout << "1. make a queue.\n";
    cout << "2. show the Front.\n";
    cout << "3. POP the Front.\n";
    cout << "4. PUSH a node to Front.\n";
    cout << "5. is queue empty now?.\n";
    cout << "6. is queue full now?.\n";
    cout << "7. size of queue now.\n";
    cout << "0. exit.\n";
    cout << "selection = ";
}