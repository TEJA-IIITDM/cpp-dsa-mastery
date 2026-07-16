/*
    Problem: Pascal's Triangle II
    Platform: LeetCode
    Link: https://leetcode.com/problems/pascals-triangle-ii/
    Difficulty: Easy
    Approach: Combinatorics Formula — C(rowIndex,i) = C(rowIndex,i-1) * (rowIndex-i+1) / i, computed directly without needing previous rows
    Time: O(rowIndex)
    Space: O(rowIndex) (excluding output, which is required)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int r;
    cout << "enter the rwo index";
    cin >> r;
    vector<int>row(r+1);
    row[0]=1;
    for(int i=1;i<=r;i++){
      row[i]=(long long)row[i-1]*(r-i+1)/i;
    }
  for(int x: row){
    cout << x << " ";
  }
}