// Better Approach
//  #include <iostream>
//  #include <vector>
//  #include <set>
//  #include <algorithm>
//  using namespace std;
//  vector<vector<int>> triplet(vector<int> &arr)
//  {
//      vector<vector<int>> ans;
//      for (int i = 0; i < arr.size(); i++)
//      {
//          // set banega
//          set<int> st;
//          for (int j = i + 1; j < arr.size(); j++)
//          {
//              int third = -(arr[i] + arr[j]);
//              if (st.find(third) != st.end())
//              {
//                  // agar st last element ko point nhi krta
//                  vector<int> temp = {arr[i] + arr[j] + third};
//                  sort(temp.begin(), temp.end());
//                  ans.push_back(temp);
//              }
//              else
//              {
//                  st.insert(arr[j]);
//              }
//          }
//      }
//      return ans;
//  }
//  void print(vector<vector<int>> &arr)
//  {
//      for (int i = 0; i < arr.size(); i++)
//      {
//          for (int j = 0; j < arr.size(); j++)
//          {
//              cout << arr[i][j] << " ";
//          }
//          cout << endl;
//      }
//  }
//  int main()
//  {
//      vector<int> arr = {-1, 0, 1, 2, -1, -4};
//      vector<vector<int>> ans = triplet(arr);
//      print(ans);
//      return 0;
//  }
// Optimal Approach
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < K)
            {
                j++;
            }
            else if (sum > K)
            {
                k--;
            }
            else
            {
                // sum==K
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}