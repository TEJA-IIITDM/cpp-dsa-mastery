/*
    Problem: Maximum Nesting Depth of the Parentheses
    Platform: LeetCode
    Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
    Difficulty: Easy
    Approach: Single Pass Counter — increment depth on '(', decrement on ')', and track maximum depth encountered
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s="(1+(2*3)+((8)/4))+1";
  int depth=0;
  int maxi=0;
  for(char c : s){
    if(c=='('){
      depth++;
      maxi=max(maxi,depth);
    }
    else if(c==')') depth--;
  }
  cout << maxi;
}