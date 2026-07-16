/*
    Problem: 4Sum
    Platform: LeetCode
    Link: https://leetcode.com/problems/4sum/
    Difficulty: Medium
    Approach: Sort array, fix two elements (i, j) with duplicate skipping, use two-pointer on remaining part to find pairs summing to (target - arr[i] - arr[j]), skip duplicates
    Time: O(n^3)
    Space: O(1) extra (excluding output and sort's internal space)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> arr={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
  int target=9;
  sort(arr.begin(),arr.end());
  vector<vector<int>> result;
  for(int i=0;i<arr.size();i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    for(int j=i+1;j<arr.size();j++){
      if(j>i+1 && arr[j]==arr[j-1]) continue;
      int left=j+1,right=arr.size()-1;
    while(left<right){
     long long sum=(long long)arr[i]+arr[j]+arr[left]+arr[right];
      if(sum==target){
        result.push_back({arr[i],arr[j],arr[left],arr[right]});
        while(left<right && arr[left]==arr[left+1]) left++;
        while(left<right && arr[right]==arr[right-1]) right--;
        left++;
        right--;
      }
      else if(sum<target) left++;
      else right--;
    }
  }
    }
  for (auto& triplet : result) {
        cout << "{ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

}