/*
    Problem: Longest Substring with At Most K Distinct Characters (LeetCode 340 / GFG)
    Platform: LeetCode / Self Practice
    Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
    Difficulty: Medium
    Approach: Sliding Window with Hash Map — track at most K distinct character frequencies
    Time: O(N)
    Space: O(K) auxiliary space
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int left = 0, right = 0;
        int maxlen = 0;
        unordered_map<char, int> mp;

        while (right < s.size()) {
            mp[s[right]]++;

            // Shrink window if unique characters exceed k
            while (mp.size() > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
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
    string s = "eceba";
    int k = 2;

    cout << "Longest substring with at most " << k << " distinct characters: " << sol.kDistinctChar(s, k) << endl;
    // Output: 3 ("ece")

    return 0;
}