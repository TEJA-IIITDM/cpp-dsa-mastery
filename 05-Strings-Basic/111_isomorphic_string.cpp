/*
    Problem: Isomorphic Strings
    Platform: LeetCode
    Link: https://leetcode.com/problems/isomorphic-strings/
    Difficulty: Easy
    Approach: Two Hash Maps — map characters from s to t and from t to s simultaneously, ensuring a consistent one-to-one mapping in both directions
    Time: O(n)
    Space: O(1) (bounded by character set size, typically 256)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
string s="egg";
string t="add";
unordered_map<char,char>mp1,mp2;
if(s.size()!=t.size()){
  cout<<"false";
  return 0;
}
for(int i=0;i<s.size();i++){
  char c1=s[i];
  char c2=t[i];
  if(mp1.count(c1) && mp1[c1]!=c2){
    cout<<"false";
    return 0;
  }
  if(mp2.count(c2) && mp2[c2]!=c1){
    cout<<"false";
    return 0;
  }
  mp1[c1]=c2;
  mp2[c2]=c1;
}
cout<<"true";
}