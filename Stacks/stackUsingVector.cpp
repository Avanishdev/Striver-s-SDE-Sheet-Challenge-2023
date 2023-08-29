#include <iostream>
#include <vector>
using namespace std;
class Stack
{
public:
    int top;
    int data;
    vector<int> arr;
    Stack()
    {
        top = -1;
    }
    void push(int data)
    {
        top++;
        arr.push_back(data);
    }
    void pop()
    {
        top--;
        return;
    }
    int Top()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        return arr.size() == 0;
    }
    int size()
    {
        return top + 1;
    }
    void clear()
    {
        while (top != -1)
        {
            pop();
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
    cout << s.size() << endl;
    cout << s.Top() << endl;
    s.pop();
    cout << s.Top() << endl;
    s.clear();
    cout << s.size() << endl;
    return 0;
}