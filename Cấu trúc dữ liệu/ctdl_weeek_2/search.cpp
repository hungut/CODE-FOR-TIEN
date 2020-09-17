#include <iostream>
using namespace std;

int arrayInit(int arr[]){
    int n;
    cout << "input the array length : ";
    cin  >> n;
    for (int i = 0; i < n; i++){
        cout << "input array element " << i << " : ";
        cin >> arr[i];
    }
    return n;
}
void arrayPrint(int arr[],int N){
    cout << "printing array..... have length = "<< N << " \n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}
int linearSearch(int arr[],int N,int x){
    int i = 0;
    arr[N] = x;
    while(arr[i++]!= x){}
    if (i-1 == N)
    {
        return -1;
    }
    return i-1;
}
int binarySearch(int arr[],int N,int x){
    int l = 0,r = N-1;
    while (l <= r) { 
        int m = (l + r)/2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 

        else
            r = m - 1; 
    } 
    return -1; 
}
void context(){
    cout << "select method u want to use : \n" << "1/ Linar Search.\n" << "2/ Binary Search.\n" << "3/ Print array again.\n"<<"0/exit program.\n" << "pls select now . \n" << "method  = ";
}
int keySearch(){
    cout << "input searching key : ";
    int x;cin >> x;
    return x;
}
void checkRes(int res){
    if (res < 0) cout << "key not found.\n";
    else cout << "key has been found at position : " << res << " .\n";
}
void console(int arr[]){
    int N = arrayInit(arr);
    if(N){
        arrayPrint(arr,N);
        context();
        int method;
        cin >> method;
        while (method != 0){
                    if(method == 1){
                        checkRes(linearSearch(arr,N,keySearch()));
                    }
                    if(method == 2){
                        checkRes(binarySearch(arr,N,keySearch()));
                    }
                    if(method == 3){
                        arrayPrint(arr,N);
                    }
                    if(method != 0 && method != 1 && method != 2 && method !=3) cout << "pls retry again. \n";
                    if(method == 0){
                        cout << "exit program now. see you again.\n";
                        return;
                    }
                    context();
                    cin >> method;
                }
    }
}
int main()
{
    int arr[100];
    console(arr);
    system("pause");
    return 0;
}