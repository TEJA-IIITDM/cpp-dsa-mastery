/*
    Problem: Valid Anagram
    Platform: LeetCode
    Link: https://leetcode.com/problems/valid-anagram/
    Difficulty: Easy
    Approach: Frequency Count — count character occurrences in s, decrement for each character in t, if all counts return to zero and lengths match, it's a valid anagram
    Time: O(n)
    Space: O(1) (bounded by character set size, typically 26)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s="anagram";
  string t="nagaram";
  if(s.size()!=t.size()) return cout<<"false",0;
  int freq[26]={0};
  for(int i=0;i<s.size();i++){
    freq[s[i]-'a']++;
    freq[t[i]-'a']--;
  }
  for(int i=0;i<26;i++){
    if(freq[i]!=0) return cout<<"false",0;
  }
  return cout<<"true",0;
}