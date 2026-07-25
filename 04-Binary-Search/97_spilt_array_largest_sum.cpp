/*
    Problem: Split Array Largest Sum
    Platform: LeetCode
    Link: https://leetcode.com/problems/split-array-largest-sum/
    Difficulty: Hard
    Approach: Binary Search on Answer — binary search over possible largest-subarray-sum thresholds, greedily count subarrays needed, search left (smaller threshold) on success
    Time: O(n log(sum(arr)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>& arr,int mid,int k){
    long long sum=0;
    int subarrays=1;
    for(int i=0;i<arr.size();i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            subarrays++;
            sum=arr[i];
        }
    }
    return subarrays<=k;
}
int spiltarray(vector<int>& arr,int k){
long long low=*max_element(arr.begin(),arr.end());
long long high=accumulate(arr.begin(),arr.end(),0LL);
long long ans=high;
while(low<=high){
    int mid=low+(high-low)/2;
  if(ispossible(arr,mid,k)){
    ans=mid;
    high=mid-1;
  }
  else low=mid+1;
}
return (int)ans;
}
int main() {
    vector<int> arr={7,2,5,10,8};
    int k=2;
    int result=spiltarray(arr,k);
    cout << result;
}