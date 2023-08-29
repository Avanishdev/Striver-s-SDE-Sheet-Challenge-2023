// Optimal Approach
#include <iostream>
using namespace std;
double powerN(double x, int n)
{
    //    Step 1:- Store ans
    double ans = 1.0;
    long N = n;
    // Step 2:- Make N positive
    if (N < 0)
    {
        N = -1 * N;
    }
    while (N > 0)
    { // N zero nahi hota tab tak
        if (N % 2 == 1)
        { // N&1
            // Step 3:- odd
            ans = ans * x;
            N = N - 1;
        }
        else
        {
            // even
            x = x * x;
            N = N / 2; // N>>1
        }
    }
    if (N < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    int ans = 1;

    while (n > 0)
    {

        if (n & 1)
        { // n%2
            // odd
            ans = (1LL * (ans) % m * (x) % m) % m;
        }
        n = n >> 1; // n=n/2
        x = (1LL * (x) % m * (x) % m) % m;
    }
    return ans;
}
int main()
{
    double x;
    int n;
    cin >> x >> n;
    double ans;
    ans = powerN(x, n);
    cout << ans << endl;
    return 0;
}