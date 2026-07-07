/*
    Problem: GCD of Odd and Even Sums
    Platform: LeetCode
    Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums
    Difficulty: Easy
    Approach: Arithmetic Series Formula + Euclidean GCD — O(1) Time
    Time: O(1)
    Space: O(1)
*/

// Time Complexity: O(1)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int gcd(int n) {
    int sumeven, sumodd;
    sumeven=n*(n+1);
    sumodd=n*n;
    
    return __gcd(sumeven, sumodd);
}   

int __gcd(int a, int b) {
    if (b == 0)
        return a;
    return __gcd(b, a % b);
}


int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "GCD of sums is: " << gcd(n) << endl;
}

