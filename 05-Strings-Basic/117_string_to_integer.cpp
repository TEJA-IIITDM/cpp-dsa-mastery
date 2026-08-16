/*
    Problem: String to Integer (atoi)
    Platform: LeetCode
    Link: https://leetcode.com/problems/string-to-integer-atoi/
    Difficulty: Medium
    Approach: Deterministic Finite Automaton (DFA) / Sequential Parsing — trim leading whitespaces, handle sign, convert digits while clamping to INT_MIN/INT_MAX on overflow
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s=" -042";
 int i=0,sign=1;
 int result=0;
 while(i<s.size() && s[i]==' ') i++;
 if(i<s.size() && (s[i]=='+' || s[i]=='-')){
  if(s[i]=='-') sign=-1;
  i++;
 }
 while(i<s.size() && isdigit(s[i])){
  result=result*10+(s[i]-'0');
  if(result*sign>INT_MAX) return INT_MAX;
  if(result*sign<INT_MIN) return INT_MIN;
  i++;
 }
 cout << result*sign;
}