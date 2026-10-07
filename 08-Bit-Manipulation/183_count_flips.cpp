/*
    Problem: Minimum Bit Flips to Convert Number (LeetCode 2220)
    Platform: LeetCode
    Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
    Difficulty: Easy
    Approach: Bit Manipulation — XOR start and goal to isolate differing bits, then count set bits via Brian Kernighan's algorithm
    Time: O(K) where K is the number of set bits
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int countflips(int n){
    int count = 0;
    while(n>0){
        n= n & (n - 1);
        count++;
    }
    return count;
}
int main(){
int start=10,goal=7;
int num=start^goal;
int result=countflips(num);
cout<<result<<endl;
}