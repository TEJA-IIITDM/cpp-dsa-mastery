/*
    Problem: Maximum Points You Can Obtain from Cards (LeetCode 1423)
    Platform: Self Practice / LeetCode
    Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
    Difficulty: Medium
    Approach: Sliding Window / Prefix-Suffix Swap — start with k left elements and swap one by one with right elements
    Time: O(K)
    Space: O(1) auxiliary space
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;

        // 1. Take initial k cards from the left
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int maxPoints = leftSum;
        int rightIndex = n - 1;

        // 2. Gradually replace left cards with right cards
        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;

            maxPoints = max(maxPoints, leftSum + rightSum);
        }

        return maxPoints;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << "Maximum points: " << sol.maxScore(cardPoints, k) << endl;
    // Output: 12 (5 + 6 + 1)

    return 0;
}