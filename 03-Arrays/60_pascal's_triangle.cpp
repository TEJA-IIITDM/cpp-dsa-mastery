/*
    Problem: Pascal's Triangle
    Platform: LeetCode
    Link: https://leetcode.com/problems/pascals-triangle/
    Difficulty: Easy
    Approach: Build each row from the previous row — first/last are 1, middle values are sum of two values directly above
    Time: O(numRows^2)
    Space: O(numRows^2) for output (required, since that's the answer itself)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "enter the number";
    cin >> n;
    vector<vector<int>> triangle;
    for(int i=0;i<n;i++){
        vector<int> row(i+1,1);
        for(int j=1;j<i;j++){
         row[j]=triangle[i-1][j-1]+triangle[i-1][j];
          }
          triangle.push_back(row);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout << triangle[i][j];
            }
            cout << endl;
        }
    }