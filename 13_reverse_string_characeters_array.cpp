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