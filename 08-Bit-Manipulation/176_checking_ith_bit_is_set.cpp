/*
    Problem: Check i-th Bit is Set or Not
    Platform: Self Practice
    Difficulty: Easy
    Approach: Bit Manipulation — Bitwise AND with left-shifted mask (1 << i) or right-shifting (n >> i) & 1
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
bool checkithbitset(int n,int i){
    if(((n >> i) & 1)!=0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n=5;
    int i=0;
    bool result=checkithbitset(n,i);
    cout<<result<<endl;
}