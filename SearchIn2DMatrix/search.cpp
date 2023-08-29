#include <iostream>
#include <vector>
using namespace std;
bool search(vector<vector<int>> matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / col][mid % col]; // logic
        if (element == target)
        {
            cout << mid / col << " " << mid % col << endl;
            return 1;
        }
        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 6;
    if (search(matrix, target))
    {
        cout << "Element present" << endl;
    }
    else
    {
        cout << "Element not present" << endl;
    }
    return 0;
}