/*
    Problem: Binary Subarrays With Sum (LeetCode 930)
    Platform: LeetCode
    Link: https://leetcode.com/problems/binary-subarrays-with-sum/
    Difficulty: Medium
    Approach: Sliding Window Transformation — Exactly(Goal) = AtMost(Goal) - AtMost(Goal - 1)
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to count subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        int left = 0;
        int count = 0;
        int sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1); // Number of valid subarrays ending at 'right'
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Exactly(goal) = AtMost(goal) - AtMost(goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Subarrays with sum equal to " << goal << ": " << sol.numSubarraysWithSum(nums, goal) << endl;
    // Output: 4

    return 0;
}