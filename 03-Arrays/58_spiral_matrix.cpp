/*
    Problem: Spiral Matrix
    Platform: LeetCode
    Link: https://leetcode.com/problems/spiral-matrix/
    Difficulty: Medium
    Approach: Four shrinking boundaries (top, bottom, left, right) — traverse right, down, left, up in a loop, shrinking boundaries after each direction
    Time: O(rows * cols)
    Space: O(1) extra (excluding output array)
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> spiral (vector<vector<int>>& matrix){
   int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
   vector<int> ans;
   while(left<=right && top<=bottom){
   for(int j=left;j<=right;j++){
    ans.push_back(matrix[top][j]);
   }
   top++;
   for(int i=top;i<=bottom;i++){
    ans.push_back(matrix[i][right]);
   }
   right--;
   if(top<=bottom){
   for(int j=right;j>=left;j--){
   ans.push_back(matrix[bottom][j]);
   }
    bottom--;
}
   if(left<=right){
   for(int i=bottom;i>=top;i--){
    ans.push_back(matrix[i][left]);
   }
   left++;
}
}
return ans;
}
int main(){
    int row,col;
    cout << "enter the rows";
    cin >> row;
    cout << "enter the columns";
    cin >> col;
    vector<vector<int>> matrix(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> matrix[i][j];
        }
    }
    vector<int> result=spiral(matrix);
    for(int x : result){
        cout << x << " ";
    }
}