/*
    Problem: Combination Sum III (LeetCode 216)
    Platform: LeetCode
    Link: https://leetcode.com/problems/combination-sum-iii/
    Difficulty: Medium
    Approach: Backtracking / Loop-Based Search — explore combinations of k distinct numbers from 1 to 9 with running sum tracking and early pruning
    Time: O(C(9, k)) bounded by fixed input domain [1..9]
    Space: O(k) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void helper(int index,vector<vector<int>> &ans,vector<int> &temp,int sum,int k,int n){
    if(temp.size()==k && sum==n){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<=9;i++){
        temp.push_back(i);
        helper(i+1,ans,temp,sum+i,k,n);
        temp.pop_back();
    }
}
vector<vector<int>> combinationsumIII(int index,int k,int n){
  vector<vector<int>> ans;
  vector<int> temp;
  helper(index,ans,temp,0,k,n);
  return ans;
}
int main(){
  int k=4;
  int n=1;
  vector<vector<int>> result=combinationsumIII(1,k,n);
  for(auto &subset:result){
    for(auto &num:subset){
      cout<<num<<" ";
    }
    cout<<endl;
  }

}