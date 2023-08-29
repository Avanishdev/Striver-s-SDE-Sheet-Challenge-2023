#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int start, long long mid, int end)
{
    // pairs count merge se nhi kar sakte kyuki merge me left side vale sorted array
    // me ek element se hogaya mtbal uske bad sare element se bhi ho jayega and this is
    // not the case for count pairs
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int *left = new int[len1];
    int *right = new int[len2];
    int mainIndex = start;
    for (int i = 0; i < len1; i++)
    {
        left[i] = a[mainIndex++];
    }
    for (int i = 0; i < len2; i++)
    {
        right[i] = a[mainIndex++];
    }
    mainIndex = start;
    int indx1 = 0;
    int indx2 = 0;
    while (indx1 < len1 && indx2 < len2)
    {
        if (left[indx1] <= right[indx2])
        {
            a[mainIndex++] = left[indx1++];
        }
        else
        {
            a[mainIndex++] = right[indx2++];
        }
    }
    while (indx1 < len1)
    {
        a[mainIndex++] = left[indx1++];
    }
    while (indx2 < len2)
    {
        a[mainIndex++] = right[indx2++];
    }
    delete[] left;
    delete[] right;
}
long long countHelper(vector<int> &a, int start, long long mid, int end)
{
    long long count = 0;
    int right = mid + 1;
    for (int i = start; i <= mid; i++)
    {
        while (right <= end && a[i] > (long long)2 * a[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}
long long countPairs(vector<int> &a, int start, int end)
{
    long long count = 0;
    // base
    if (start >= end)
    {
        return count;
    }
    // ek case solve karo
    long long mid = start + (end - start) / 2;
    // baki sabko count me add karo
    count += countPairs(a, start, mid);
    count += countPairs(a, mid + 1, end);
    count += countHelper(a, start, mid, end);
    merge(a, start, mid, end);
    return (int)count;
}
int main()
{
    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    int N = arr.size();
    cout << countPairs(arr, 0, N - 1) << endl;
    return 0;
}