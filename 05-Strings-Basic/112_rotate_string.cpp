/*
    Problem: Rotate String
    Platform: LeetCode
    Link: https://leetcode.com/problems/rotate-string/
    Difficulty: Easy
    Approach: Concatenation Trick — check if lengths match and if string t exists as a substring inside (s + s)
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s="abcde";
  string goal="cdeab";
  if(s.size()!=goal.size()){
    cout<<"false";
    return 0;
  }
  string temp=s+s;
  if(temp.find(goal)!=string::npos){
    
    cout<<"true";
  }
  else{
    cout<<"false";
  }
}