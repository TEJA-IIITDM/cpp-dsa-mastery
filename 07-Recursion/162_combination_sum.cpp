/*
    Problem: Combination Sum (LeetCode 39)
    Platform: LeetCode
    Link: https://leetcode.com/problems/combination-sum/
    Difficulty: Medium
    Approach: Backtracking / Pick-and-Don't-Pick — pass 'index' instead of 'index + 1' on pick branch to enable unlimited element re-use
    Time: O(2^T) where T = target / min_element
    Space: O(T) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
void findcombination(vector<int>& arr,int target,int sum,int index,vector<vector<int>>& result,vector<int>& temp){
    if(sum==target){
        result.push_back(temp);
        return;
    }
    if(index==arr.size() || sum>target){
    return;
}
    if(arr[index]<=target-sum){
        temp.push_back(arr[index]);
        findcombination(arr,target,sum+arr[index],index,result,temp);
        temp.pop_back();
    }
    findcombination(arr,target,sum,index+1,result,temp);
}
vector<vector<int>> combinationsum(vector<int>& arr,int target){
    vector<vector<int>> result;
    vector<int> temp;
    findcombination(arr,target,0,0,result,temp);
    return result;
}
int main(){
    vector<int> arr={2,3,6,7};
    int target=7;
    vector<vector<int>> result=combinationsum(arr,target);
    for(const auto& v : result){
        for(int num : v){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}