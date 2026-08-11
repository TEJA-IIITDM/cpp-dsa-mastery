/*
    Problem: Remove Outermost Parentheses
    Platform: LeetCode
    Link: https://leetcode.com/problems/remove-outermost-parentheses/
    Difficulty: Easy
    Approach: Depth/Balance Tracking — track a balance counter, skip the outermost '(' (when balance was 0) and outermost ')' (when balance becomes 0), keep everything else
    Time: O(n)
    Space: O(n) for output
*/
#include<bits/stdc++.h>
using namespace std;    
int main(){
    string s="()(()())(())";
    int balance=0;
    string res="";
    for(char c:s){
        if(c=='('){
            if(balance==0) balance++;
            else{
                res+=c;
                balance++;
            }
        }
        else{
            if(balance==1){
                balance--;
            }
            else{
                res+=c;
                balance--;
            }
        }
    }
    cout<<res<<endl;
}