/*
    Problem: Merge Intervals
    Platform: LeetCode
    Link: https://leetcode.com/problems/merge-intervals/
    Difficulty: Medium
    Approach: Sort by start time, then merge overlapping intervals in a single pass by comparing each interval's start against the current merged interval's end
    Time: O(n log n)
    Space: O(n) for output (excluding sort's internal space)
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals){
  sort(intervals.begin(),intervals.end());
  if(intervals.empty()) return vector<vector<int>>();
  vector<vector<int>> result;
  result.push_back(intervals[0]);
  for(int i=1;i<intervals.size();i++){
    vector<int> &last=result.back();
    if(last[1]>=intervals[i][0]){
      last[1]=max(last[1],intervals[i][1]);
    }
    else{
      result.push_back(intervals[i]);
    }
  }
  return result;
}
int main (){
 vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
 vector<vector<int>> result=merge(intervals);
for(auto &interval : result){
  cout << "{";
  for(int x : interval){
    cout << x << " ";
  }
  cout << "}";
}
}