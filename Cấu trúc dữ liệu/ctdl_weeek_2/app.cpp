#include <iostream>
using namespace std;
//***************************************************************************************************************************************
void swap (int *s,int *d);
//***************************************************************************************************************************************
int arrayInit(int arr[]);void arrayPrint(int arr[],int N);
//***************************************************************************************************************************************
int linearSearch(int arr[],int N,int x);
int binarySearch(int arr[],int N,int x);
int keySearch();void checkSearch(int res);
//***************************************************************************************************************************************
void interchangeSort(int a[],int n);
void selectionSort(int a[],int n);
void bubbleSort(int a[],int n);
void insertionSort(int a[],int n);
void quickSort(int a[],int l, int r);
//***************************************************************************************************************************************
void contxt_menu();
void main_menu(int arr[],int N);
void context_search();
void search_menu(int arr[],int N);
void context_sort();
void sort_menu(int arr[],int N);
//***************************************************************************************************************************************
int main(){
    int arr[100];
    int N = arrayInit(arr);
    main_menu(arr,N);
    system("pause");
    return 0;
}
//***************************************************************************************************************************************
void swap (int *s,int *d){
	 int t = *s;								
	 *s = *d;								
	 *d = t;								
}
//***************************************************************************************************************************************
int arrayInit(int arr[]){
    int n;
    cout << "input the array length : ";
    cin  >> n;
    for (int i = 0; i < n; i++){
        cout << "input array element " << i << " : ";
        cin >> arr[i];
    }
    arrayPrint(arr,n);
    return n;
}
void arrayPrint(int arr[],int N){
    cout << "printing array..... have length = "<< N << " \n";
    for (int stt = 0; stt < N; stt++) cout << stt << "\t";
    cout << "\n";
    for (int i = 0; i < N; i++) cout << arr[i] << "\t";
    cout << "\n";
}
//***************************************************************************************************************************************
int linearSearch(int arr[],int N,int x){
    int i = 0;
    while(arr[i++]){
        if (arr[i-1] == x){
            return i-1;
        }
    }
    return -1;
}
int binarySearch(int arr[],int N,int x){
    int l = 0,r = N-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 

        else
            r = m - 1; 
    } 
    return -1; 
}
int keySearch(){
    cout << "input searching key : ";
    int x;cin >> x;
    return x;
}
void checkSearch(int res){
    if (res < 0) cout << "key not found.\n";
    else cout << "key has been found at position : " << res << " .\n";
}
//***************************************************************************************************************************************
void interchangeSort(int a[],int n){
    cout << "using interchange sort method...... \n";
    for (int i = 0; i < n-1;i++)
		for (int j = i + 1; j < n;j++)
		if (a[i]>a[j])
			swap(a[i], a[j]);
    arrayPrint(a,n);
}
void selectionSort(int a[],int n){
    cout << "using selection sort method...... \n";
    for (int i = 0; i < n-1; i++)  
    {  
        int min = i;  

        for (int j = i+1; j < n; j++)  
            if (a[j] < a[min]) min = j;  

        swap(&a[min], &a[i]);  
    }
    arrayPrint(a,n);
}
void bubbleSort(int a[],int n){
    cout << "using bubble sort method...... \n";
    for (int i = 0; i < n-1; i++)      
        for (int j = n-1; j > i; j--)  
        if (a[j] < a[j-1])  
            swap(&a[j], &a[j-1]);  
    arrayPrint(a,n);
}
void insertionSort(int a[],int n){
    cout << "using insertion sort method...... \n";
    int i, key, pos;  
    for (i = 1; i < n; i++) 
    {  
        key = a[i];  
        pos = i - 1;  
        while (pos >= 0 && a[pos] > key) 
        {  
            a[pos + 1] = a[pos];  
            pos--; 
        }  
        a[pos + 1] = key;  
    }
    arrayPrint(a,n);
}
void quickSort(int a[],int l, int r){

    int i = l, j = r,x = a[(l+r)/2];
    do
    {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j)
        {
        swap(a[i],a[j]);
        i++ ; j--;
        }
    } while(i <= j);
    if(l<j)  quickSort(a, l, j);
    if(i<r)  quickSort(a, i, r);
}
//***************************************************************************************************************************************
void context_menu(){
    cout << "select mode u want to use : \n" 
        << "1/ Search mode.\n" 
        << "2/ Sort mode.\n"
        << "3/ Print array again.\n"
        << "0/exit program.\n" << "pls select now . \n" 
        << "mode  = ";
}
void main_menu(int arr[],int N){
    if(N){
        context_menu();
        int mode;
        cin >> mode;
        while (mode != 0){
            switch (mode)
            {
            case 0: cout << "exit program now. see you again.\n";
                return;
            case 1: search_menu(arr,N);
                break;
            case 2: sort_menu(arr,N);
                break;
            case 3: arrayPrint(arr,N);
                break;
            default: cout << "pls retry again. \n";
                break;
            }
            context_menu();
            cin >> mode;       
        }
    }
}
void context_search(){
    cout << "select mode u want to use : \n" 
        << "1/ Linar Search.\n" 
        << "2/ Binary Search.\n" 
        << "3/ Print array again.\n"
        << "0/ exit to main menu.\n" << "pls select now . \n" 
        << "mode  = ";
}
void search_menu(int arr[],int N){
    context_search();
    int search_mode;
    cin >> search_mode;
    while (search_mode != 0){
            switch (search_mode)
            {
            case 0: cout << "exitting to main menu........\n";
                return;
            case 1: checkSearch(linearSearch(arr,N,keySearch()));
                break;
            case 2: checkSearch(binarySearch(arr,N,keySearch()));
                break;
            case 3: arrayPrint(arr,N);
                break;
            default: cout << "pls retry again. \n";
                break;
            }
            context_search();
            cin >> search_mode;       
        }
}
void context_sort(){
    cout << "select mode u want to use : \n" 
        << "1/ Interchange Sort.\n" 
        << "2/ Selection Sort.\n" 
        << "3/ Bubble Sort.\n" 
        << "4/ Insertion Sort.\n" 
        << "5/ Quick Sort.\n" 
        << "6/ Print array again.\n"
        << "0/ exit to main menu.\n" << "pls select now . \n"
        << "mode  = ";
}
void sort_menu(int arr[],int N){
    context_sort();
    int sort_mode;
    cin >> sort_mode;
    while (sort_mode != 0){
            switch (sort_mode)
            {
            case 0: cout << "exitting to main menu........\n";
                return;
            case 1: interchangeSort(arr,N);
                break;
            case 2: selectionSort(arr,N);
                break;
            case 3: bubbleSort(arr,N);
                break;
            case 4: insertionSort(arr,N);
                break;
            case 5: { 
                cout << "using quick sort method...... \n";
                quickSort(arr,0,N-1); 
                arrayPrint(arr,N);
                } break;
            case 6: arrayPrint(arr,N);
                break;
            default: cout << "pls retry again. \n";
                break;
            }
            context_sort();
            cin >> sort_mode;       
        }
}
//***************************************************************************************************************************************
