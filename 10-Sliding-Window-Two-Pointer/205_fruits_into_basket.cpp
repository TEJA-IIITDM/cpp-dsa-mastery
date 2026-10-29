/*
    Problem: Fruit Into Baskets (LeetCode 904)
    Platform: LeetCode
    Link: https://leetcode.com/problems/fruit-into-baskets/
    Difficulty: Medium
    Approach: Non-shrinking Sliding Window with Hash Map — track at most 2 distinct fruit types
    Time: O(N)
    Space: O(1) auxiliary space (map size <= 3)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        unordered_map<int, int> basket;
        int maxfruits = 0;

        while (right < fruits.size()) {
            basket[fruits[right]]++;

            // Shift left forward by 1 if unique fruit types exceed 2
            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxfruits = max(maxfruits, right - left + 1);
            right++;
        }

        return maxfruits;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1, 2, 3, 2, 2};

    cout << "Maximum fruits collected: " << sol.totalFruit(fruits) << endl;
    // Output: 4 (collecting [2, 3, 2, 2])

    return 0;
}