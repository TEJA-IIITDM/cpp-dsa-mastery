/*
    Problem: 3Sum
    Platform: LeetCode
    Link: https://leetcode.com/problems/3sum/
    Difficulty: Medium
    Approach: Sort array, fix one element (only while nums[i]<=0, since sorted array means positives can't sum to 0), use two-pointer to find pairs summing to its negative, skip duplicates
    Time: O(n^2)
    Space: O(1) extra (excluding output and sort's internal space)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> arr={-1,0,1,2,-1,-4};
  sort(arr.begin(),arr.end());
  vector<vector<int>> result;
  int sum;
  for(int i=0;i<arr.size() && arr[i]<=0;i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    int left=i+1,right=arr.size()-1;
    while(left<right){
      sum=arr[i]+arr[left]+arr[right];
      if(sum==0){
        result.push_back({arr[i],arr[left],arr[right]});
        while(left<right && arr[left]==arr[left+1]) left++;
        while(left<right && arr[right]==arr[right-1]) right--;
        left++;
        right--;
      }
      else if(sum<0) left++;
      else right--;
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