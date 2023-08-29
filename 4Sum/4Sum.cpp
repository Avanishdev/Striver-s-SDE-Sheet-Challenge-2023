#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            //edge case
             // avoid the duplicates while moving i:
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                //edge case 2
                 // avoid the duplicates while moving j:
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                //using two pointers
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        //sum==target
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        //same logic as 3Sum to prevent same comparision of elements
                        //skip the duplicates:
                        while(k<l&&nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l&&nums[l]==nums[l+1]){
                            l--;
                        }
                        
                    }
                }
            }
        }
        return ans;
    }
};
void print(vector<vector<int>>& nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> nums={2,2,2,2,2};
    int target;
    cout<<"Enter target: ";
    cin>>target;
    Solution obj;
    vector<vector<int>> ans=obj.fourSum(nums,target);
    print(ans);
    return 0;
}