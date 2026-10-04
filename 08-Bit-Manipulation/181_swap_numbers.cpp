/*
    Problem: Swap Two Numbers
    Platform: Self Practice / GeeksforGeeks
    Difficulty: Easy
    Approach: Bit Manipulation — use bitwise XOR properties (a ^ a = 0) to swap values in-place without extra storage or overflow risk
    Time: O(1)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=5;
    int b=7;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<" b="<<b;
}
