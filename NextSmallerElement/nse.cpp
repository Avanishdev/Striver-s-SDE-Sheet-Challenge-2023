// circular array [i%n]
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        // pop out all greater elements
        while (!st.empty() && st.top() > arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                // not empty
                ans[i] = st.top();
            }
        }
        st.push(arr[i % n]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 10, 5, 8, 20, 15, 3, 12};
    int N = arr.size();
    arr = nextSmallerElement(arr, N);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}