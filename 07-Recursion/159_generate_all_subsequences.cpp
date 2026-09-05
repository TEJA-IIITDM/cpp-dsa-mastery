/*
    Problem: Subsets / Power Set / Generate All Subsequences (LeetCode 78)
    Platform: LeetCode / Self Practice
    Link: https://leetcode.com/problems/subsets/
    Difficulty: Medium
    Approach: Backtracking / Pick-and-Don't-Pick Recursion — branch into including or excluding arr[index] and backtrack upon returning from recursive steps
    Time: O(2^N * N)
    Space: O(N) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void generatesubsequences(const string& str,int index,string curr,vector<string>& result){
    if(index==str.size()){
        if(curr.size()>0){
            result.push_back(curr);
        }
        return;
    }
    curr.push_back(str[index]);
    generatesubsequences(str,index+1,curr,result);
    curr.pop_back();
    generatesubsequences(str,index+1,curr,result);
}
int main(){
    string str="abc";
    vector<string> result;
    generatesubsequences(str,0,"",result);
    for(const auto& s : result){
        cout<<s<<endl;
    }
}