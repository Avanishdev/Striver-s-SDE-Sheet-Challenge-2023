#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
Node* findMiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(slow!=NULL&&fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
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
    Node* mid=findMiddle(head);
    print(mid);
    return 0;
}