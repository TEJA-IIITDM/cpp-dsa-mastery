/*
    Problem: GCD of Odd and Even Sums
    Platform: LeetCode
    Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums
    Difficulty: Easy
    Approach:  Mathematical simplification — GCD(n(n+1), n^2) = n * GCD(n+1,n) = n * 1 = n, since consecutive integers are always coprime
    Time: O(1)
    Time: O(1)
    Space: O(1)
*/

// Time Complexity: O(1)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

int gcd(int n) {
   return n;  //GCD of sum of first n evens and first n odds is always just n
}
int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "GCD of sums is: " << gcd(n) << endl;
}

