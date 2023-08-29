// Optimal Approach
#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    { // executed atleast once
        slow = arr[slow];
        fast = arr[arr[fast]];
        cout << slow << endl;
        cout << fast << endl;
        cout<<"end"<<endl;
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
        cout << slow << endl;
        cout << fast << endl;
    }
    return slow; // or fast
}
int main()
{
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr) << endl;
    return 0;
}