/*
    Problem: Greedy Coin Change / Find Minimum Number of Coins (GFG)
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/number-of-coins1824/1
    Difficulty: Easy
    Approach: Greedy Strategy — iterate denominations in descending order and greedily pick largest valid coin
    Time: O(V) where V is the total coins picked
    Space: O(1) auxiliary space
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> coinchange(int n,vector<int> coins){
    vector<int> result;
    sort(coins.begin(),coins.end());
    for(int i=coins.size()-1;i>=0;i--){
        while(n>=coins[i]){
            result.push_back(coins[i]);
            n-=coins[i];
        }
    }
    return result;
}

int main() {
    int n=121;
    vector<int> coins={1,2,5,10,20,50,100,500,1000};
    vector<int> ans=coinchange(n, coins);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}