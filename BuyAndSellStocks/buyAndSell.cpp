//Optimal Approach
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int mini = INT_MAX;
    int maxProfit = INT_MIN;
    int profit = -1;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < mini)
        {
            mini = prices[i];
        }
        profit = prices[i] - mini;
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
    }
    return maxProfit;
}
int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}