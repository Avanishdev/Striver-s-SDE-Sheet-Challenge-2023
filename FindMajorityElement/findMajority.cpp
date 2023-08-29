//Optimal Approach
//majorityElement>N/2
#include <iostream>
#include <vector>
using namespace std;
int findMajority(vector<int> &arr)
{
    int N = arr.size();
    // Step 1:- Store majority element and count
    int count = 0;
    int majorityElement;
    for (int i = 0; i < N; i++)
    {
        if (count == 0)
        {
            count++;
            majorityElement = arr[i];
        }
        else if (arr[i] == majorityElement)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == majorityElement)
        {
            count++;
        }
    }
    if (count > N / 2)
    {
        return majorityElement;
    }
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    cout << findMajority(arr) << endl;
    return 0;
}