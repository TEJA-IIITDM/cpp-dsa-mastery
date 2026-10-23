/*
    Problem: Shortest Job First (SJF) Scheduling
    Platform: Self Practice 
    Link: N/A
    Difficulty: Medium
    Approach: Greedy Choice — sort process burst times in ascending order to minimize overall total waiting time
    Time: O(N log N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
long long shortestjobfirst(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    long long totaltime=0;
    long long waitingtime=0;
    for(int i=0;i<arr.size();i++){
       waitingtime+=totaltime;
       totaltime+=arr[i];
    } 
    return waitingtime/arr.size();
}
int main(){
    vector<int> arr={3,1,4,2,5};
    long long averagewaitingtime=shortestjobfirst(arr);
    cout<<"Average waiting time is: "<<averagewaitingtime<<endl;
}