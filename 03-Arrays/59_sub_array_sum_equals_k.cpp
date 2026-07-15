/*
    Problem: Subarray Sum Equals K
    Platform: LeetCode
    Link: https://leetcode.com/problems/subarray-sum-equals-k/
    Difficulty: Medium
    Approach: Prefix Sum + Hash Map — track frequency of each prefix sum seen so far, check if (currentSum - k) has occurred before
    Time: O(n)
    Space: O(n)
*/ 
#include<bits/stdc++.h>
using namespace std;
int checksum(vector<int>& arr,int k){
unordered_map<int,int> mp;
mp[0]=1;
int sum=0,count=0;
for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    int remainder=sum-k;
    if(mp.count(remainder)){
        count+=mp[remainder];
    }
    mp[sum]++;
}
return count;
}
int main(){
    vector<int> arr={1,3,1,2,4};
    int k=6;
  int result=checksum(arr,k);
  cout << result;
}