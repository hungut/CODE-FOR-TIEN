#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
vector<vector<int>>Arrayindex(vector<vector<int>>A){
    int size=A[0].size();
    vector<vector<int>>Array;
    
   vector<int>V=A[0];
 sort( V.begin(),V.end(), [&](int i,int j){return A[1][i]>A[1][j];} );//sort index giam dan
   Array.push_back(V);
   ///
   vector<int>B=A[1];
    sort(B.begin(),B.end(),greater<int>());//sort values
   Array.push_back(B);
    return Array;//tra ve mang 2 chieu :hàng 1 là array value;hàng 2 là array index:))
}
int main(){
    int n;
    cin>>n;
 vector<vector<int>>A(2,vector<int>(n+1,0));
 for(int i=0;i<2;i++){
     for(int j=0;j<n+1;j++) cin>>A[i][j];
 }
 A=Arrayindex(A);
  for(int i=0;i<A[0].size();i++){
       cout<<A[0][i]<<" ";
   }
   cout<<endl;
    for(int i=0;i<A[0].size();i++){
       cout<<A[1][i]<<" ";
   }
}