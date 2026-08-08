/*
    Problem: Search a 2D Matrix II
    Platform: LeetCode
    Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
    Difficulty: Medium
    Approach: Staircase Search — start at the top-right corner (or bottom-left); move left if current element > target, or move down if current element < target
    Time: O(m + n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
string searchmatrix(vector<vector<int>>& matrix,int m,int n,int target) {
 int low=0,high=n-1;
 while(low<m && high>=0) {
     if(matrix[low][high]==target) {
         return "true";
     }
     else if(matrix[low][high]<target) {
         low++;
     }
     else {
         high--;
     }
 }
 return "false";
}
int main (){
    vector<vector<int>> matrix={
        {1,4,7,11},
        {2,5,8,12},
        {3,6,9,16},
        {10,13,14,17}
    };
    int target=5;
    int m=matrix.size(), n=matrix[0].size();
    cout<<searchmatrix(matrix,m,n,target);
}