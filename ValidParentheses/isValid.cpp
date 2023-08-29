#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            // opening bracket
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                // closing bracket
                if (st.empty())
                {
                    return false;
                }
                else
                {
                    //
                    char c = st.top();
                    st.pop();
                    if (
                        (s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
                    {
                        continue; // agli iteration pe jao
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Solution obj;
    string s = "(){}[]]";
    cout << obj.isValid(s) << endl;
    return 0;
}