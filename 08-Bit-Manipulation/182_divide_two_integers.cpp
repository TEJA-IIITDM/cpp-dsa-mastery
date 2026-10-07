/*
    Problem: Divide Two Integers (LeetCode 29)
    Platform: LeetCode
    Link: https://leetcode.com/problems/divide-two-integers/
    Difficulty: Medium
    Approach: Bit Manipulation / Exponential Subtraction — repeatedly subtract shifted multiples of divisor (d << count) using bitwise left shifts
    Time: O(log^2 N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int divide(int dividend,int divisor){
    if(dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    int sign=1;
    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
        sign=-1;
    }
    long long ldividend=abs((long long)dividend);
    long long ldivisor=abs((long long)divisor);
    long long result=0,sum=0;
    while(ldividend>=ldivisor){
        long long temp=ldivisor,multiple=1;
        while(temp<<1 <= ldividend){
            temp<<=1;
            multiple<<=1;
        }
        ldividend-=temp;
        result+=multiple;
    }
    if(result>INT_MAX){
        return sign==1?INT_MAX:INT_MIN;
    }
    return sign*result;
}
int main(){
    int dividend=10,divisor=3;
    int result=divide(dividend,divisor);
    cout<<result;
}
