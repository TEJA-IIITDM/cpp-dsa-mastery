/*
    Problem: Count Reverse Pairs
    Platform: LeetCode
    Link: https://leetcode.com/problems/reverse-pairs/
    Difficulty: Hard
    Approach: Modified Merge Sort — before merging, count pairs where arr[i] > 2*arr[j] using a monotonically advancing pointer (reset before merge phase), then perform standard merge
    Time: O(n log n)
    Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    long long count = 0;
    for(int i=left;i<=mid;i++){
        while(right<=high && arr[i]>(long long)2*arr[right]){
            right++;
        }
        count+=(right-(mid+1));
    }
    right=mid+1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } 
        else {
            temp.push_back(arr[right]);
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
    vector<int> arr = {1,3,2,3,1};
    int n = arr.size();
    long long totalInversions = mergeSortAndCount(arr, 0, n - 1);
    cout << "Total inversions: " << totalInversions << endl;
    return 0;
}