/*
    Problem: Find Missing Number in Array (1 to n) - XOR Approach
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: XOR — XOR all numbers 1 to n with all array elements, matching pairs cancel out leaving the missing number
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int ans(vector<int>& arr,int m){
    int xorall=0,xorarr=0;
    for(int x : arr) xorarr^=x;
    for(int i=0;i<=m;i++) xorall^=i;
    return xorall^xorarr;
}
int main(){
    vector<int> arr={4,2,1};
    int m=arr.size()+1;
    int element=ans(arr,m);
    cout << element;
}