#include <iostream>

#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;
    ifstream FileIn;
    FileIn.open(argv[1]);
    int n;
    FileIn >> n;
    cout << n << "\n";
    int *arr = new int[n];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        FileIn >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << max << "\n";
    delete arr;
    FileIn.close();
    return 0;
}