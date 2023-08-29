#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int slidingWindowMax(vector<int> &arr, int left, int right)
{
    int maxi = INT_MIN;
    for (int i = left; i <= right; i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i]; // max update
        }
    }
    return maxi;
}
vector<int> getMax(vector<int> &arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n-k+1; i++)
    {
        int temp = slidingWindowMax(arr, i, i + k - 1);
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    // vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};//3
    // vector<int> arr = {20,25};//2
    vector<int> arr = {1,3,-1,-3,5,3,6,7};//3
    // vector<int> arr = {1};//1
    int k;
    cin >> k;
    vector<int> temp = getMax(arr, k);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}