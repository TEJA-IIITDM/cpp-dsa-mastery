/*
    Problem: Aggressive Cows
    Platform: self practice (GeeksforGeeks/Coding Ninjas)
    Link: N/A
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible minimum distances, greedily check if k cows can be placed with at least that distance apart, search right (larger distance) on success
    Time: O(n log(max(stalls)-min(stalls)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
bool isenoughplacing(vector<int> & stalls,int cows,int d){
  int count=1,lastposition=stalls[0];
  for(int i=0;i<stalls.size();i++){
    if((stalls[i]-lastposition)>=d){
      count++;
      lastposition=stalls[i];
    }
    if(count>=cows) return true;
  }
  return false;
}
int placingcows(vector<int>& stalls,int cows){
  if(cows>stalls.size()) return -1;
   sort(stalls.begin(),stalls.end());
   int low=1,high=stalls.back() - stalls.front();
   int ans=0;
   while(low<=high){
    int mid=low+(high-low)/2;
   if(isenoughplacing(stalls,cows,mid)){
     ans=mid;
     low=mid+1;
   }
    else high=mid-1;
   }
   return ans;
}
int main(){
  vector<int> stalls={1,2,4,8,9};
  int cows=3;
  int result=placingcows(stalls,cows);
  cout << result;
}