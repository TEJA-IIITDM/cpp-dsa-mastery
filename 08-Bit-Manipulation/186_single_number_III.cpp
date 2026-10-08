/*
    Problem: Single Number III (LeetCode 260)
    Platform: LeetCode
    Link: https://leetcode.com/problems/single-number-iii/
    Difficulty: Medium
    Approach: Bit Manipulation / Bitmasking — XOR all elements to find A ^ B, extract rightmost set bit (xor & -xor) to partition array into two buckets
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

      
        long long diffBit = xorSum & (-xorSum);

      
        int num1 = 0;
        int num2 = 0;

        for (int num : nums) {
            if ((num & diffBit) != 0) {
                num1 ^= num; 
            } else {
                num2 ^= num; 
            }
        }

        return {num1, num2};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> result = sol.singleNumber(nums);

    cout << "The two single numbers are: " << result[0] << " and " << result[1] << "\n";

    return 0;
}