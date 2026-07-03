// Time Complexity: O(n)
// Space Complexity: O(1) 
#include<bits/stdc++.h>
using namespace std;
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << fib(i) << " ";
    }
    return 0;
}