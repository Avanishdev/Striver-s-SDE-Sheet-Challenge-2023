// Optimal Approach
// majorityElement>N/3
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int findMajority(vector<int> &arr)
{
    int N = arr.size();
    // Step 1:- Store majority element and count
    int count1 = 0, count2 = 0;
    int majorityElement1=INT_MIN;
    int majorityElement2=INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (count1 == 0&& arr[i] != majorityElement2)
        {
            count1++;
            majorityElement1 = arr[i];
        }
        else if (count2 == 0&& arr[i] != majorityElement1)
        {
            count2++;
            majorityElement2 = arr[i];
        }
        else if (arr[i] == majorityElement1 )
        {
            count1++;
        }
        else if (arr[i] == majorityElement2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == majorityElement1)
        {
            count1++;
        }
        else if (arr[i] == majorityElement2)
        {
            count2++;
        }
    }
    if (count1 > N / 3)
    {
        // store majorityElement1;
    }
    if (count2 > N / 3)
    {
        // store majorityElement2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 2};
    cout << findMajority(arr) << endl;
    return 0;
}