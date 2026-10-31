/*
    Problem: Count Number of Nice Subarrays (LeetCode 1248)
    Platform: LeetCode
    Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
    Difficulty: Medium
    Approach: Sliding Window Transformation — Exactly(K) = AtMost(K) - AtMost(K - 1) with odd parity tracking
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int left = 0, right = 0;
        int result = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 != 0) {
                k--;
            }
            while (k < 0) {
                if (nums[left] % 2 != 0) {
                    k++;
                }
                left++;
            }
            result += (right - left + 1);
            right++; // FIXED: Increment right pointer
        }
        return result;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // Exactly(K) = AtMost(K) - AtMost(K - 1)
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Subarrays with exactly " << k << " odd numbers: " << sol.numberOfSubarrays(nums, k) << endl;
    // Output: 2 ([1,1,2,1] and [1,2,1,1])

    return 0;
}