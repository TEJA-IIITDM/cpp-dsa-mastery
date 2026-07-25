/*
    Problem: Allocate Minimum Number of Pages
    Platform: self practice (GeeksforGeeks)
    Link: N/A
    Difficulty: Medium
    Approach: Binary Search on Answer — binary search over possible max pages per student, greedily count students needed, search left (smaller threshold) on success
    Time: O(n log(sum(books)))
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>& books, int mid, int students) {
    int count = 1;
    long long pages = 0;
    for (int i = 0; i < books.size(); i++) {
        if (pages + books[i] <= mid) {
            pages += books[i];
        } else {
            count++;
            pages = books[i];
        }
    }
    return count <= students;
}

int minimumpages(vector<int>& books, int students) {
    if (students > (int)books.size()) return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ispossible(books, mid, students)) {
            ans = mid;
            high = mid - 1;   
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {25, 46, 28, 49, 24};
    int students = 4;
    int result = minimumpages(books, students);
    cout << result;
}