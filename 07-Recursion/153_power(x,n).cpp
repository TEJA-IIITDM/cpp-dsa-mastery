/*
    Problem: Pow(x, n) - Binary Exponentiation
    Platform: LeetCode
    Link: https://leetcode.com/problems/powx-n/
    Difficulty: Medium
    Approach: Recursive Divide & Conquer (Binary Exponentiation) — square the base when power is even, multiply once when odd, cast n to 64-bit long long to prevent INT_MIN overflow
    Time: O(log N)
    Space: O(log N) auxiliary call stack space
*/
#include<bits/stdc++.h>
using namespace std;
double solvepower(double x,long long n){ 
if(n==0) return 1.0;
if(n%2==0) return solvepower(x*x,n/2);
else{
    return x*solvepower(x,n-1);
}
}
double power(double x,int n){
    long long N=n;
    if(N<0){
        x=1.0/x;
        N=-N;
    }
    return solvepower(x,N);
}
int main(){
    double x=2.00000;
    int n=10;
    cout << power(x,n);
}