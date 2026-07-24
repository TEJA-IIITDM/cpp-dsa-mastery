/*
    Problem: Kth Missing Positive Number
    Platform: LeetCode
    Link: https://leetcode.com/problems/kth-missing-positive-number/
    Difficulty: Easy
    Approach: Binary Search — at each index, compute how many numbers are missing so far (arr[i]-(i+1)), find where this count first becomes >= k, answer = low + k
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int kthmissingnumber(vector<int>& arr,int k){
  int low=0,high=arr.size()-1;
  while(low<=high){
  int mid=low+(high-low)/2;
   int missingcount=arr[mid]-(mid+1);
   if(missingcount<k){
    low=mid+1;
   }
   else high=mid-1;
  }
  return low+k;
}
int main(){
  vector<int> arr={2,3,4,7,11};
  int k=5;
  int result=kthmissingnumber(arr,k);
  cout << result;
}
