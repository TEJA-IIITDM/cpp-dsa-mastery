#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:
    pair<int, int> JobScheduling(vector<Job>& arr) {
        int n = arr.size();

        // 1. Sort jobs in descending order of profit
        sort(arr.begin(), arr.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        // 2. Find maximum deadline to size slot array
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // slots[j] stores -1 if slot j is free
        vector<int> slots(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        // 3. Greedily place each job in the latest available slot <= deadline
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) { // Search backwards from deadline
                if (slots[j] == -1) {
                    slots[j] = arr[i].id; // Occupy slot j
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break; // Job scheduled, move to next job
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

int main() {
    Solution sol;
    vector<Job> arr = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    pair<int, int> ans = sol.JobScheduling(arr);
    cout << "Jobs done: " << ans.first << ", Total profit: " << ans.second << endl;
    // Output: Jobs done: 2, Total profit: 60

    return 0;
}