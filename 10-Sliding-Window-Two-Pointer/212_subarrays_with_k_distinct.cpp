/*
    Problem: Subarrays with K Distinct Integers - Single Pass Optimization (LeetCode 992)
    Platform: LeetCode
    Link: https://leetcode.com/problems/subarrays-with-k-distinct-integers/
    Difficulty: Hard
    Approach: Dual Left-Pointer Single Pass — maintain left1 (at most K) and left2 (at most K-1) simultaneously
    Time: O(N)
    Space: O(K) auxiliary space (two frequency maps)
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int left1 = 0, left2 = 0;
        int count = 0;

        unordered_map<int, int> freq1; // Frequency map for window ending at left1 (at most K)
        unordered_map<int, int> freq2; // Frequency map for window ending at left2 (at most K - 1)

        for (int right = 0; right < n; right++) {
            freq1[nums[right]]++;
            freq2[nums[right]]++;

            // Shrink window 1 so it contains at most K distinct elements
            while (freq1.size() > k) {
                freq1[nums[left1]]--;
                if (freq1[nums[left1]] == 0) {
                    freq1.erase(nums[left1]);
                }
                left1++;
            }

            // Shrink window 2 so it contains at most K - 1 distinct elements
            while (freq2.size() > k - 1) {
                freq2[nums[left2]]--;
                if (freq2[nums[left2]] == 0) {
                    freq2.erase(nums[left2]);
                }
                left2++;
            }

            // Valid starting indices for exactly K distinct elements are in [left1, left2 - 1]
            count += (left2 - left1);
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << "Subarrays with exactly " << k << " distinct integers (Single Pass): " 
         << sol.subarraysWithKDistinct(nums, k) << endl;
    // Output: 7

    return 0;
}