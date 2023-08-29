#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> targetSum(vector<int> &a,int target){
    unordered_map<int,int> map;
    for(int i=0;i<a.size();i++){
        int diff=target-a[i];
        if(map.find(diff)!=map.end()){//returns true or false but works like this only
            return {map[diff],i};
        }
        else{
            map[a[i]]=i;
        }
    }
    return {-1,-1};
}
bool twoSum(vector<int> &a,int target){
    //two-pointer approach
    //originnal array distorted
    sort(a.begin(),a.end());
    int s=0;
    int e=a.size()-1;
    while(s<=e){
        if(a[s]+a[e]==target){
            return 1;
        }
        else if(a[s]+a[e]<target){
            s++;
        }
        else{
            e--;
        }
    }
    return 0;
}
int main(){
    vector<int> arr={2,7,11,15};
    cout<<"Enter target sum "<<endl;
    int target;
    cin>>target;
    cout<<twoSum(arr,target)<<endl;
    return 0;
}