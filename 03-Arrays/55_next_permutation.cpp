/*
    Problem: Next Permutation
    Platform: LeetCode
    Link: https://leetcode.com/problems/next-permutation/
    Difficulty: Medium
    Approach: Find rightmost pivot where arr[i] < arr[i+1], swap with smallest greater element to its right, reverse the suffix after pivot
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={0,1,2,4,5,7};
    int n=arr.size();
   int pivot=-1;
   for(int i=n-2;i>=0;i++){
    if(arr[i]<arr[i+1]){
        pivot=i;
        break;
    }
   }
   if(pivot==-1){
    reverse(arr.begin(),arr.end());
   }
   for(int i=n-1;i>=0;i++){
    if(arr[i]>arr[pivot]){
        swap(arr[pivot],arr[i]);
        break;
    }
   }
   reverse(arr.begin()+pivot+1,arr.end());
   for(int x : arr){
    cout << x << " ";
   }
   
}