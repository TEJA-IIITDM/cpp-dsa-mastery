/*
    Problem: Merge Sorted Array
    Platform: LeetCode
    Link: https://leetcode.com/problems/merge-sorted-array/
    Difficulty: Easy
    Approach: Merge from the back using three pointers (i for arr1, j for arr2, k for write position), then drain any remaining elements from arr2
    Time: O(m+n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
 vector<int> arr1={1,3,5,0,0,0};
 vector<int> arr2={2,4,6};
 int m=3;
 int n=3;
int i=m-1;
int j=n-1;
int k=(m+n)-1;
while(i>=0 && j>=0){
  if(arr1[i]<=arr2[j]){
    arr1[k--]=arr2[j--];
  }
  else{
    arr1[k--]=arr1[i--];
  }
}
while(j>=0){
  arr1[k--]=arr2[j--];
}
for(int x : arr1){
  cout << x << " ";
}
}