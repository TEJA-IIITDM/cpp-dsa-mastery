/*
    Problem: Valid Parenthesis String (LeetCode 678)
    Platform: LeetCode
    Link: https://leetcode.com/problems/valid-parenthesis-string/
    Difficulty: Medium
    Approach: Greedy / Range Tracking — maintain [minOpen, maxOpen] bounds for possible unmatched open brackets '('
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum possible open brackets
        int maxOpen = 0; // Maximum possible open brackets

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat '*' as ')'
                maxOpen++; // Treat '*' as '('
            }

            // If maxOpen is negative, we have unmatched closing brackets
            if (maxOpen < 0) return false;

            // minOpen cannot drop below 0 (we can't have negative unmatched open brackets)
            if (minOpen < 0) minOpen = 0;
        }

        // If 0 is within the possible range [minOpen, maxOpen], string is valid
        return minOpen == 0;
    }
};

int main() {
    Solution sol;
    string s = "(*))";

    if (sol.checkValidString(s)) {
        cout << "\"" << s << "\" is a Valid Parenthesis String\n";
    } else {
        cout << "\"" << s << "\" is NOT valid\n";
    }

    return 0;
}