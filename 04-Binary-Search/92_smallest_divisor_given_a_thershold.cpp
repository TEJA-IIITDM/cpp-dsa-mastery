/*
    Problem: Find the Smallest Divisor Given a Threshold
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible divisors, check if sum of ceiling divisions stays within threshold, search left (smaller divisor) on success
    Time: O(n log(max(arr)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
long long findsum(vector<int>& arr,int mid){
    long long sum=0;
    for(int x : arr){
        sum+=(x+mid-1)/mid;
    }
  return sum;
}
int finddivisor(vector<int>& arr,int thershold){
  if(arr.size()>thershold) return -1;
int low=1,high=*max_element(arr.begin(),arr.end());
int ans=high;
while(low<=high){
    int mid=low+(high-low)/2;
   if(findsum(arr,mid)<=thershold){
    ans=mid;
    high=mid-1;
   }
   else low =mid+1;
}
return ans;
}
int main(){
  vector<int> arr={1,2,3,4,5};
  int thershold=8;
  int result=finddivisor(arr,thershold);
}
