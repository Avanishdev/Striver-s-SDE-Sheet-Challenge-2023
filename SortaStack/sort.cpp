#include <bits/stdc++.h>
using namespace std;
void insertSorted(stack<int> &stack, int num)
{
    // base
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    // ek case solve karo
    int n = stack.top();
    stack.pop();

    // recursive call
    insertSorted(stack, num);

    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    // base case
    if (stack.empty())
    {
        return;
    }
    // ek case solve karo
    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);
    // insert in a sorted order
    insertSorted(stack, num);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(-7);
    st.push(3);
    st.push(2);
    st.push(-5);
    cout << "Before sorting" << endl;
    // while (st.size())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;
    sortStack(st);
    cout << "After sorting" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}