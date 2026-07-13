/*
    Problem: Leaders in an Array
    Platform: self pratice
    Link: NA
    Difficulty: Easy
    Approach: Scan from Right — keep track of the maximum element from the right side; if current element is larger, it's a leader
    Time: O(n)
    Space: O(1) auxiliary space (excluding ans vector)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();
    vector<int> ans;
    ans.push_back(arr[n-1]);
    int max=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max){
            ans.push_back(arr[i]);
            max=arr[i];
        }
    }
    for(auto it : ans){
        cout << it << " ";
    }
}