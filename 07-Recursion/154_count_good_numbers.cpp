/*
    Problem: Count Good Numbers
    Platform: LeetCode
    Link: https://leetcode.com/problems/count-good-numbers/
    Difficulty: Medium
    Approach: Modular Binary Exponentiation — calculate (5^even_positions * 4^odd_positions) % (10^9 + 7) using fast power algorithm
    Time: O(log n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long binarypower(long long base,long long exp){
long long result=1;
base=base%mod;
while(exp>0){
    if(exp&1){
            result=(result*base)%mod;
        }
        exp=exp>>1;
        base=(base*base)%mod;
    }
    return result;
}
long long countgoodnumbers(int n){
    long long evenpositions=(n+1)/2;
    long long oddpositions=n/2;
    long long evenways=binarypower(5,evenpositions);
    long long oddways=binarypower(4,oddpositions);
    return (evenways*oddways)%mod;
}
int main(){
    int n=4000;
    long long result=countgoodnumbers(n);
    cout << result;
}