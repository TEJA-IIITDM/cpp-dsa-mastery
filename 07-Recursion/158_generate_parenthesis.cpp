/*
    Problem: Generate Parentheses
    Platform: LeetCode / Self Practice
    Link: https://leetcode.com/problems/generate-parentheses/
    Difficulty: Medium
    Approach: Backtracking / Decision Tree Pruning — append '(' if open < n, append ')' if close < open until length equals 2*n
    Time: O(4^N / sqrt(N)) — bounded by N-th Catalan Number
    Space: O(N) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void generate(vector<string> &result,int n,string current,int open,int close){
    if(current.length()==2*n){
        result.push_back(current);
        return;
    }
    if(open<n){
        generate(result,n,current+'(',open+1,close);
    }
    if(close<open){
        generate(result,n,current+')',open,close+1);
    }
}
int main(){
    vector<string> result;
    int n=2;
    generate(result,n,"",0,0);
    for(auto s : result){
        cout<<s<<endl;
    }
}