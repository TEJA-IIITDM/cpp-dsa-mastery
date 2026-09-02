/*
    Problem: Sort a Stack using Recursion
    Platform: Self Practice
    Difficulty: Medium
    Approach: Dual-Recursive Insertion — recursively dismantle stack, sort remaining elements, and insert each element into its sorted position via auxiliary recursive function
    Time: O(N^2)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> &s, int temp){
    if(s.empty() || temp>=s.top()){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertatbottom(s, temp);
    s.push(val);
}
void sortstack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    sortstack(s);
    insertatbottom(s, temp);
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    sortstack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}