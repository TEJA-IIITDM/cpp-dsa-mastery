/*
    Problem: Merge Intervals (LeetCode 56)
    Platform: Leetcode
    Link: https://leetcode.com/problems/merge-intervals/
    Difficulty: Medium
    Approach: Sorting & Greedy Merge — sort intervals by start time and iteratively extend or commit intervals
    Time: O(N log N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeintervals(vector<vector<int>> intervals){
    if(intervals.empty()) return {};
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> result;
    vector<int> last=intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(last[1]>=intervals[i][0]){
            last[1]=max(last[1],intervals[i][1]);
        }
        else{
           result.push_back(last);
           last=intervals[i];
        }
    }
    result.push_back(last);
    return result;
}
int main(){
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result=mergeintervals(intervals);
    for(auto i:result){
        cout << i[0] << " " << i[1] << endl;
       }
}