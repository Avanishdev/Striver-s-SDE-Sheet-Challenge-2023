//circular array[i%n]
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> nextGreaterElement(vector<int> &nums, int n)
{
  vector<int> nge(n, -1);
  stack<int> st;
  for (int i = 2 * n - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top() <= nums[i % n])
    {
      st.pop();
    }

    if (i < n)
    {
      if (!st.empty())
        nge[i] = st.top();
    }
    st.push(nums[i % n]);
  }
  return nge;
}
int main()
{
  vector<int> nums = {1, 5, 3, 4, 2};
  int n = nums.size();
  nums = nextGreaterElement(nums, n);
  for (int i = 0; i < n; i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}