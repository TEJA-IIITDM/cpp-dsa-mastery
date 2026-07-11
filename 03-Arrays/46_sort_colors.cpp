/*
    Problem: Sort Colors
    Platform: LeetCode
    Link: https://leetcode.com/problems/sort-colors/
    Difficulty: Medium
    Approach: Dutch National Flag Algorithm — three pointers (low, mid, high) partition array into 0s, 1s, 2s in one pass
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={0,2,1,2,0,1};
    int low=0,mid=0,high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
         mid++;
        }
        else {
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";;
    }
}