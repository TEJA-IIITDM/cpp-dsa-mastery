/*
    Problem: Max Consecutive Ones III (LeetCode 1004)
    Platform: Self Practice / LeetCode
    Link: https://leetcode.com/problems/max-consecutive-ones-iii/
    Difficulty: Medium
    Approach: Single-Pass Sliding Window — shift window forward without inner shrinking loop
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int maxconsectutiveones(vector<int> nums,int k){
    int left=0,right=0;
    int zeroes=0;
    int len=0;
    while(right<nums.size()){
        if(nums[right]==0) zeroes++;
        if(zeroes>k){
         if(nums[left]==0) zeroes--;
         left++;
        }
        len=max(len,right-left+1);
        right++;
    }
    return len;
}
int main(){
    vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k=2;
    int result=maxconsectutiveones(nums,k);
    cout << result;
}