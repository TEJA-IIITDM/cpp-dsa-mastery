/*
    Problem: Longest Consecutive Sequence
    Platform: LeetCode
    Link: https://leetcode.com/problems/longest-consecutive-sequence/
    Difficulty: Medium
    Approach: Hash Set — only start counting from true sequence beginnings (where x-1 doesn't exist), walk forward counting consecutive elements
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
bool linear(vector<int>& arr,int num){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==num) return true;
    }
    return false;
}
int main(){
    vector<int> arr={1,2,5,6,7};
    int longest=0;
    unordered_set<int> s(arr.begin(),arr.end());
    for(int x : s){
     if(!s.count(x-1)){
       int cur=x;
       int curlen=1;
       while(s.count(cur+1)){
        cur++;
        curlen++;
       }
       longest=max(longest,curlen);
     }
    }
    cout << longest;
}