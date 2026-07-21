/*
    Problem: Find Minimum in Rotated Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    Difficulty: Medium
    Approach: Modified Binary Search — determine which half is sorted; the sorted half's leftmost element is a candidate for minimum, then narrow toward the unsorted half which contains the true minimum
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int searchminimum(vector<int>& arr){
    int low=0,high=arr.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[high]<arr[mid]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return arr[low];
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int result=searchminimum(arr);
    cout << result;
}
