#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both greed factors and cookie sizes
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Pointer for children (g)
        int j = 0; // Pointer for cookies (s)

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // Child satisfied, move to next child
            }
            j++; // Move to next cookie in either case
        }

        return i; // Number of content children
    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << "Content children: " << sol.findContentChildren(g, s) << "\n";
    // Output: 1

    return 0;
}