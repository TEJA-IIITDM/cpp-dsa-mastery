/*
    Problem: Find How Many Times the Array Has Been Rotated
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Medium
    Approach: Modified Binary Search (same as Find Minimum in Rotated Sorted Array) — the index of the minimum element directly gives the RIGHT rotation count; for LEFT rotation count, use (n - index of minimum)
    Time: O(log n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int findRotationCount(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[high] < arr[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    int rightRotationCount = low;
    int leftRotationCount = arr.size() - low;

    return rightRotationCount; // change to leftRotationCount if problem asks for left rotations
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 6, 0, 1};
    cout << "Number of rotations: " << findRotationCount(arr) << endl;
    return 0;
}