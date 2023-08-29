#include <bits/stdc++.h>

using namespace std;
class Stack
{
    // Define the data members.
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element)
    {
        // Implement the push() function.
        // Step 1
        // Push x first in empty q2
        q2.push(element);
        // Step 2
        //  Push all the remaining
        //  elements in q1 to q2.
        while (!q1.empty())
        {
            // q1 se utha kar q2 me dalo
            q2.push(q1.front());
            q1.pop();
        }
        // Step 3
        //  swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        // Implement the pop() function.
        if (q1.empty())
            return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        // Implement the top() function.
        if (q1.empty())
            return -1;
        return q1.front();
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
    cout << "Size of the stack before removing element: " << s.getSize() << endl;
    cout << "The deleted element is: " << s.pop() << endl;
    cout << "Top of the stack after removing element: " << s.top() << endl;
    cout << "Size of the stack after removing element: " << s.getSize();
    return 0;
}