#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class Queue
{
public:
    int count;
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }
    void push(int d)
    {
        Node *Temp;
        Temp = new Node(d);
        if (Temp == nullptr) // When heap exhausted
            cout << "Queue is Full" << endl;
        else
        {
            if (front == nullptr)
            {
                front = Temp;
                rear = Temp;
            }
            else
            {
                rear->next = Temp;
                rear = Temp;
            }
            cout << d << " Inserted into Queue " << endl;
            count++;
        }
    }
    void pop()
    {
        if (front == nullptr)
            cout << "Queue is Empty" << endl;
        else
        {
            cout << front->data << " Removed From Queue" << endl;
            Node *Temp = front;
            front = front->next;
            delete Temp;
            count--;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        return front->data;
    }
    // int Size()
    // {
    //     if (isEmpty())
    //     {
    //         return 0;
    //     }
    //     return (rear - front + 1);
    // }
    // void clear()
    // {
    //     if (isEmpty())
    //     {
    //         return;
    //     }
    //     while (front != NULL)
    //     {
    //         pop();
    //         front = front->next;
    //     }
    // }
    // bool isFull()
    // {
    //     return count == Size();
    // }
};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.top() << endl;
    return 0;
}