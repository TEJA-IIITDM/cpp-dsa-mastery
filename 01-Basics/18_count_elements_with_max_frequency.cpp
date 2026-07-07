/*
    Problem: count elements with maximum frequency
    Platform: LeetCode
    Link: https://leetcode.com/problems/count-elements-with-maximum-frequency
    Difficulty: easy
    Approach: Hashing — unordered_map + find maxFreq then count all elements with that frequency
    Time: O(n)
    Space: O(n)
*/

// Time Complexity: O(n)
// Space Complexity: O(n) 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    unordered_map<int,int> mp;
    for(int x:arr){
        mp[x]++;
    }
    int max_freq=0;
    for(auto [key, value]:mp){
       max_freq=max(max_freq,value);
    }
    int count=0;
    for(auto [key, value]:mp){
        if(value==max_freq){
            count+=value;
        }
    }
    cout<<"The number of elements with the maximum frequency is: "<<count<<endl;
}

