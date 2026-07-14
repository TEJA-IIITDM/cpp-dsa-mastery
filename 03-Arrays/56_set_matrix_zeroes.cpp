/*
    Problem: Set Matrix Zeroes
    Platform: LeetCode
    Link: https://leetcode.com/problems/set-matrix-zeroes/
    Difficulty: Medium
    Approach: Use first row and first column of matrix itself as marker storage, track first column separately with a flag
    Time: O(rows * cols)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void setzeroes(vector<vector<int>>& matrix){
    int row=matrix.size(),col=matrix[0].size();
    bool colzero=false;
  for(int i=0;i<row;i++){
    if(matrix[i][0]==0) colzero=true;
    for(int j=1;j<col;j++){
        if(matrix[i][j]==0){
            matrix[i][0]=0;
            matrix[0][j]=0;
        }
    }
  }
  for(int i=1;i<row;i++){
    for(int j=1;j<col;j++){
        if(matrix[i][0]==0 || matrix[0][j]==0){
            matrix[i][j]=0;
        }
    }
  }
  
if(matrix[0][0]==0){
    for(int i=0;i<col;i++){
        matrix[0][i]=0;
    }
}
if(colzero){
    for(int i=0;i<row;i++){
         matrix[i][0]=0;
    }
  }

}
void print(vector<vector<int>>& matrix){
    int r=matrix.size(),c=matrix[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int row,col;
    cout << "enter the rows";
    cin >> row;
    cout << "enter column";
    cin >> col;
    vector<vector<int>> matrix(row,vector<int>(col));
    cout << "enter elements";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> matrix[i][j];
        }
    }
    print(matrix);
    setzeroes(matrix);
    print(matrix);
}