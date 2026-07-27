/*
    Problem: Minimise Maximum Distance between Gas Stations
    Platform: self practice (GeeksforGeeks/Coding Ninjas)
    Link: N/A
    Difficulty: Hard
    Approach: Binary Search on Answer (real-valued) — binary search over possible max gap sizes using fixed iteration count, for each gap calculate stations needed (ceil(gap/mid)-1), sum across all gaps, compare to k
    Time: O(n log(maxGap/precision))
    Space: O(1)
*/
#include<bits/stdc++.h> 
using namespace std;
bool ispossible(vector<int>& stations,double mid,int k){
  int count=0;
  for(int i=1;i<stations.size();i++){
    int gap=stations[i]-stations[i-1];
    count+=ceil(gap/mid)-1;
  }
  return count<=k;
}
int minimisemaxdistance(vector<int>& stations,int k){
double low=0,high=0;
for(int i=1;i<stations.size();i++){
    high=max(high,(double)stations[i]-stations[i-1]);
}
int iterations=100;
double ans=high;
while(iterations--){
    double mid=low+(high-low)/2;
  if(ispossible(stations,mid,k)){
    ans=mid;
    high=mid;
  }
  else low=mid;
}
return ans;
}
int main(){
    vector<int> stations={1,13,17,23};
    int k=5;
   double result=minimisemaxdistance(stations,k);
   cout << result;
}