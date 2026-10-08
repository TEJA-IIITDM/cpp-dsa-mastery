/*
    Problem: Find XOR of Numbers in Range [L, R]
    Platform: Self Practice / GeeksforGeeks
    Difficulty: Easy
    Approach: Bit Manipulation — compute prefix XORs using modulo-4 sequence pattern: XOR(L..R) = XOR(1..R) ^ XOR(1..L-1)
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int xorrange(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}
int xorr(int l,int r){
return xorrange(l-1)^xorrange(r);
}
int main(){
int l=3,r=5;
int result=xorr(l,r);
cout << result;
}