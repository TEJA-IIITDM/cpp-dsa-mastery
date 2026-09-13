/*
    Problem: Palindrome Partitioning (LeetCode 131)
    Platform: LeetCode
    Link: https://leetcode.com/problems/palindrome-partitioning/
    Difficulty: Medium
    Approach: Loop-Based Backtracking — iterate partition boundaries i from index to N-1, advancing next search to i + 1 upon palindrome validation
    Time: O(2^N * N)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int l,int r){
while(l<r){
    if(s[l]!=s[r]) return false;
        l++;
        r--;
}
return true;
}
void helper(string s,int index,vector<vector<string>>& answer,vector<string>& temp){
    if(index==s.size()){
        answer.push_back(temp);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index,i)){
       temp.push_back(s.substr(index,i-index+1));
       helper(s,i+1,answer,temp);
       temp.pop_back();
        }
    }
}
vector<vector<string>> palindromepartitions(string s){
    vector<vector<string>> answer;
    vector<string>temp;
    helper(s,0,answer,temp);
    return answer;
}
int main(){
    string s="aab";
    vector<vector<string>> result=palindromepartitions(s);
    for(auto & s : result){
     for(auto c : s){
        cout << c << " ";
     }
    }
}