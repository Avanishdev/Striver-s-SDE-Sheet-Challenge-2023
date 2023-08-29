#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
//  class Solution {
//  public:
//      void markRow(int i,vector<vector<int>>& matrix){

//         for(int j=0;j<matrix[0].size();j++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]=-1;
//             }
//         }
//     }
//     void markCol(int j,vector<vector<int>>& matrix){

//          for(int i=0;i<matrix.size();i++){
//              if(matrix[i][j]!=0){
//                  matrix[i][j]=-1;
//              }
//          }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         //traversing 2-D matrix
//         for(int row=0;row<matrix.size();row++){
//             for(int col=0;col<matrix[0].size();col++){
//                 //Check if ele is zero or not
//                 if(matrix[row][col]==0){
//                     //mark row
//                     markRow(row,matrix);
//                     //mark column
//                     markCol(col,matrix);
//                 }
//             }
//         }
//         //again traverse to mark -1 to 0
//         for(int row=0;row<matrix.size();row++){
//             for(int col=0;col<matrix[0].size();col++){
//                 if(matrix[row][col]==-1){
//                     matrix[row][col]=0;
//                 }
//             }
//         }
//     }
// };

// Better Approach
//  class Solution {
//  public:
//      void setZeroes(vector<vector<int>>& matrix) {
//          //traverse
//          //make seperate arrays for row as well as col
//          vector<int> i(matrix.size());//row
//          vector<int> j(matrix[0].size());//col
//          for(int row=0;row<matrix.size();row++){
//              for(int col=0;col<matrix[0].size();col++){
//                  if(matrix[row][col]==0){
//                      i[row]=1;
//                      j[col]=1;
//                  }
//              }
//          }
//          //traverse i & j to make 1 to 0's
//          for(int row=0;row<matrix.size();row++){
//              for(int col=0;col<matrix[0].size();col++){
//                  if(i[row]==1 || j[col]==1){
//                      matrix[row][col]=0;
//                  }
//              }
//          }
//      }
//  };

// Optimal Approach
// Optimal Approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // traverse
        int col0 = 1;
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[0].size(); col++)
            {
                if (matrix[row][col] == 0)
                {
                    // ith row mark 0
                    matrix[row][0] = 0;
                    // jth row mark 0
                    if (col != 0)
                    {
                        matrix[0][col] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }
        // Non hash traversal
        for (int row = 1; row < matrix.size(); row++)
        {
            for (int col = 1; col < matrix[0].size(); col++)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }
        // hashes ko mark karo

       for(int col=0;col<matrix[0].size();col++){
                if(matrix[0][0]==0){
                    matrix[0][col]=0;
                }
            }
         
        
            for(int row=0;row<matrix.size();row++){
                if(col0==0){
                    matrix[row][0]=0;
                }
            }
    }
};
void print(vector<vector<int>> &matrix)
{
    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    obj.setZeroes(matrix);
    print(matrix);
    return 0;
}