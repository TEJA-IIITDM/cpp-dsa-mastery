/*
    Problem: Set Rightmost Unset Bit
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
    Difficulty: Easy
    Approach: Bit Manipulation — compute n | (n + 1) to flip the lowest 0 bit to 1
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int setrightmostbit(int n){
    return n | (n + 1);
}
int main(){
    int n=5;
    int result=setrightmostbit(n);
    cout<<result<<endl;
}