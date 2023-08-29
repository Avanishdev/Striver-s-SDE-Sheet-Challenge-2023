#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        next = NULL;
    }
};
class Stack
{
public:
    Node *head;
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(int d)
    {
        // creating newNode with data d
        Node *newNode = new Node(d);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            return;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        head = head->next;
        return;
    }
    int top()
    {
        return head->data;
    }
    int size()
    {
        int count = 0;
        Node *temp = head;
        while (!isEmpty())
        {
            count++;
            pop();
        }
        return count;
    }
    void clear()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            pop();
            temp = temp->next;
        }
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.isEmpty() << endl;
    // cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    // s.clear();
    // cout << s.size() << endl;
    return 0;
}