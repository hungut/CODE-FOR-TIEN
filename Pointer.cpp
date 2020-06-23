#include <iostream>
#include <string.h>
using namespace std;
void removeLastSubString(char *str,char *sub){
	char *sub1;
	sub1=strstr(str,sub);
	if(sub1!=NULL){
	int n=0;
	do{
		n=strlen(sub1);
		sub1=strstr(sub1+2,sub);
	}
	while(sub1!=NULL);
	int i=strlen(str)-n;
	int j=0;
	for(j=i;j<strlen(str);j++){
		str[j]=str[j+strlen(sub)];
	}
}
}
int main(){
	char str1[200]="con ong lam mat yeu hoa, con ca yeu nuoc con chim ca yeu troi. Con nguoi muon song con oi, phai yeu dong chi yeu nguoi anh em.";
	char str2[200]="nguoi con";
	 removeLastSubString(str1, str2);
  cout << str1 << endl;
  return 0;
}


//******************--------------------------------------------------**********************//
#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int** a)
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			ifs >> a[i][j];
			if (a[i][j] == 0) {
				for (int b = j; b < 10; b++)
					a[i][b] = 0;
			}
			if (a[i][j] == 0) j = 9;
		}
	}
	
}
void printArray(int** a)
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (j != 9)
				cout << a[i][j] << " ";
			if (j == 9) cout << a[i][j];
		}
		cout << endl;
	}
}
int main(int narg, char** argv)
{


	int** arr;
	arr = new int* [10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = new int[10];
	}

	readArray(arr);
	printArray(arr);

	for (int i = 0; i < 10; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


	return 0;
}
