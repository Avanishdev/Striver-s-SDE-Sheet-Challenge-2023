#include <iostream>
#include <vector>
using namespace std;
// int merge(vector<int> &arr, int start, int mid, int end)
// {
//     int count = 0;
//     vector<int> temp;
//     int left = start;
//     int right = mid + 1;
//     while (left <= mid && right <= end)
//     {
//         if (arr[left] < arr[right])
//         {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else
//         {
//             count = mid - start + 1;
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while (left <= mid)
//     {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while (right <= end)
//     {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     return count;
// }
long long merge(vector<int> &arr, int start, long long mid, int end)
{
    long long count = 0;
    // dono ki length nikalo
    int len1 = mid - start + 1;
    int len2 = end - mid;
    // dono ko heap memory allocate karo
    int *temp1 = new int[len1];
    int *temp2 = new int[len2];
    // copy values
    int mainIndex = start;
    for (int i = 0; i < len1; i++)
    {
        temp1[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        temp2[i] = arr[mainIndex++];
    }
    mainIndex = start;
    int index1 = 0;
    int index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        if (temp1[index1] < temp2[index2])
        {
            arr[mainIndex++] = temp1[index1++];
        }
        else
        {
            count+=len1-index1;//logic
            arr[mainIndex++] = temp2[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainIndex++] = temp1[index1++];
    }
    while (index2 < len2)
    {
        arr[mainIndex++] = temp2[index2++];
    }
    delete []temp1;
    delete []temp2;
    return count;
}
long long mergeSort(vector<int> &arr, int start, int end)
{
    long long count = 0;
    // base case
    if (start >= end)
    {
        return count;
    }
    // ek case solve karo
    long long mid = start + (end - start) / 2;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, start, mid, end);
    return count;
}
int main()
{
    vector<int> arr = {3, 2, 1};
    int n = arr.size();
    long long ans = 0;
    ans = mergeSort(arr, 0, n - 1);
    cout << ans << endl;
    return 0;
}