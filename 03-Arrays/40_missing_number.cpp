/*
    Problem: Missing Number
    Platform: LeetCode
    Link: https://leetcode.com/problems/missing-number/
    Difficulty: Easy
    Approach: Sum Formula — expected sum of 0 to n minus actual array sum gives missing number
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int ans(vector<int>& arr,int m){
    int sum=m*(m+1)/2;
    int sum1=0;
    for(int x : arr) sum1+=x;
    return sum-sum1;
}
int main(){
    vector<int> arr={4,2,1};
    int m=arr.size()+1;
    int element=ans(arr,m);
    cout << element;
}