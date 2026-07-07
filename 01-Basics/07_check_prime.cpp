/*
    Problem: check prime
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Loop till sqrt(n) — if no divisor found then Prime — O(√n)
    Time: O(sqrt(n))
    Space: O(1)
*/

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isprime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}

