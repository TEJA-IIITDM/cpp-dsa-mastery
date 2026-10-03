/*
    Problem: Check Odd or Even
    Platform: Self Practice
    Difficulty: Easy
    Approach: Bit Manipulation — check least significant bit (LSB) using bitwise AND (n & 1)
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
bool checknumberisodd(int n){
    if((n & 1)!=0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n=5;
    bool result=checknumberisodd(n);
    cout<<result<<endl;
}