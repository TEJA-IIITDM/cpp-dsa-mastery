/*
    Problem: Largest Odd Number in String
    Platform: LeetCode
    Link: https://leetcode.com/problems/largest-odd-number-in-string/
    Difficulty: Easy
    Approach: Scan from the right, find the first (last, positionally) odd digit, return substring from start up to and including that digit; return "" if none found
    Time: O(n)
    Space: O(n) for output
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "4562346762";
    int length = s.length();
    int lastOddIndex = -1;

    for (int i = length - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 != 0) {
            lastOddIndex = i;
            break;
        }
    }

    string result = (lastOddIndex == -1) ? "" : s.substr(0, lastOddIndex + 1);

    cout << result << endl;
}