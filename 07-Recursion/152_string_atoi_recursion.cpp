/*
    Problem: String to Integer (atoi) - Recursive Approach
    Platform: LeetCode / GeeksforGeeks
    Link: https://leetcode.com/problems/string-to-integer-atoi/
    Difficulty: Medium
    Approach: Tail Recursion — handle leading whitespace & sign iteratively, then recursively accumulate digits while performing overflow checks against INT_MAX/INT_MIN
    Time: O(N)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
int solve(string s,int i,long long num,int sign){
    if(i>=s.size() || !isdigit(s[i])){
   return num*sign;
    }
    num=num*10+(s[i]-'0');
    if( sign==1 && num>=INT_MAX) return INT_MAX;
    if( sign==-1 && num*sign<=INT_MIN) return INT_MIN;
    return solve(s,i+1,num,sign);
}
int atoi(string s){
    int i=0;
    while(i<s.size() && s[i] ==' ') i++;
    int sign=1;
    if(i<s.size() && (s[i]=='+' || s[i]=='-')){
    if(s[i]=='-') sign=-1;
    i++;
    }
    return solve(s,i,0,sign);
}
int main(){
    string s="1337c0d3";
    cout << atoi(s) ;
}