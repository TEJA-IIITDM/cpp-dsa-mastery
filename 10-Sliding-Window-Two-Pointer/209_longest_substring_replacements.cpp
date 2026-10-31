/*
    Problem: Longest Repeating Character Replacement (LeetCode 424)
    Platform: LeetCode
    Link: https://leetcode.com/problems/longest-repeating-character-replacement/
    Difficulty: Medium
    Approach: Sliding Window — maintain maxfreq of any single character and shrink window when (length - maxfreq) > k
    Time: O(N)
    Space: O(1) auxiliary space (size 26 frequency vector)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int maxlen = 0, maxfreq = 0;
        vector<int> freq(26, 0);

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            // If replacements required exceed k, shift left pointer forward by 1 step
            if ((right - left + 1) - maxfreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
            right++;
        }

        return maxlen;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;

    cout << "Longest repeating character replacement length: " << sol.characterReplacement(s, k) << endl;
    // Output: 4 ("AABA" or "ABBB")

    return 0;
}