/*
    Problem: Median in a Row-Wise Sorted Matrix
    Platform: self practice
    Link: N/A
    Difficulty: Hard
    Approach: Binary Search on Answer — binary search over possible values, count elements <= mid across all rows using upper_bound, find smallest value where count reaches (n*m)/2 + 1
    Time: O(n log m log(max-min))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int>& row,int mid){
    int low=0,high=row.size()-1;
    int ans=row.size();
    while(low<=high){
        int m=low+(high-low)/2;
        if(row[m]>mid){
            ans=m;
            high=m-1;
        }
        else{
            low=m+1;
        }
    }
    return ans;
}
int countLessEqual(vector<vector<int>>& matrix,int mid,int m,int n){
    int count=0;
    for(auto &row:matrix){
        count+=upper_bound(row,mid);
    }
    return count;
}
int median(vector<vector<int>>& matrix,int m,int n){
    int low=INT_MAX,high=INT_MIN;
    for(int i=0;i<m;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][n-1]);
    }
    int required=(m*n+1)/2;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(countLessEqual(matrix,mid,m,n)>=required){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<vector<int>> matrix={
        {1,3,5},
        {2,6,9},
        {3,6,9}
    };
    int m=matrix.size(),n=matrix[0].size();
    cout<<median(matrix,m,n)<<endl;
}