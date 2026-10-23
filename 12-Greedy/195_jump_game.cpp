/*
    Problem: Jump Game I (LeetCode 55)
    Platform: LeetCode
    Link: https://leetcode.com/problems/jump-game/
    Difficulty: Medium
    Approach: Greedy Choice — maintain maxReach variable tracking the furthest index accessible from index 0
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // If current index is beyond our max reachability, we are stuck
            if (i > maxReach) return false;

            // Update the furthest reachable index
            maxReach = max(maxReach, i + nums[i]);

            // Early return if we can already reach the last index
            if (maxReach >= n - 1) return true;
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "nums1 Can Reach: " << (sol.canJump(nums1) ? "true" : "false") << "\n"; // Output: true
    cout << "nums2 Can Reach: " << (sol.canJump(nums2) ? "true" : "false") << "\n"; // Output: false

    return 0;
}