/*
    Problem: Intersection of Two Arrays
    Platform: LeetCode
    Link: https://leetcode.com/problems/intersection-of-two-arrays/
    Difficulty: Easy
    Approach: Hash Set — store nums1 in a set, scan nums2 checking membership, track added elements to avoid duplicates in result
    Time: O(n + m) average
    Space: O(n + m)
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int x : nums2) {
            if (s.count(x)) {
                result.insert(x);
            }
        }

        return vector<int> (result.begin(),result.end());
    }
int main(){
    vector<int> arr1={1,2,2,1};
    vector<int> arr2={2,2};
    vector<int> result=intersection(arr1,arr2);
    for(int x : result){
        cout << x << " ";
    }
}