/*
    Problem: Search a 2D Matrix
    Platform: LeetCode
    Link: https://leetcode.com/problems/search-a-2d-matrix/
    Difficulty: Medium
    Approach: Single Binary Search treating the matrix as a flattened 1D sorted array — convert between 1D index and (row,col) using division/modulo
    Time: O(log(m*n))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
string binarysearch(vector<vector<int>>& matrix,int m,int n,int target){
    int low=0,high=m*n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=mid/n,col=mid%n;
        if(matrix[row][col]==target){
            return "true";
        }
        else if(matrix[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return "false";
}
int main(){
    vector<vector<int>> matrix={
        {1, 1, 1},
        {4, 5, 6},
        {7, 8, 9}
    };
    int m=matrix.size(), n=matrix[0].size();
    int target=5;
    string search=binarysearch(matrix,m,n,target);
    cout << search << endl;
}