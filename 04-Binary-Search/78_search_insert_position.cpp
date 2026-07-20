/*
    Problem: Search Insert Position
    Platform: LeetCode
    Link: https://leetcode.com/problems/search-insert-position/
    Difficulty: Easy
    Approach: Binary Search (same as Lower Bound) — find leftmost index where arr[i] >= target, which is exactly the position where target exists or should be inserted
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& arr,int k){
int low=0,high=arr.size()-1;
int ans=arr.size();
while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]>=k){
    ans=mid;
    high=mid-1;
   }
   else low=mid+1;
   
}
return ans;
}
int main(){
    vector<int> arr={1,2,4,7};
    int target=6;
    int result=binarysearch(arr,target);
    cout << result;
}