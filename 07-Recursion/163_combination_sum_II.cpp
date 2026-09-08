/*
    Problem: Combination Sum II (LeetCode 40)
    Platform: LeetCode
    Link: https://leetcode.com/problems/combination-sum-ii/
    Difficulty: Medium
    Approach: Backtracking with Loop-Based Duplicate Pruning — sort array and skip arr[i] == arr[i-1] for i > index to avoid duplicate subset branches
    Time: O(2^N)
    Space: O(N) call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void findcombination(vector<int>& arr,int target,int sum,int index,vector<vector<int>>& result,vector<int>& temp){
    if(sum==target){
        result.push_back(temp);
        return;
    }
    for(int i=index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(sum+arr[i]>target) break;
        temp.push_back(arr[i]);
        findcombination(arr,target,sum+arr[i],i+1,result,temp);
        temp.pop_back();
    }
}
vector<vector<int>> combinationsum2(vector<int>& arr,int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    vector<int> temp;
    findcombination(arr,target,0,0,result,temp);
    return result;
}
int main(){
    vector<int> arr={2,5,2,1,2};
    int target=5;
    vector<vector<int>> result=combinationsum2(arr,target);
    for(const auto& v : result){
        for(int num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}