/*
    Problem: N Meetings in One Room
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
    Difficulty: Easy
    Approach: Greedy Interval Scheduling — sort meetings by end time ascending and select non-overlapping intervals
    Time: O(N log N)
    Space: O(N) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> n_meetings(vector<int> start,vector<int> end){
    vector<tuple<int,int,int>> meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({start[i],end[i],i+1});
    }
    sort(meetings.begin(),meetings.end(),[](const tuple<int,int,int>& a,const tuple<int,int,int>& b){
        if(get<1>(a)==get<1>(b)){
            return get<0>(a)<get<0>(b);
        }
        return get<1>(a)<get<1>(b);
    });
    vector<int> ans;
    int last_end_time=get<1>(meetings[0]);
    ans.push_back(get<2>(meetings[0]));
    for(auto m:meetings){
        if(get<0>(m)>last_end_time){
            ans.push_back(get<2>(m));
            last_end_time=get<1>(m);
        }
    }
    return ans;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    vector<int> ans=n_meetings(start,end);
    for(auto i:ans){
        cout<<i<<" ";
    }
}