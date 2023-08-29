// front%size Or rear%size because array is rotating
#include <iostream>
using namespace std;
class Queue
{
public:
    int size;
    int count;
    int front;
    int rear;
    int *arr;
    Queue(int capacity)
    {
        count = 0;
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int d)
    {
        if (count == size)
        {
            return;
        }
        else if (count < size)
        {
            arr[rear % size] = d;
            rear++;
            count++;
        }
    }
    int pop()
    {
        if (count == 0)
        {
            return -1;
        }
        int x = arr[front % size];
        arr[front % size] = -1;
        front++;
        count--;
        return x;
    }
    int top()
    {
        if (count == 0)
        {
            return -1;
        }
        return arr[front % size];
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == size;
    }
    int Size()
    {
        return count;
    }
    void clear()
    {
        while (count != 0)
        {
            pop();
        }
    }
};

int main()
{
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.top() << endl;
    cout << q.pop() << " poped out" << endl;
    cout << q.Size() << endl;
    q.push(10);
    cout << q.top() << endl;
    cout << q.Size() << endl;
    q.clear();
    cout << q.Size() << endl;
    return 0;
}

