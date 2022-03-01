#include<iostream>
using namespace std;

class node{
public:
   int data;
   node*next;
   node(int d){
      data=d;
      node*next= NULL;
   }
};
void insertAt(node*&head, int data){
   node*n= new node(data);
   n->next= head;
   head= n;
}
bool searchSequential(node*head,int key){
   if(head==NULL){
      return false;
   }
   if(head->data==key){
      return true;
   }
   else{
      return searchSequential(head->next, key);
   }
}
void printNode(node*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
int main(){
   node*head= NULL;
   insertAt(head,10);
   insertAt(head,9);
   insertAt(head,8);
   insertAt(head,7);
   insertAt(head,6);
   printNode(head);
   if(searchSequential(head,4)){
      cout<<"Is found"<<endl;
   }
   else{
      cout<<"Is not found"<<endl;
   }
}
