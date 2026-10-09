/*
    Problem: Single Number II (LeetCode 137)
    Platform: LeetCode
    Link: https://leetcode.com/problems/single-number-ii/
    Difficulty: Medium
    Approach: Bit Counting (Modulo 3) — sum bits at position i across all numbers; set bit i in result if count % 3 != 0
    Time: O(32 * N) = O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // Iterate through all 32 bits of a standard integer
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            // Count how many numbers have the bit set at position 'bit'
            for (int num : nums) {
                if ((num >> bit) & 1) {
                    count++;
                }
            }

            // If count is not divisible by 3, the unique element has a 1 here
            if (count % 3 != 0) {
                result |= (1U << bit); // 1U prevents signed shift overflow
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << "Single number: " << sol.singleNumber(nums) << "\n"; // Output: 3

    return 0;
}