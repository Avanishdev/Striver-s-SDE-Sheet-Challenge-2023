#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=1;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> st;//set stores unique elements
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        //set pe traverse karna hai simple
        for(auto itr:st){
            int count=0;
            int x=itr;
            //find function returns 0 or 1
            if(st.find(itr-1)==st.end()){
                //st me end tak (itr-1) nhi mila
                count=1;
                x=itr;
                while(st.find(x+1)!=st.end()){
                    //isme agye mtlab (itr+1) mil gaya hoga
                    count++;
                    x=x+1;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};