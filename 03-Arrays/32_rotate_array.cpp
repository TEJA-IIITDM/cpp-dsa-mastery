/*
    Problem: Rotate Array (Right Rotate by K Positions)
    Platform: LeetCode
    Link: https://leetcode.com/problems/rotate-array/
    Difficulty: Medium
    Approach: Reversal Algorithm — reverse whole array, reverse first k, reverse remaining n-k
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[5] = {1, 2, 3, 4, 5};
  int n = 5;
  int k;
  cout << "enter the value of k: ";
  cin >> k;
  if(n == 0) return 0;
  k=(k%n+n)%n;
  reverse(arr+n-k, arr+n);
  reverse(arr, arr+n-k);
  reverse(arr, arr+n);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}