/*
    Problem: Lemonade Change (LeetCode 860)
    Platform: LeetCode
    Link: https://leetcode.com/problems/lemonade-change/
    Difficulty: Easy
    Approach: Greedy Strategy — prioritize giving $10 + $5 over three $5s when making change for $20 to preserve $5 bills
    Time: O(N)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false; // Cannot make change
                five--;
                ten++;
            } else { // bill == 20
                // Greedy choice: prefer giving $10 + $5 over $5 + $5 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false; // Cannot make $15 change
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20};

    if (sol.lemonadeChange(bills)) {
        cout << "Successfully provided change for all customers!\n";
    } else {
        cout << "Failed to provide change.\n";
    }

    return 0;
}