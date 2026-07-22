/*
    Problem: Find Peak Element
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-peak-element/
    Difficulty: Medium
    Approach: Binary Search on Slope — compare arr[mid] with arr[mid+1] to determine slope direction and eliminate the side without a peak
    Time: O(log n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int peak(vector<int>& arr){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]<arr[mid+1]) low=mid+1;
        else high=mid;
    }
    return low;
}
int main() {
    vector<int> arr={1,2,1,3,5,6,4};
    int result=peak(arr);
    cout << result;
}