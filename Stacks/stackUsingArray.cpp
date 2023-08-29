#include<iostream>
using namespace std;
class Stack{
    public:
    
    int top;
    int* arr;
    Stack(){
        top=-1;
        int size=1000;
        arr=new int[size];
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int data){
        top++;
        arr[top]=data;
    }
    //pop operation without returning any value
    // void pop(){
    //     top--;
    // }
    int pop(){
        int x=arr[top];
        top--;
        return x;
    }
    int Top(){
        return arr[top];
    }
    void clear(){
        while(top!=-1){
            cout<<pop()<<" element poped out "<<endl;
        }
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.isEmpty()<<endl;
    cout<<s.size()<<endl;
    // while(s.top!=-1){
    //     cout<<s.Top()<<" ";
    //     cout<<s.pop()<<endl;
    // }
    s.clear();
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}