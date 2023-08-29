// Time Complexity-O(1) *amortized
// Space Complexity-O(2N)
#include <iostream>
#include <stack>
using namespace std;
class Queue
{
public:
    stack<int> input;
    stack<int> output;
    void push(int x)
    {
        input.push(x);
    }
    int pop()
    {
        if(output.empty()){
            //Input -> Output
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()){
            return -1;
        }
        int ans=output.top();
        output.pop();
        return ans;
    }
    int Top()
    {
        // shift input to output
        if(output.empty()){
            //Input -> Output
            while(!input.empty()){
            output.push(input.top());
            input.pop();
            }
        }
        if(output.empty()){
            return -1;
        }
        return output.top();
    }
    bool isEmpty()
    {
        return output.empty()&&input.empty();
    }
    int size()
    {
        return output.size()+input.size();
    }
};
int main()
{
    Queue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
    return 0;
}