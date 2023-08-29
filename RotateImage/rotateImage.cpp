#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void transpose(vector<vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < row; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }
}

// clock-wise
void reverseRow(vector<vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        reverse(matrix[row].begin(), matrix[row].end());
    }
}
//Approach-1
// for anticlockwise solution basically reverse every column
void reverseColumn(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    //Approach-2
    // different way
    //int temp=[i][j]
    //[i][j]=[j][n-1-i]
    //[j][n-1-i]=[n-1-i][n-1-j]
    //[n-1-i][n-1-j]=[n-1-j][i]
    //[n-1-j][i]=temp
    for (int i = 0; i < n / 2; i++)
    {
        // i=border element
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][n - 1-i];
            matrix[j][n - 1-i] = matrix[n - 1-i][n  - 1-j];
            matrix[n - i - 1][n - j - 1] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = temp;
        }
    }
}
void rotateImage(vector<vector<int>> &matrix)
{
    // transpose
    // transpose(matrix);
    // reverse every row
    // reverseRow(matrix);
    reverseColumn(matrix);
}

void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateImage(matrix);
    print(matrix);
    return 0;
}