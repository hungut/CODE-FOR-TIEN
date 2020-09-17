#include <iostream>
using namespace std;
void swap (int *s,int *d){
	 int t = *s;								
	 *s = *d;								
	 *d = t;								
}
void arrayPrint(int arr[],int N){
    cout << "printing array..... have length = "<< N << " \n";
    for (int stt = 0; stt < N; stt++) cout << stt << "\t";
    cout << "\n";
    for (int i = 0; i < N; i++) cout << arr[i] << "\t";
    cout << "\n";
}
void quicksort(int a[], int left, int right)
{
    int i = left, j = right;
    int mid = a[(left + right) / 2];
    do
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j)
    {
        quicksort(a, left, j);
    }
    if (i < right)
    {
        quicksort(a, i, right);
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
int main(){
    int a[6] = {5,1,6,2,4,3};
    arrayPrint(a,6);
    quicksort(a,0,5);
    // quickSort(a,0,5);
    arrayPrint(a,6);
    system("pause");
    return 0;
}