/*
    Problem: Single Element in a Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
    Difficulty: Medium
    Approach: Modified Binary Search — pairs align at (even,odd) index positions before the single element and shift to (odd,even) after it; binary search for where this pattern breaks, with edge cases handled separately to avoid out-of-bounds access
    Time: O(log n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int findduplicate(vector<int>& arr){
int n=arr.size();
if(n==1) return arr[0];
if(arr[0]!=arr[1]) return arr[0];
if(arr[n-1]!=arr[n-2]) return arr[n-1]; 
int low=1,high=n-2;
while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];
    if((mid % 2 == 0 && arr[mid] == arr[mid+1]) || (mid % 2 == 1 && arr[mid] == arr[mid-1])){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
return -1;
}
int main() {
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    int result=findduplicate(arr);
    cout << result;
}