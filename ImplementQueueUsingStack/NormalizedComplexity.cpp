//Time Complexity-O(N)
//Space Complexity-O(2N)
#include<iostream>
#include<stack>
using namespace std;
class Queue{
    public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        //Step 1 S1-->S2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //Step 2 x-->S1
        s1.push(x);
        //Step 3 S2-->S1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        if(s1.empty()){
            return -1;
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
    int Top(){
        if(s1.empty()){
            return -1;
        }
        return s1.top();
    }
    bool isEmpty(){
        return s1.empty();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while(!q.isEmpty()){
        cout<<q.Top()<<" ";
        cout<<q.pop()<<" popped"<<endl;
    }
    return 0;
}