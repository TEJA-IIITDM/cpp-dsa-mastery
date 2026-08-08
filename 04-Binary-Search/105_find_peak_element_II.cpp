/*
    Problem: Find Peak Element II (2D Matrix)
    Platform: LeetCode
    Link: https://leetcode.com/problems/find-a-peak-element-ii/
    Difficulty: Hard
    Approach: Binary Search on Columns — for each candidate column, find the row with the max value in that column, then check left/right neighbors to decide direction
    Time: O(numRows * log(numCols))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int maxrow(vector<vector<int>>& matrix,int mid,int m){
    int maxrow=0;
    for(int i=0;i<m;i++){
       if(matrix[mid][i]>matrix[mid][maxrow]){
           maxrow=i;
       }
    }
    return maxrow;
}
vector<int> peakelement(vector<vector<int>>& matrix, int m, int n){
    int low=0,high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int maxrow_index=maxrow(matrix, mid, n);
        int left=(mid-1>=0) ? matrix[maxrow_index][mid-1] :-1;
        int right=(mid+1<m) ? matrix[maxrow_index][mid+1] :-1;
      if(matrix[maxrow_index][mid]>left && matrix[maxrow_index][mid]>right){
        return {maxrow_index,mid};
      }
      else if(left>matrix[maxrow_index][mid]){
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return {-1,-1};
}
int main (){
    vector<vector<int>> matrix={
        {10,20,15},
        {21,30,14},
        {7,16,32}
    };
    int m=matrix.size(),n=matrix[0].size();
    vector<int> ans=peakelement(matrix,m,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}