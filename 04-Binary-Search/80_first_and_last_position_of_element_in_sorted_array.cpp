/*
    Problem: Find First and Last Position of Element in Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    Difficulty: Medium
    Approach: Binary Search — run two separate binary searches: one biased to the left to find the first occurrence, and one biased to the right for the last occurrence
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int occurence(vector<int>& arr,int k,bool isfirst){
 int low=0,high=arr.size()-1;
 int ans=-1;
 while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]==k){
    ans=mid;
    if(isfirst) high=mid-1;
     else low=mid+1;
   }
   else if(arr[mid]<k){
    low=mid+1;
   }
   else high=mid-1;
}
return ans;
}
int main(){
    vector<int> arr={3,4,13,13,13,20,40};
    int target=13;
    int first=occurence(arr,target,true);
    if(first==-1) cout << -1 << " " << -1;
    else {
         int last=occurence(arr,target,false);
    cout << first << " " << last;
    }
}
