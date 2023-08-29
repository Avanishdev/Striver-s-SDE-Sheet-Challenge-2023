#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
};
void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode *addLL(ListNode *first, ListNode *second)
{
    // creating dummy node
    ListNode *newHead = new ListNode();
    ListNode *temp = newHead; // temp pointing on dummy node initially
    int carry = 0;
    // dono equal ho to
    while (first != NULL && second != NULL)
    {
        int sum = first->data + second->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode();
        newNode->data = digit;
        temp->next = newNode;
        temp = newNode;
        first = first->next;
        second = second->next;
    }
    // first bada ho to
    while (first != NULL)
    {
        int sum = first->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode();
        newNode->data = digit;
        temp->next = newNode;
        temp = newNode;
        first = first->next;
    }
    // second bada ho to
    while (second != NULL)
    {
        int sum = second->data + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode();
        newNode->data = digit;
        temp->next = newNode;
        temp = newNode;
        second = second->next;
    }
    // carry baccha ho to
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode *newNode = new ListNode();
        newNode->data = digit;
        temp->next = newNode;
        temp = newNode;
    }
    return newHead->next;
}
int main()
{
    ListNode *first = new ListNode();
    first->data = 2;
    ListNode *two = new ListNode();
    two->data = 4;
    first->next = two;
    ListNode *three = new ListNode();
    three->data = 3;
    two->next = three;

    ListNode *second = new ListNode();
    second->data = 5;
    ListNode *node2 = new ListNode();
    node2->data = 6;
    second->next = node2;
    ListNode *node3 = new ListNode();
    node3->data = 4;
    node2->next = node3;

    // print(first);
    // print(second);
    first=addLL(first, second);
    print(first);
    return 0;
}