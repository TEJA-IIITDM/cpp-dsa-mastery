/*
    Problem: Subsets / Power Set (LeetCode 78)
    Platform: LeetCode
    Link: https://leetcode.com/problems/subsets/
    Difficulty: Medium
    Approach: Bitmasking — iterate binary numbers from 0 to 2^N - 1 and test j-th bit (i & (1 << j)) to determine element inclusion
    Time: O(N * 2^N)
    Space: O(N * 2^N) for output storage
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerset(vector<int>& nums){
    vector<vector<int>> ans;
    int total=1<<nums.size();
    for(int i=0;i<total;i++){
        vector<int>subset;
        for(int j=0;j<nums.size();j++){
            if(i&(1<<j)){
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}
int main(){
vector<int> nums={1,2,3};
vector<vector<int>> ans=powerset(nums);
for(auto subset:ans){
    for(auto num:subset){
        cout<<num<<" ";
    }
    cout<<endl;
}
}