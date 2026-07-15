/*
    Problem: Rotate Image
    Platform: LeetCode
    Link: https://leetcode.com/problems/rotate-image/
    Difficulty: Medium
    Approach: Transpose the matrix (swap across diagonal), then reverse each row — achieves 90 degree clockwise rotation in-place
    Time: O(n^2)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate(vector<vector<int>>& matrix){
   int n=matrix.size();
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      swap(matrix[j][i],matrix[i][j]);
    }
   }
   for(int i=0;i<n;i++){
    reverse(matrix[i].begin(),matrix[i].end());
   }
   return matrix; 
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
vector<vector<int>> rotated=rotate(matrix);
 for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           cout << rotated[i][j] << " ";
        }
       cout <<  endl;
    }
}