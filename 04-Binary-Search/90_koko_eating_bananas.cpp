/*
    Problem: Koko Eating Bananas
    Platform: LeetCode
    Link: https://leetcode.com/problems/koko-eating-bananas/
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible eating speeds k (1 to max(piles)), check if total hours needed at that speed fits within h, using ceiling division and monotonic true/false pattern
    Time: O(n log(max(piles)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
long long findhours(vector<int>& piles,int k){
long long hours=0;
for(int p : piles){
    hours+=(p+k-1)/k;
}
return hours;
}
int minspeed(vector<int>& piles,int h){
int low=1,high=*max_element(piles.begin(),piles.end());
int ans=high;
while(low<=high){
    int mid=low+(high-low)/2;
    if(findhours(piles,mid)<=h){
        ans =mid;
        high=mid-1;
    }
    else low=mid+1;
}
return ans;
}
int main(){
  vector<int> piles={30,11,23,4,20};
  int h=5;
  int k=minspeed(piles,h);
  cout << k;
}
