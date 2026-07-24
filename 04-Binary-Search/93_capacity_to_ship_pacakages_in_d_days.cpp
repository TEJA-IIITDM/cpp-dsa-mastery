/*
    Problem: Capacity to Ship Packages Within D Days
    Platform: LeetCode
    Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible capacities, greedily count days needed at each capacity, search left (smaller capacity) on success
    Time: O(n log(sum(weights)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int check(vector<int>& weights,int mid){
  long long sum=0;
  int days=1;
  for(int x : weights){
   if(sum+x>mid){
    days++;
    sum=0;
   }
   sum+=x;
  }
  return days;
}
int mincapacity(vector<int>& weights,int days){
int low=*max_element(weights.begin(),weights.end());
long long high=accumulate(weights.begin(),weights.end(),0LL);
int ans=high;
while(low<=high){
  int mid=low+(high-low)/2;
  if(check(weights,mid)<=days){
    ans=mid;
    high=mid-1;
  }
  else low=mid+1;
}
return ans;
}
int main(){
  vector<int> weights={1,2,3,1,1};
  int days=4;
  int result=mincapacity(weights,days);
  cout << result;
}
