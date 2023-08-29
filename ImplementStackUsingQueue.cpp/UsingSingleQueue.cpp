#include <queue>
#include <iostream>
using namespace std;
class Stack
{
public:
    queue<int> q;
    void push(int d)
    {
        q.push(d);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }
    int top()
    {
        return q.front();
    }
    int size()
    {
        return q.size();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Top of the stack: " << s.top() << endl;
    cout << "Size of the stack before removing element: " << s.size() << endl;
    cout << "The deleted element is: " << s.pop() << endl;
    cout << "Top of the stack after removing element: " << s.top() << endl;
    cout << "Size of the stack after removing element: " << s.size();
    return 0;
}