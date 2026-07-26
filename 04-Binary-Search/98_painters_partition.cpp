/*
    Problem: Painter's Partition Problem
    Platform: self practice (GeeksforGeeks/Coding Ninjas)
    Link: N/A
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible max painting time per painter, greedily count painters needed, search left (smaller threshold) on success
    Time: O(n log(sum(boards)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>& boards,int mid,int k){
 long long sum=0;
 int count=1;
  for(int i=0;i<boards.size();i++){
    if(sum+boards[i]<=mid){
        sum+=boards[i];
    }
    else{
        count++;
        sum=boards[i];
    }
  }
  return count<=k;
}
int painterstime(vector<int>& boards,int k){
 int low=*max_element(boards.begin(),boards.end());
 int high=accumulate(boards.begin(),boards.end(),0);
 int ans=high;
 while(low<=high){
    int mid=low+(high-low)/2;
   if(ispossible(boards,mid,k)){
    ans=mid;
    high=mid-1;
   }
   else{
    low=mid+1;
   }
 }
 return ans;
}
int main(){
    vector<int> boards={10,20,30,40};
    int k=2;
   int result=painterstime(boards,k);
   cout << result;
}