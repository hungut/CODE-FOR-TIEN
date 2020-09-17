#include <iostream>
using namespace std;

void swap (int *s,int *d){
	 int t = *s;								
	 *s = *d;								
	 *d = t;								
}
void arrayPrint(int arr[],int N){
    cout << "printing array..... have length = "<< N << " \n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n";
}
void interchangeSort(int a[],int n){
    cout << "using interchange sort method...... \n";
    for (int i = 0; i < n-1;i++)
		for (int j = i + 1; j < n;j++)
		if (a[i]>a[j])
			swap(a[i], a[j]);
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
}
void bubbleSort(int a[],int n){
    for (int i = 0; i < n-1; i++)      
        for (int j = n-1; j > i; j--)  
        if (a[j] < a[j-1])  
            swap(&a[j], &a[j-1]);  
}
void insertionSort(int a[],int n){
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
}
void quickSort(int a[],int l, int r){
    int i, j, x;
    x = a[(l+r)/2];
    i = l; j = r;
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
    if(i<r) quickSort(a, i, r);
}
int main()
{   
    const int N = 10;
    int a[N] = {11,21,13,47,25,64,27,83,39,101};
    arrayPrint(a,N);
    // interchangeSort(arr,N);
    // selectionSort(a,N);
    // bubbleSort(a,N);
    // insertionSort(a,N);
    quickSort(a,0,N-1);
    arrayPrint(a,N);
    system("pause");
    return 0;
}
