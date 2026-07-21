/*
    Problem: Search in Rotated Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
    Difficulty: Medium
    Approach: Modified Binary Search — determine which half (left or right of mid) is properly sorted using arr[low]<=arr[mid], then check if target falls within that sorted half's range to decide which side to search
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr,int target){
int low=0,high=arr.size()-1;
while(low<=high){
    int mid=low+(high-low)/2;
   if(arr[mid]==target) return mid;
   else if(arr[low]<=arr[mid]){
    if(arr[low]<=target && target<arr[mid]){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
   }
   else{
     if(arr[mid]<target && target<=arr[high]){
        low=mid+1;
     }
     else{
      high=mid-1;
     }
   }
} 
return -1;
}
int main(){
    vector<int> arr={7,8,9,1,2,3,4,5,6};
    int target=9;
   int result=search(arr,target);
   cout << result;
}
