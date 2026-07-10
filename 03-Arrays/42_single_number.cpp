/*
    Problem: Single Number
    Platform: LeetCode
    Link: https://leetcode.com/problems/single-number/
    Difficulty: Easy
    Approach: XOR — XOR all elements together, every number appearing twice cancels out (a^a=0), leaving only the single unique number
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={4,1,1,2,2};
    int num=0;
    for(int i=0;i<arr.size();i++){
     num^=arr[i];
    }
cout << num;
}