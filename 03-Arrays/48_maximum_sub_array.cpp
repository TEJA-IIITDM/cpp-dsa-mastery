/*
    Problem: Maximum Subarray
    Platform: LeetCode
    Link: https://leetcode.com/problems/maximum-subarray/
    Difficulty: Medium
    Approach: Kadane's Algorithm — maintain running sum, reset to 0 whenever it goes negative, track max along the way
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={ -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxi=INT32_MIN,sum=0;
    for(int x : arr){
        sum+=x;
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    cout << maxi;
}
