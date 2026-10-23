/*
    Problem: Non-overlapping Intervals (LeetCode 435)
    Platform: Leetcode
    Link: https://leetcode.com/problems/non-overlapping-intervals/
    Difficulty: Medium
    Approach: Greedy Interval Selection — sort by end time ascending and remove intervals that start before prevEnd
    Time: O(N log N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int nonoverlappingintervals(vector<vector<int>> intervals){
    sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    });
    int count=0;
    int prevend=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<prevend){
            count++;
        }
        else{
            prevend=intervals[i][1];
        }
    }
    return count;
}
int main(){
    vector<vector<int>> intervals={{1,2},{2,3},{3,4},{1,3}};
    int result=nonoverlappingintervals(intervals);
    cout << result;
}