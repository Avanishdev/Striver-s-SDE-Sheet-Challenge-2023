#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* reverseLL(Node* head){
//base case
if(head==NULL || head->next==NULL){
    return head;
}
//head recursion
Node* newHead=reverseLL(head->next);
//ek case solve karo
head->next->next=head;
head->next=NULL;
return newHead;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=new Node();
    head->data=1;
    Node* two=new Node();
    two->data=2;
    head->next=two;
    Node* three=new Node();
    three->data=3;
    two->next=three;
    Node* four=new Node();
    four->data=4;
    three->next=four;
    Node* five=new Node();
    five->data=5;
    four->next=five;
    print(head);
    head=reverseLL(head);
    print(head);
    return 0;
}