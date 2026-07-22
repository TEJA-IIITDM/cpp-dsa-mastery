/*
    Problem: Sqrt(x)
    Platform: LeetCode
    Link: https://leetcode.com/problems/sqrtx/
    Difficulty: Easy
    Approach: Binary Search — search space [1, x/2], track largest mid where mid * mid <= x, cast to long long to prevent integer overflow
    Time: O(log x)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int squareroot(int x){
    if(x<2) return x;
    int low=1,high=x/2;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if((long long)mid*mid<=x){
           ans=mid;
           low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
int main() {
    int x=36;
    int result=squareroot(x);
    cout << result;
}