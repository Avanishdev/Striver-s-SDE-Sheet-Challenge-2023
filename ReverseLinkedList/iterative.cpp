#include<iostream>
using namespace std;
struct ListNode{
int data;
ListNode* next;
};
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* left=NULL;
        ListNode* curr=head;
        ListNode* right=NULL;
        while(curr!=NULL){
            right=curr->next;//store karra liya taki link na tote
            curr->next=left;

            left=curr;
            curr=right;//right=curr->next eventually
        }
        return left;
    }
};
void print(ListNode* &head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Solution obj;
    ListNode* head=new ListNode();
    head->data=3;
    ListNode* second=new ListNode();
    second->data=6;
    head->next=second;
    ListNode* third=new ListNode();
    third->data=8;
    second->next=third;
    ListNode* fourth=new ListNode();
    fourth->data=10;
    third->next=fourth;
    print(head);
    obj.reverseList(head);
    print(head);
    return 0;
}