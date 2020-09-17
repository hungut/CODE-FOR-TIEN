#include <iostream>

using namespace std;

void func(int a = 0,int b = 1){
    cout << a << "\t" << b << "\n";
}

 int main()
 {
    // cout << "good morning OPP! \n";
    // FILE *f1  = fopen("intput.txt","r+");
    // FILE *f2  = fopen("output.txt","w+");
    // cout << "inputing......\n";
    // int a[4]={};
    // for (int i = 0; i < 4; i++)
    // {
    //     fscanf(f1,"%d",&a[i]);
    //     fprintf(f2,"%d \n",a[i]);
    // }
    // fclose(f1);
    // fclose(f2);
    // cout << "done input to output.txt.\n";
    //tham số mặc nhiên
    int x = 10,y=20;
    func(x,y);
    func(x);
    func(0,y);
    func();
    system("pause");
    return 0;
 }