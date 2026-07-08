/*
    Problem: Move Zeroes
    Platform: LeetCode
    Link: https://leetcode.com/problems/move-zeroes/
    Difficulty: Easy
    Approach: Two Pointer — j tracks next position for a non-zero element, swap when arr[i] != 0, preserves relative order
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[5] = {0,1,0,3,12};
  int n = sizeof(arr)/sizeof(arr[0]);
  int j = 0;
  for(int i = 0; i < n; i++){
    if(arr[i] != 0){
     swap(arr[i], arr[j]);
     j++;
    }
  }
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << j;
}