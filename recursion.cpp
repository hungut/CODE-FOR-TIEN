/*#include <iostream>
#include <fstream>
using namespace std;
int* removeElement(int *a, int &n, int position){

    
     a[position] = a[position+1];
   if(position>=n){
   	n--;
   	return a;
   }
   if(position<n)
   return removeElement(a,n,position+1);
    
}
int main(){
int *a=new int[30]{1, -1 ,121, -211, 19, 14 ,-101 ,431 ,911, 101, 0, -1, 121, -211 ,19, 0 ,-1090, 499 ,951, 1120, 13 ,-112, 121, -21111, 139, 0 ,-110 ,4 ,9 ,10};
int N=30;
int* newA = removeElement(a, N, 19);
		for(int i = 0; i < N; i++) {
			cout << newA[i] << " ";
		}
return 0;
}*/

//-------------------------------------------//
 /*#include <iostream>

#include <string.h>

using namespace std;
int linearSearch(int *a, int key, int sizeofArray){

if(sizeofArray == 0 ) return -1;
if(a[sizeofArray-1] == key) return sizeofArray-1;
else
{
	return linearSearch(a,key,sizeofArray-1);
}

}
int main(){
int *a=new int[30]{1, -1 ,121, -211, 19, 14 ,-101 ,431 ,911, 101, 0, -1, 121, -211 ,19, 0 ,-1090, 499 ,951, 1120, 13 ,-112, 121, -21111, 139, 0 ,-110 ,4 ,9 ,10};
int N=30,M=27;
cout<<linearSearch(a,M,N);

}*/



