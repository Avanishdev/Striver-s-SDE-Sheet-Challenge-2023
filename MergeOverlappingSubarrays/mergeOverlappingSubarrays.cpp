#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &matrix){
    vector<vector<int>> ans;
    //sort
    sort(matrix.begin(),matrix.end());
    //traverse
    for(int i=0;i<matrix.size();i++){
        if(ans.empty() || matrix[i][0]>ans.back()[1]){
            ans.push_back(matrix[i]);//matrix[i]=intervals
        }
        else{
            ans.back()[1]=max(matrix[i][1],ans.back()[1]);
        }
    }
    return ans;
}
void print(vector<vector<int>> &matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix={{1,3},{2,4},{3,5},{6,7}};
    matrix=merge(matrix);
    print(matrix);
    return 0;
}