/*
    Problem: Sum of Beauty of All Substrings
    Platform: LeetCode
    Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
    Difficulty: Medium
    Approach: Brute Force with Running Frequency Count — for each starting point, extend substring one char at a time maintaining a frequency array, compute (max freq - min freq) at each step, sum across all substrings
    Time: O(26 * n^2)
    Space: O(26)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
 string s="aabcb";
 int answer=0;
 for(int i=0;i<s.size();i++){
  vector<int>freq(26,0);
  for(int j=i;j<s.size();j++){
   freq[s[j]-'a']++;
   int maxi=0,mini=INT_MAX;
   for(int f : freq){
    if(f>0){
      maxi=max(maxi,f);
      mini=min(mini,f);
    }
   }
   answer+=(maxi-mini);
  }
 }
 cout << answer;
}