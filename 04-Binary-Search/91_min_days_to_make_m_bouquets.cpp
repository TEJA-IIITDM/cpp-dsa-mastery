/*
    Problem: Minimum Number of Days to Make m Bouquets
    Platform: LeetCode
    Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible days, check if at least m bouquets (each needing k adjacent bloomed flowers) can be made by that day
    Time: O(n log(max(bloomDay)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int findflowers(vector<int>& bloomday,int mid,int k){
int count=0,boquets=0;
for(int flower : bloomday){
    if(flower<=mid){
        count++;
        if(count==k){
         boquets++;
          count=0;
    }
    }
    else{
        count=0;
    }
}
return boquets;
}
int mindays(vector<int>& bloomday,int m,int k){
long long need=(long long)m*k;
if(need>(long long)bloomday.size()) return -1;
int low=*min_element(bloomday.begin(),bloomday.end());
int high=*max_element(bloomday.begin(),bloomday.end());
int ans=high;
while(low<=high){
    int mid=low+(high-low)/2;
    if(findflowers(bloomday,mid,k)>=m){
    ans=mid;
    high=mid-1;
    }
    else low=mid+1;

}
return ans;
}
int main(){
  vector<int> bloomday={7,7,7,7,12,7,7};
  int m=2,k=3;
  int days=mindays(bloomday,m,k);
  cout << days;
}
