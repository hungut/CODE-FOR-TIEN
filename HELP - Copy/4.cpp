#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s= to_string(n);
   stack<char>S;
   for(int i=0;i<s.size();i++) S.push(s[i]);
   while(S.empty()==false){
       cout<<S.top();
       S.pop();
   }
   return 0;
}