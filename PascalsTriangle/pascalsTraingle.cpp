// print pascals triangle
#include <iostream>
#include <vector>
using namespace std;
long long nCr(int row, int col)
{
    long long res = 1;
    for (int i = 0; i < col; i++)
    {
        res = res * (row - i);
        res = res / (i + 1);
    }
    return res;
}
vector<int> generateRow(int N)
{
    int ans = 1; // i=0 ans=1
    vector<int> temp;
    temp.push_back(ans);
    for (int i = 1; i < N; i++)
    { // i is for col
        ans = ans * (N - i);//numerator
        ans = ans / i;//denominator
        temp.push_back(ans);
        }
    return temp;
}
vector<vector<int>> printPascalTriangle(int N)
{
    vector<vector<int>> ans;
    for (int row = 0; row < N; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}
int main()
{
    int row;
    cin >> row;
    int col;
    cin >> col;
    // printPascalTriangle(5);
    return 0;
}
