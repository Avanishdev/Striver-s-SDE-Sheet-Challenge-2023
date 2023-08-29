#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Better Approach
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}
// Optimal Approach
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int N = nums.size();
        int index = -1;
        // Step 1:- Find breakpoint
        for (int i = N - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Step 2:- Find just greater ele to index traversing from back
        for (int i = N - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Step 3:-reverse from index+1
        reverse(nums.begin() + index + 1, nums.end());
    }
};