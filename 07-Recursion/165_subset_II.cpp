/*
    Problem: Subsets II (LeetCode 90)
    Platform: LeetCode
    Link: https://leetcode.com/problems/subsets-ii/
    Difficulty: Medium
    Approach: Loop-Based Backtracking — sort input array first, then prune duplicate choices at the same recursion depth using `i > index && arr[i] == arr[i - 1]`
    Time: O(2^N * N) worst case
    Space: O(N) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void helper(vector<int> &arr,int index,vector<vector<int>> &ans,vector<int> &temp){
    ans.push_back(temp);
    
  for(int i=index;i<arr.size();i++){
    if(i>index && arr[i]==arr[i-1]) continue;
    temp.push_back(arr[i]);
    helper(arr,i+1,ans,temp);
    temp.pop_back();
  }
}
vector<vector<int>> uniquesubsets(vector<int> &arr,int index){
  sort(arr.begin(),arr.end());
  vector<vector<int>> ans;
  vector<int> temp;
  helper(arr,index,ans,temp);
  return ans;
}
int main(){
  vector<int> arr={1,2,2};
  vector<vector<int>> result=uniquesubsets(arr,0);
  for(auto &subset:result){
    for(auto &num:subset){
      cout<<num<<" ";
    }
    cout<<endl;
  }

}