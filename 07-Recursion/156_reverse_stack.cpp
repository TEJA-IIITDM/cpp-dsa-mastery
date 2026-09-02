/*
    Problem: Reverse a Stack using Recursion
    Platform: Self Practice
    Difficulty: Medium
    Approach: Dual Recursion — hold top elements in call stack, recursively reverse remaining sub-stack, and insert held elements at the bottom using a recursive helper
    Time: O(N^2)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> &s, int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertatbottom(s, temp);
    s.push(val);
}
void reversestack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s, temp);
}
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);
    reversestack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}