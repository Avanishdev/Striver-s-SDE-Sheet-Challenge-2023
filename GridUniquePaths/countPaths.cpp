#include <iostream>
#include <vector>
using namespace std;
// int uniquePathsHelper(int i,int j,int m,int n,vector<vector<int>> &dp){
//         //can be traversed
//         if(i==(m-1) && j==(n-1)){
//             return 1;
//         }
//         //out of bounds
//         if(i>=m||j>=n){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//            return dp[i][j];//removing that extra traversal(1,1)
//         }
//         return dp[i][j]=uniquePathsHelper(i+1,j,m,n,dp)+uniquePathsHelper(i,j+1,m,n,dp);
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));//sabko initialize kardiya -1 se
//          int num=uniquePathsHelper(0,0,m,n,dp);
//         if(m==1&&n==1)
//             return num;
//         return dp[0][0];//ans stored
//     }
int uniquePaths(int row, int col)
{
    int N = row + col - 2; //(row-1)+(col-1)
    int r = row - 1;       // Or col-1
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        // numerator
        ans = ans * (N - r + i);
        // denominator
        ans = ans / i;
    }
    return (int)ans;
}
int main()
{
    cout << "Enter row" << endl;
    int row;
    cin >> row;
    cout << "Enter col" << endl;
    int col;
    cin >> row;
    cout << uniquePaths(row, col) << endl;
    return 0;
}