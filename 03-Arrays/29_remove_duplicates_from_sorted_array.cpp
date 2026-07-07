/*
    Problem: Remove Duplicates from Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    Difficulty: Easy
    Approach: Two Pointer — slow pointer marks last unique position, fast pointer scans ahead
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int removeduplicates(vector<int>& arr, int n){
    if(n == 0) return 0;
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
int main(){
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();
    int result = removeduplicates(arr, n);
    for(int i=0;i<result;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
