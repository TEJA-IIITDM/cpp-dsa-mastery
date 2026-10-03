/*
    Problem: Power of Two (LeetCode 231)
    Platform: LeetCode
    Link: https://leetcode.com/problems/power-of-two/
    Difficulty: Easy
    Approach: Bit Manipulation — clear the lowest set bit using n & (n - 1); a power of two has strictly one set bit
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
bool checkpoweroftwo(int n){
    return n>0 && n&(n-1)==0;
}
int main(){
    int n=5;
    bool result=checkpoweroftwo(n);
    cout<<result<<endl;
}