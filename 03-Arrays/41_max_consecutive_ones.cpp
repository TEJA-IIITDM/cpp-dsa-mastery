/*
    Problem: Max Consecutive Ones
    Platform: LeetCode
    Link: https://leetcode.com/problems/max-consecutive-ones/
    Difficulty: Easy
    Approach: Single Pass — track running count of consecutive 1s, reset to 0 on encountering a 0, update max along the way
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={1,1,1,1,0,1};
    int count=0;
    int maxcount=0;
    for(int i=0;i<arr.size();i++){
    if(arr[i]==1){
        count++;
        maxcount=max(maxcount,count);
    }
    else{
        count=0;
    }
    }
    cout << maxcount;
}