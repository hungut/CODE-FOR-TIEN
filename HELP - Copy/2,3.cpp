#include<iostream>
using namespace std;
struct node{
    int data;
    node*next;
    node*pre;
};
struct douList{
    node*head;
    node*tail;
};
//create each Node
douList *CreateList(int x){
    douList*p=new douList;
    p->head=new node;
    p->head->data=x;
    p->head->next=NULL;
    p->head->pre=NULL;
    p->tail=p->head;
    return p;
}
//add to the top of Linked List(equal same direction with stack,queue)
douList *addHead(douList*p,int x){
   node*temp=new node;
   temp->data=x;
   temp->pre=NULL;
   temp->next=p->head;
   p->head->pre=temp;
   p->head=temp;
   return p;
}
//add to bottom of Linked List(equal different direction with stack,queue)
douList *addTail(douList*p,int x){
    node*temp=new node;
    temp->data=x;
    temp->next=NULL;
    temp->pre=p->tail;
    p->tail->next=temp;
    p->tail=temp;
    return p;
}
//Delete first element of Linked List
douList *pop(douList*p){
  node*b=p->tail;
  p->head=p->head->next;
  while(b->pre!=NULL){
      b=b->pre;
  }
  b->pre=NULL;
  return p;
}

int top(douList*p){
   return p->head->data;
}
//#1# print from Head
void printList_fromHead(douList*p){
    node*q=p->head;
    while(q!=NULL){
        cout<<q->data<<" ";
         q=q->next;
    }
};
//#2# print from Tail
void printList_fromTail(douList*p){
     node*q=p->tail;
     while(q!=NULL){
         cout<<q->data<<" ";
         q=q->pre;
     } 
};
int main(){
    int n,x1;
    cin>>n;
    cin>>x1;
    douList*List=CreateList(x1);
    for(int i=1;i<n;i++){
        cin>>x1;
        List=addTail(List,x1);
    }
    //printList_fromTail(List);
    printList_fromHead(List);
    cout<<endl;
    //cout<<top(List);
    List=pop(List);
     printList_fromHead(List);
     return 0;
}