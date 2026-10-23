/*
    Problem: Jump Game II (LeetCode 45)
    Platform: LeetCode
    Link: https://leetcode.com/problems/jump-game-ii/
    Difficulty: Medium
    Approach: Greedy BFS Range Expansion — update maxReach at each step and increment jumps only when index i reaches currEnd
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int minimumjumps(vector<int> nums){
    int jumps=0,currentend=0,maxindex=0;
        for(int i=0;i<nums.size()-1;i++){
            maxindex=max(maxindex,i+nums[i]);
            if(i==currentend){
                jumps++;
                currentend=maxindex;
            }
        }
        return jumps;
}
int main(){
    vector<int> nums={2,3,1,1,4};
    int result=minimumjumps(nums);
    cout<<result<<endl;
}