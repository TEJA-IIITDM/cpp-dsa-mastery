/*
    Problem: Number of 1 Bits / Count Set Bits (LeetCode 191)
    Platform: LeetCode
    Link: https://leetcode.com/problems/number-of-1-bits/
    Difficulty: Easy
    Approach: Bit Manipulation — Brian Kernighan's Algorithm repeatedly clears the lowest set bit using n & (n - 1)
    Time: O(K) where K is the number of set bits
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int countsetbits(int n){
    int count=0;
    while(n>0){
        n=n&(n-1);
        count++;
    }
    return count;
}
int main(){
    int n=5;
    int result=countsetbits(n);
    cout<<result<<endl;
}