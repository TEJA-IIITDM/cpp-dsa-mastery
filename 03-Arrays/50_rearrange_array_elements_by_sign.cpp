/*
    Problem: Rearrange Array Elements by Sign
    Platform: LeetCode
    Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
    Difficulty: Medium
    Approach: Two-Pointer Pass — pre-allocate array, place positive numbers at even indices and negative at odd indices
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
    vector<int> arr={1,2,-4,-5};
    int n=arr.size();
  vector<int> ans(n,0);
  int pos=0,neg=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
        ans[pos]=arr[i];
        pos+=2;
        }
        else{
          ans[neg]=arr[i];
          neg+=2;
        }
    }
    for(int x : ans){
        cout << x << " ";
    }
}