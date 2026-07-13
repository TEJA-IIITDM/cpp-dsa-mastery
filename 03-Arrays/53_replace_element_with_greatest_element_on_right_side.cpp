/*
    Problem: Replace Elements with Greatest Element on Right Side
    Platform: LeetCode
    Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
    Difficulty: Easy
    Approach: Scan from Right — maintain the maximum value encountered from right to left, replacing the current element with the max value before updating it
    Time: O(n)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();
    vector<int> ans;
    int max=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            int temp=arr[i];
            arr[i]=max;
            max=temp;
        }
        else arr[i]=max;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}