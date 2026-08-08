/*
    Problem: Find the Row with Maximum Number of 1's
    Platform: GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
    Difficulty: Easy
    Approach: Binary Search per row — since each row is sorted, use upper bound/lower bound to find the first 1 in each row via binary search, track row with maximum count of 1s
    Time: O(n log m)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& arr,int m){
    int low=0,high=m-1;
    int ans=m;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==1){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int maximumones(vector<vector<int>>& matrix,int m,int n){
    int max_ones=0;
    int rowindex=-1;
    for(int i=0;i<m;i++){
        int firstone=binarysearch(matrix[i],n);
        int ones=n-firstone;
        if(ones>max_ones){
            max_ones=ones;
            rowindex=i;
        }
    }
    return rowindex;
}
int main(){
    vector<vector<int>> matrix={
        {0, 0, 0},
        {0, 1, 1}
    };
    int m=matrix.size(), n=matrix[0].size();
    cout << maximumones(matrix, m, n) << endl;
}