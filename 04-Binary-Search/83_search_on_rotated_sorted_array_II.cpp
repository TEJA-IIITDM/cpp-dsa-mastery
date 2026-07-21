/*
    Problem: Search in Rotated Sorted Array II
    Platform: LeetCode
    Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
    Difficulty: Medium
    Approach: Modified Binary Search — when arr[low]==arr[mid]==arr[high], shrink from both ends (ambiguous case due to duplicates), otherwise determine sorted half and check if target falls within its range
    Time: O(log n) average, O(n) worst case (due to duplicates)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
string search(vector<int>& arr,int target){
int low=0,high=arr.size()-1;
while(low<=high){
    int mid=low+(high-low)/2;
   if(arr[mid]==target) return "true";
   if(arr[low]==arr[mid] && arr[mid]==arr[high]){
    low++;
    high--;
   }
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
return "false";
}
int main(){
    vector<int> arr={3,1};
    int target=1;
   string result=search(arr,target);
   cout << result;
}
