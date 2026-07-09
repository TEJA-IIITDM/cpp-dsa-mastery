/*
    Problem: Union of Two Unsorted Arrays
    Platform: self practice
    Link: N/A
    Difficulty: Easy
    Approach: Set — insert all elements from both arrays, set auto-handles duplicates and sorting
    Time: O((n+m) log(n+m))
    Space: O(n+m)
*/
// IF TWO ARRAYS ARE NOT SORTED USE SET,MAP<INT,BOOL> FOR SORTED OUTPUT AND FOR UNSORTED OUTPUT USE UNORDERED SET,UNORDERED MAP<INT,BOOL>
#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int>& arr1, vector<int>& arr2) {
    set<int> s;

    for (int x : arr1) s.insert(x);
    for (int x : arr2) s.insert(x);

    vector<int> unionArr(s.begin(), s.end());
    return unionArr;
}

int main() {
    vector<int> arr1 = {4, 1, 2, 2, 3};
    vector<int> arr2 = {6, 3, 2, 5};

    vector<int> result = findUnion(arr1, arr2);

    cout << "Union: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

