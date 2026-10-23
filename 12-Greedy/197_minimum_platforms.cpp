/*
    Problem: Minimum Platforms / Meeting Rooms II
    Platform: Self Practice
    Link: N/A
    Difficulty: Medium
    Approach: Greedy Two Pointers / Timeline Sweep — sort arrival and departure endpoints independently to calculate peak concurrent overlapping intervals
    Time: O(N log N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
int minimumplatforms(vector<int> arr,vector<int> dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int platforms=1;
    int result=1;
    int i=1,j=0;
    while(i<arr.size() && j<dep.size()){
        if(arr[i]<=dep[j]){
            platforms++;
            i++;
            result=max(result,platforms);
        }
        else{
            platforms--;
            j++;
        }
    }
    return result;
}
int main(){
     vector<int> arr={900,945,955,1100,1500,1800};
     vector<int> dep={920,1130,1150,1200,1900,2000};
     int result=minimumplatforms(arr,dep);
     cout<<result<<endl;
}