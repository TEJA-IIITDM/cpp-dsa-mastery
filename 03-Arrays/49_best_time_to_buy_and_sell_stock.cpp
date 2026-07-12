/*
    Problem: Best Time to Buy and Sell Stock
    Platform: LeetCode
    Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    Difficulty: Easy
    Approach: Single Pass — track minimum price seen so far, update max profit using (current price - min price so far)
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr= {7,1,5,3,6,4};
    int mini=INT_MAX,maxi=0;
    for(int x : arr){
    mini=min(mini,x);
    maxi=max(maxi,x-mini);
    }
    cout << maxi;
}
