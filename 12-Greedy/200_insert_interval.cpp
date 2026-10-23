/*
    Problem: Insert Interval (LeetCode 57)
    Platform: Leetcode
    Link: https://leetcode.com/problems/insert-interval/
    Difficulty: Medium
    Approach: Three-Phase Linear Sweep — corrected third loop iteration index increment
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insertinterval(vector<vector<int>> intervals,vector<int> newinterval){
    int n=intervals.size();
    vector<vector<int>> result;
    int i=0;
    while(i<n && intervals[i][1]<newinterval[0]){
        result.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=newinterval[1]){
        newinterval[0]=min(intervals[i][0],newinterval[0]);
        newinterval[1]=max(intervals[i][1],newinterval[1]);
        i++;
    }
    result.push_back(newinterval);
    while(i<n){
        result.push_back(intervals[i]);
        i++;
    }
return result;
}
int main(){
    vector<vector<int>> intervals={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newinterval={4,8};
    vector<vector<int>> result=insertinterval(intervals,newinterval);
    for(auto i : result){
        cout << i[0] << " " << i[1] << endl;
    }
}