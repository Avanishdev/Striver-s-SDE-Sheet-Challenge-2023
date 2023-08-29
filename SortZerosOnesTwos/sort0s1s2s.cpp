// DNF->Dutch National Flag
#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            // 2
            swap(nums[mid], nums[high]);
            mid++;
            high--;
        }
    }
}
void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sort(nums);
    print(nums);
    return 0;
}