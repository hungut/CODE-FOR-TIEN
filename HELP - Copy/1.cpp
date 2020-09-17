#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
};
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* addNode(node*head,int x){
    node*temp=new node;
    node*p=head;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL) head=temp;
    else{
        while(p->next!=NULL){
            p=p->next;
        } 
       p->next=temp;
    }
     return head;
}
int Search(node*head,int k){
    node*p=head;
    int i=0,m;
    if(k==0) m=p->data;
    else{
    while(i!=k-1){
        p=p->next;
        i++;
    }
    m=p->next->data;
    }
    return m;
}
node*convert(node*head,int n,int a,int b){
    node*p=head;
    while(p!=NULL){
        if(p->data==a){
            p->data=b;
        }
        p=p->next;
    }
    return head;
}
node*deleteBigger(node*head,int k){
    node*p=head;node*q=NULL;
    int a=Search(head,k);
    while(p!=NULL){
        if(p->data<=a){
           q=addNode(q,p->data);
        }
        p=p->next;
    }
    return q;
}
node*delete_at_Head(node *head){
    node*p=head;
    p=p->next;
    //delete(head);??==head=NULL;
    return p;
}
node*delete_at_Tail(node*head){
    node*p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    p->next=NULL;
    return head;
}
node* deleleNode(node*head,int k){
    node*p=head;
    if(k==0) head=delete_at_Head(head);
    else
    {
        int count=0;
        while(count!=k-1){
            p=p->next;
            count++;
        }
        node*temp=p->next;
      p->next=p->next->next;
      temp=NULL;//delete(temp);
    }
    return head;
}
int main(){
    int n,x,k;
    cin>>n;
    node*head=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        head=addNode(head,x);
    }
    cin>>k;
    //head=delete_at_Head(head);
    //head=deleleNode(head,k);
    //head=delete_at_Tail(head);
    //head=convert(head,n,a,b);
    head=deleteBigger(head,k);
    print(head);
    //Search(head,k);
}