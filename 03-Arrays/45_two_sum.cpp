/*
    Problem: Two Sum
    Platform: LeetCode
    Link: https://leetcode.com/problems/two-sum/
    Difficulty: Easy
    Approach: Hash Map — store value to index mapping, check if complement (target - current) was seen before
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> issum(vector<int>& arr,int k){
   unordered_map<int,int> mp;
   for(int i=0;i<arr.size();i++){
    int num=arr[i];
    int more=k-num;
    if(mp.find(more)!=mp.end()) return {mp[more],i};
    mp[num]=i;
   }
   return {-1,-1};
}
int main(){
    vector<int> arr={2,7,11,15};
    int k=9;
    vector<int> ans=issum(arr,k);
    cout << ans[0] << ","  << ans[1];
}