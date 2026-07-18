/*
    Problem: Count Inversions in an Array
    Platform: self practice
    Link: N/A
    Difficulty: Medium
    Approach: Modified Merge Sort — count inversions during the merge step; when an element from the right half is taken before the left half is exhausted, it is inverted with all remaining left-half elements
    Time: O(n log n)
    Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    long long count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {
    long long count = 0;
    if (low >= high) return count;

    int mid = (low + high) / 2;

    count += mergeSortAndCount(arr, low, mid);
    count += mergeSortAndCount(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    long long totalInversions = mergeSortAndCount(arr, 0, n - 1);

    cout << "Total inversions: " << totalInversions << endl;

    return 0;
}