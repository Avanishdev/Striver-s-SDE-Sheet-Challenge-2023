#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
vector<int> leftSmaller(vector<int> &heights)
{
    int n = heights.size();
    // leftSmallerArray
    vector<int> leftSmallerArray(n);
    for (int i = 0; i < n; i++)
    {
        // greater elements ko pop karo
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }
        // stack is empty
        if (st.empty())
        {
            leftSmallerArray[i] = 0;
        }
        else
        {
            // stack is not empty
            // smaller element mil gaya
            // push element in array
            leftSmallerArray[i] = st.top() + 1;
        }
        // push element in stack
        st.push(i);
    }
    
    return leftSmallerArray;
}
vector<int> rightSmaller(vector<int> &heights)
{
    int n = heights.size();
    // rightSmallerArray
    vector<int> rightSmallerArray(n);
    // ulta traversal
    for (int i = n - 1; i >= 0; i--)
    {
        // greater elements ko pop karo
        while (!st.empty() && heights[i] <= heights[st.top()])
        {
            st.pop();
        }
        // stack is empty
        if (st.empty())
        {
            rightSmallerArray[i] = n - 1; // or i
        }
        else
        {
            // stack is not empty
            // smaller element mil gaya
            // push element in array
            rightSmallerArray[i] = st.top() - 1;
        }
        // push element in stack
        st.push(i);
    }
    
    return rightSmallerArray;
}
int findMaxArea(vector<int> &heights)
{
    int n=heights.size();
    vector<int> leftSmallerArray = leftSmaller(heights);
    // stack ko empty kare h taki reuse ho sake
    while (!st.empty())
    {
        st.pop();
    }
    vector<int> rightSmallerArray = rightSmaller(heights);
    //for every element, calculate area
    int maxArea=0;
    for(int i=0;i<n;i++){
        //width*height=area
        //maximum of both
        maxArea=max(maxArea,(rightSmallerArray[i]-leftSmallerArray[i]+1)*heights[i]);
    }
    return  maxArea;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    cout << findMaxArea(heights) << endl;
    return 0;
}