/*
    Problem: Sort Characters By Frequency
    Platform: LeetCode
    Link: https://leetcode.com/problems/sort-characters-by-frequency/
    Difficulty: Medium
    Approach: Hash Map + Sort — count character frequencies, sort (char,count) pairs by count descending, build result by repeating each character its count times
    Time: O(n + k log k) where k = number of distinct characters
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s="Aabb";
  unordered_map<char,int>mp;
  for(int i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  vector<pair<char,int>> chars(mp.begin(),mp.end());
  sort(chars.begin(),chars.end(), [](pair<char,int>& a,pair<char,int>& b){
    return a.second > b.second;
  });

  string result="";
  for(auto& [ch,count] : chars){
    result+=string(count,ch);
  }
  cout << result;
}