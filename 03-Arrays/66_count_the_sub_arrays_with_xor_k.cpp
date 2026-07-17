/*
    Problem: Count the Number of Subarrays with Given XOR K
    Platform: self practice
    Link: N/A
    Difficulty: Medium
    Approach: Prefix XOR + Hash Map — track frequency of each prefix XOR seen so far, check if (currentXOR ^ k) has occurred before, add its frequency to count
    Time: O(n)
    Space: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
  vector<int> arr={4, 2, 2, 6, 4};
  unordered_map<int,int> mp;
  int xorr=0,k=6;
  mp[xorr]++;
  int count=0;
  for(int i=0;i<arr.size();i++){
   xorr^=arr[i];
   int x=xorr^k;
   count+=mp[x];
   mp[xorr]++;
  }
  cout << count;
}