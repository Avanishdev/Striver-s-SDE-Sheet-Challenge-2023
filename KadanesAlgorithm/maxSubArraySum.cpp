// Optimal Approach
#include <iostream>
#include <limits.h>
using namespace std;
int maxSubArray(int arr[], int N)
{
    int start=-1;
    int sum = 0;
    int maxSum = INT_MIN;
    int ansStart=-1;
    int anskaEnd=-1;
    for (int i = 0; i < N; i++)
    {
        if(sum==0){
            start=i;//sum 0 ek naya start ho sakta hai
        }
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart=start;
            anskaEnd=i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxSum < 0)
    {
        maxSum = 0;
    }
    //printing subarray with maximum sum
    while(ansStart<=anskaEnd){
        cout<<arr[ansStart]<<" ";
        ansStart++;
    }
    cout<<endl;
    return maxSum;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int N = sizeof(arr) / sizeof(int);
    cout << maxSubArray(arr, N) << endl;
    return 0;
}