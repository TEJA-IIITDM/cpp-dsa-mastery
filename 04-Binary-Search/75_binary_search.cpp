/*
    Problem: Binary Search
    Platform: LeetCode
    Link: https://leetcode.com/problems/binary-search/
    Difficulty: Easy
    Approach: Binary Search — repeatedly halve the search space by comparing target with the middle element, narrowing left or right based on comparison
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& arr,int k){
int low=0,high=arr.size()-1;
while(low<=high){
   int mid=low+(high-low)/2;
   if(arr[mid]==k) return mid;
    else if(arr[mid]>k) high=mid-1;
     else low=mid+1; 
}
return -1;
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    int target=6;
    int result=binarysearch(arr,target);
    cout << result;
}