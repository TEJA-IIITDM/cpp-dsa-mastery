/*
    Problem: Roman to Integer
    Platform: LeetCode
    Link: https://leetcode.com/problems/roman-to-integer/
    Difficulty: Easy
    Approach: Single Pass Lookup — compare current value with next value; subtract if current < next, otherwise add
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s="MCMXCIV";
 int result=0;
 unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
 for(int i=0;i<s.size();i++){
  if(i+1<s.size() && mp[s[i]]<mp[s[i+1]]){
    result-=mp[s[i]];
  }
  else{
    result+=mp[s[i]];
  }
 }
 cout << result;
}