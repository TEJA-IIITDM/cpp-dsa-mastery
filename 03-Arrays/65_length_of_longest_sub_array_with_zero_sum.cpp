/*
    Problem: Length of the Longest Subarray with Zero Sum
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Medium
    Approach: Prefix Sum + Hash Map — store first occurrence of each prefix sum, if same prefix sum seen again, subarray between them sums to zero
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
  vector<int> arr={9, -3, 3, -1, 6, -5};
  unordered_map<int,int> mp;
  int sum=0;
  int maxi=0;
  for(int i=0;i<arr.size();i++){
  sum+=arr[i];
  if(sum==0){
    maxi=i+1;
  }
  else{
   if(mp.find(sum)!=mp.end()){
   maxi=max(maxi,i-mp[sum]);
   }
   else{
    mp[sum]=i;
   }
  }
  }
  cout << maxi;
}