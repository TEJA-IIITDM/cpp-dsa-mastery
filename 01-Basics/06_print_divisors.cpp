/*
    Problem: print all divisors
    Platform: self pratice
    Link: N/A
    Difficulty: easy
    Approach: Divisor Pairs + Loop till sqrt(n) — O(√n)
    Time: O(sqrt(n))
    Space: O(1)
*/

// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

void printdivisors(int n) {
    for(int i = 1; i*i <= n; i++) { 
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i) {
                cout << n / i << " ";
            }
        }
    }
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printdivisors(n);
}

