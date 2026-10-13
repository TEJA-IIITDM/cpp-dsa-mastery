/*
    Problem: Fractional Knapsack
    Platform: Self Practice / GeeksforGeeks
    Link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
    Difficulty: Medium
    Approach: Greedy Strategy — sort items descending by value-to-weight ratio (v/w); greedily take whole items then fraction of last item
    Time: O(N log N)
    Space: O(1) auxiliary space
*/
#include <bits/stdc++.h>
using namespace std;

double fractionalknapsack(int n, int W, vector<vector<int>> items) {
    sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
        return (double)a[0] / a[1] > (double)b[0] / b[1];
    });

    int curr = 0;
    double value = 0;

    for (int i = 0; i < n; i++) {
        if(curr + items[i][1]<= W){
            curr+=items[i][1];
            value+=items[i][0];
        }
        else{
            int remain=W-curr;
            value+=(items[i][0]/(double)items[i][1])*remain;
            break;
        }
    }

    return value;
}

int main() {
    int n = 3, W = 50;
    vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}};
    double ans = fractionalknapsack(n, W, items);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}