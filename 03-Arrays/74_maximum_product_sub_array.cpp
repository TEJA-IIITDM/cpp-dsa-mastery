/*
    Problem: Maximum Product Subarray
    Platform: LeetCode
    Link: https://leetcode.com/problems/maximum-product-subarray/
    Difficulty: Medium
    Approach: Prefix and Suffix Product — track running product from both ends, reset to 1 whenever the running product hits 0, track max seen
    Time: O(n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int productarray(vector<int>& arr){
    int i=0;
    if(arr.size()==1) return arr[i];
    int pre=1,suf=1;
    int maxi=INT_MIN;
    for(i;i<arr.size();i++){
    if(pre==0) pre=1;
    if(suf==0) suf=1;
    pre*=arr[i];
    suf*=arr[arr.size()-i-1];
    maxi=max(maxi,max(pre,suf));
    }
    return maxi;
}
int main() {
    vector<int> arr = {-2,3,2,4};
    int res = productarray(arr);
    cout << res << '\n';
    return 0;
}