/*
    Problem: K-th Element of Two Sorted Arrays
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Hard
    Approach: Binary Search on Partition — same as Median of Two Sorted Arrays, but partition size is k (not necessarily half), binary search on smaller array
    Time: O(log(min(n,m)))
    Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        if (arr1.size() > arr2.size()) {
            return kthElement(arr2, arr1, k);
        }

        int n1 = arr1.size(), n2 = arr2.size();
        int low = max(0, k - n2), high = min(k, n1);

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return -1; // shouldn't reach here for valid input
    }
int main() {
   vector<int> arr1 = {2, 3, 6, 7, 9};
   vector<int> arr2 = {1, 4, 8, 10};
   int k = 5;
   cout << "The " << k << "-th element is: " << kthElement(arr1, arr2, k) << endl;
   return 0;
}