/*
    Problem: Longest Subarray with Sum K (handles negatives)
    Platform: self practice
    Link: N/A
    Difficulty: Medium
    Approach: Prefix Sum + Hash Map — store first occurrence of each prefix sum, check if (currentSum - k) was seen before
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr={2,3,5,1,9};
    unordered_map<int,int> mp;
    int k=5,prefixsum=0,maxlen=0;
    for(int i=0;i<arr.size();i++){
        prefixsum+=arr[i];
        if(prefixsum==k) maxlen=max(maxlen,i+1);
        int remainder=prefixsum-k;
        if(mp.find(remainder)!=mp.end()) maxlen=max(maxlen,i-remainder);
        if(mp.find(prefixsum)==mp.end()) mp[prefixsum]=i;
    }
    cout << maxlen;
}