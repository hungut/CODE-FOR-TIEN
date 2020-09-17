#include <ctime>
#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    cout << "input n : ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        // rand() % so cuoi + so dau
    }
    cout << "arr : ";
    for (int i = 0; i < n; i++)
    {
        cout << "["<< i << "]: " << arr[i] << ",";
    }
    return 0;
}
