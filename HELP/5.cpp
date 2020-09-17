#include<iostream>
using namespace std;
class Sophuc{
    float phanthuc;
    float phanao;
    public:
    Sophuc(){};
    Sophuc(float x,float y){
        this->phanthuc=x;
        this->phanao=y;
    }
    Sophuc operator+(Sophuc);
    Sophuc operator-(Sophuc);
    Sophuc operator*(Sophuc);
    Sophuc operator/(Sophuc);
    void print(){
        if(phanao>0)
      cout<<this->phanthuc<<"+"<<this->phanao<<"i"<<endl;
      else
      {
         cout<<this->phanthuc<<"+"<<"("<<this->phanao<<")"<<"i"<<endl;
      }
    }
};
Sophuc Sophuc::operator+(Sophuc A){
     return Sophuc(phanthuc+A.phanthuc,phanao+A.phanao);
}
Sophuc Sophuc::operator-(Sophuc A){
     return Sophuc(phanthuc-A.phanthuc,phanao-A.phanao);
}
Sophuc Sophuc::operator*(Sophuc A){
     return Sophuc(phanthuc*A.phanthuc-phanao*A.phanao,phanthuc*A.phanao+phanao*A.phanthuc);
}
Sophuc Sophuc::operator/(Sophuc A){
     return Sophuc((phanthuc*A.phanthuc+phanao*A.phanao)/(A.phanthuc*A.phanthuc+A.phanao*A.phanao),(-phanthuc*A.phanao+phanao*A.phanthuc)/(A.phanthuc*A.phanthuc+A.phanao*A.phanao));
}
int main(){
    Sophuc A(2,3),B(4,5);
    Sophuc C,D,E,F;
    C=A+B;C.print();
    D=A-B;D.print();
    E=A*B;E.print();
    F=A/B;F.print();
    return 0;
}
