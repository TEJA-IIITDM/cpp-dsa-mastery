/*
    Problem: Longest Palindromic Substring
    Platform: LeetCode
    Link: https://leetcode.com/problems/longest-palindromic-substring/
    Difficulty: Medium
    Approach: Expand Around Center — for each index, expand outward for both odd-length (single center) and even-length (gap center) palindromes, track the longest found
    Time: O(n^2)
    Space: O(1) extra (excluding output)
*/
#include<bits/stdc++.h>
using namespace std;
int extractouter(string s,int left,int right){
  while(left>=0 && right<s.size() && s[left]==s[right]){
    left--;
    right++;
  }
  return right-left-1;
}
string longestpalindrome(string s){
int start=0,end=0;
for(int i=0;i<s.size();i++){
  int len1=extractouter(s,i,i);
  int len2=extractouter(s,i,i+1);
  int len=max(len1,len2);
  if(len>end-start){
   start=i-(len-1)/2;
   end=i+(len)/2;
  }
}
return s.substr(start,end-start+1);
}
int main(){
 string s="losababaklwm";
 string result=longestpalindrome(s);
 cout << result;
}