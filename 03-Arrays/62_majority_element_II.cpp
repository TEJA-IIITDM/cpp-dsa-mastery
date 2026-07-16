/*
    Problem: Majority Element II
    Platform: LeetCode
    Link: https://leetcode.com/problems/majority-element-ii/
    Difficulty: Medium
    Approach: Extended Moore's Voting Algorithm — track two candidates and their counts, verify actual frequency in a second pass
    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> arr={3,3,2,2,3,2,1};
  int count1=0,count2=0;
  int n=arr.size();
  int element1,element2;
  vector<int> result;
 for(int x : arr){
  if(count1>0 && element1==x){
  count1++;
 }
 else if(count2>0 && element2==x){
count2++;
 }
 else if(count1==0){
  element1=x;
  count1=1;
 }
 else if(count2==0){
  element2=x;
  count2=1;
 }
 else{
  count1--;
  count2--;
 }
 }
count1=count2=0;
for(int x : arr){
  if(element1==x) count1++;
  if(element2==x) count2++;
}
if(count1>n/3) result.push_back(element1);
if(count2>n/3) result.push_back(element2);
for(int x : result){
  cout << x << " ";
}
}