/*
    Problem: Longest Substring Without Repeating Characters (LeetCode 3)
    Platform: LeetCode
    Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
    Difficulty: Medium
    Approach: Sliding Window with Hash Array Indexing — track last seen character index to jump left pointer in O(1)
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int hash[256];
        int len = 0;

        // Initialize hash array with -1 (character not seen yet)
        for (int i = 0; i < 256; i++) hash[i] = -1;

        while (right < s.size()) {
            // If character was seen before, jump left pointer to right of previous occurrence
            if (hash[s[right]] != -1) {
                left = max(left, hash[s[right]] + 1);
            }

            // Record/update last seen index of current character
            hash[s[right]] = right;

            // Calculate current window length
            len = max(len, right - left + 1);

            right++;
        }

        return len;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";

    cout << "Length of longest non-repeating substring: " << sol.lengthOfLongestSubstring(s) << "\n";
    // Output: 3 ("abc")

    return 0;
}