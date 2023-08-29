#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
// Optimal Approach 1 - Using Gap Method
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int left, int right)
{
    if (arr1[left] > arr2[right])
    {
        swap(arr1[left], arr2[right]);
    }
}
void merge(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int len = n + m;
    int gap = ceil(len / 2); // len/2+len%2
    while (gap > 0)
    {
        // alag left or right har gap itr ke sath
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // left arr1 or right arr2 me reside karr h
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // left arr2 or right toh tha hi arr2 me
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // left or right dono arr1 me reside karr h
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = ceil(gap / 2);
    }
}
// Optimal Approach 2
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int left = arr1.size() - 1; // largest element in arr1
    int right = 0;              // smallest element in arr2
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1.begin(), arr1.end()); // n size
    sort(arr2.begin(), arr2.end()); // m size
}
void print(vector<int> &arr1, vector<int> &arr2)
{
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < arr2.size(); j++)
    {
        cout << arr2[j] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int n = arr1.size();
    int m = arr2.size();
    // merge(arr1, n, arr2, m);
    merge(arr1, arr2, n, m);
    print(arr1, arr2);
    return 0;
}