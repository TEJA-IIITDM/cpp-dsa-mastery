/*
    Problem: reverse string characeters array
    Platform: LeetCode
    Link: https://leetcode.com/problems/reverse-string/
    Difficulty: easy
    Approach: Two Pointer — swap characters from both ends moving inward
    Time: O(n)
    Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void reversearray(vector<string>&arr) {
    int start = 0;
    int end = arr.size() - 1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int main() {
    vector<string> arr = {"h","e","l","l","o"};
    reversearray(arr);
    for(const string x : arr) {
        cout << x << " ";
    }
    return 0;
}

